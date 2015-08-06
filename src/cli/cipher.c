/*
 *   Copyright (c) 2014, Andrew Romanenko <melanhit@gmail.com>
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of the project nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 *   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#ifdef HAVE_ERROR_H
#include <error.h>
#else
#ifdef HAVE_ERR_H
#include <err.h>
#endif
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <termios.h>

#include "../akmos.h"
#include "cli.h"
#include "secur.h"

#define DEFAULT_EALGO   AKMOS_ALGO_TWOFISH
#define DEFAULT_EMODE   AKMOS_MODE_CBC
#define DEFAULT_DALGO   AKMOS_ALGO_SHA2_512
#define DEFAULT_KEYLEN  128
#define DEFAULT_ITER    65536

#define MAX_KEYLEN      128
#define MAX_PASSLEN     128

#define BUFLEN          (BUFSIZ*2)

struct opt_cipher_s {
    int algo;
    int mode;
    size_t blklen;
    size_t keylen;
    uint32_t iter;
    char pass[MAX_PASSLEN];
    char *key;
    char *input;
    char *output;
    struct {
        char algo;
        char mode;
        char pass;
        char key;
        char keylen;
        char iter;
        char over;
    } set;
};

struct header_cipher_s {
    uint8_t *iv;
    uint8_t *key;
};

static int prompt_over(char *s, int flag)
{
    char ans;

    /* use flag for skip newline of printf, unclean but work :) */
    if(flag) {
        ans = getchar();

        if(ans == EOF)
            return 0;
    }

    printf("Overwrite %s? [Y/n] ", s);

    ans = getchar();
    if(ans == EOF)
        return 0;

    if(ans == 'y' || ans == 'Y' || ans == '\n')
        return 1;
    else
        return 0;
}

static int parse_arg(struct opt_cipher_s *opt, int argc, char **argv)
{
    char *algo_str, *mode_str, *keylen_str;
    int c, err;

    algo_str = mode_str = keylen_str = NULL;

    while((c = getopt(argc, argv, "a:m:l:pk:e:i:hy")) != -1) {
        switch(c) {
            case 'a':
                algo_str = optarg;
                opt->set.algo = c;
                break;

            case 'm':
                mode_str = optarg;
                opt->set.mode = c;
                break;

            case 'l':
                keylen_str = optarg;
                opt->set.keylen = c;
                break;

            case 'p':
                opt->set.pass = c;
                break;

            case 'k':
                opt->key = optarg;
                opt->set.key = c;
                break;

            case 'i':
                err = sscanf(optarg, "%u", &opt->iter);
                if(err == EOF || !err) {
                    printf("Invalid number iterations\n");
                    return EXIT_FAILURE;
                }

                opt->set.iter = c;
                break;

            case 'y':
                opt->set.over = c;
                break;

            case 'h':
            default:
                printf("Usage: akmos enc|dec [-a algo] [-m mode] [-k key] [-l keylen] [-p] [-i iter] [-y] [-h] <input> <output>\n");
                return EXIT_FAILURE;
        }
    }

    /* check input/output */
    if((argc - optind) != 2) {
        printf("Missing <input> or <output>\n");
        return EXIT_FAILURE;
    }

    opt->input = argv[optind];
    opt->output = argv[optind + 1];

    /* set algo */
    if(!opt->set.algo) {
        opt->algo = DEFAULT_EALGO;
    } else {
        if(algo_str) {
            opt->algo = akmos_str2algo(algo_str);
            if(opt->algo == -1)
                return akmos_perror(AKMOS_ERR_ALGOID);
        }
    }

    /* set mode */
    if(!opt->set.mode) {
        opt->mode = DEFAULT_EMODE;
    } else {
        if(mode_str) {
            opt->mode = akmos_str2mode(mode_str);
            if(opt->mode == -1)
                return akmos_perror(AKMOS_ERR_MODEID);
        }
    }

    if(!opt->set.key && !opt->set.pass)
        opt->set.pass = 'p';

    /* set keylen */
    if(!opt->set.keylen) {
        switch(opt->algo) {
            case AKMOS_ALGO_THREEFISH_256:
                opt->keylen = 256;
                break;

            case AKMOS_ALGO_THREEFISH_512:
                opt->keylen = 512;
                break;

            case AKMOS_ALGO_THREEFISH_1024:
                opt->keylen = 1024;
                break;

            default:
                opt->keylen = DEFAULT_KEYLEN;
                break;
       }
    } else {
        if(keylen_str) {
            err = sscanf(keylen_str, "%zd", &opt->keylen);
            if(err == EOF || !err)
                return akmos_perror(AKMOS_ERR_KEYLEN);
        }
    }

    if(opt->keylen > (MAX_KEYLEN*8) || opt->keylen <= 0) {
        printf("Invalid key length\n");
        return EXIT_FAILURE;
    }
    opt->keylen /= 8;

    if((opt->blklen = akmos_blklen(opt->algo)) == 0) {
        printf("Invalid algo\n");
        return EXIT_FAILURE;
    }

    /* read password */
    if(opt->set.pass) {
        err = secur_read_passw(opt->pass);
        if(err) {
            printf("Could not read password\n");
            return EXIT_FAILURE;
        }
    }

    if(opt->set.iter && opt->set.pass) {
        if(opt->iter > UINT32_MAX) {
            printf("Maximum number of iterations - %u\n", UINT32_MAX);
            return EXIT_FAILURE;
        }
    } else {
        opt->iter = DEFAULT_ITER;
    }

    return EXIT_SUCCESS;
}

static int lb_padbuf(akmos_cipher_ctx *ctx, uint8_t *buf, size_t *rlen, size_t blklen, const int enc)
{
    size_t len, tmplen;

    len = *rlen;

    if(enc == AKMOS_FORCE_ENCRYPT) {
        tmplen = (len / blklen) * blklen;
        akmos_padadd(buf + tmplen, len - tmplen, buf + tmplen, blklen);

        akmos_cipher_crypt(ctx, buf + tmplen, blklen, buf + tmplen);

        *rlen = tmplen + blklen;
    } else {
        if((len % blklen) != 0 || len < blklen) {
            printf("Input not multiple %zd\n", blklen);
            return EXIT_FAILURE;
        }

        tmplen = akmos_padrem(buf + (len - blklen), blklen);
        *rlen = len + tmplen - blklen;
    }

    return EXIT_SUCCESS;
}

int akmos_cli_cipher(int argc, char **argv, const int enc)
{
    akmos_cipher_ctx *ctx;
    struct opt_cipher_s opt;
    struct header_cipher_s header;
    struct stat sb;
    uint8_t *keybuf, *keypass;
    uint8_t *buf, *tbuf, *hbuf, *rbuf, *wbuf;
    size_t keylen, rlen, wlen, hlen, tmplen;
    mode_t mask;
    int fd_in, fd_out, err;

    ctx = NULL;
    keybuf = hbuf = buf = NULL;
    fd_in = fd_out = -1;
    err = EXIT_SUCCESS;

    memset(&opt, 0, sizeof(struct opt_cipher_s));
    err = parse_arg(&opt, argc, argv);
    if(err)
        return err;

    /* Setup master keys */
    keylen = opt.keylen * 2;
    AMALLOC(keybuf, keylen, err);
    if(err)
        return err;
    memset(keybuf, 0, keylen);

    keypass = keybuf + opt.keylen;
    tbuf = keypass;
    if(opt.set.pass) {
        err = akmos_kdf_pbkdf2(tbuf, opt.keylen, NULL, 0, opt.pass, opt.iter, DEFAULT_DALGO);
        if(err) {
            akmos_perror(err);
            goto out;
        }
    }

    if(opt.set.key) {
        /* keypass is used as salt */
        err = secur_mk_keyfile(opt.key, keybuf, opt.keylen, keypass, opt.keylen);
        if(err)
            goto out;
    } else {
        memcpy(keybuf, keypass, opt.keylen);
    }

    /* Open source and destination */
    fd_in = open(opt.input, O_RDONLY);
    if(fd_in == -1) {
        err = EXIT_FAILURE;
        printf("%s: %s\n", opt.input, strerror(errno));
        goto out;
    }

    mask = umask(0);
    umask(mask);

    /* skip fifo and device */
    if(stat(opt.output, &sb) == 0) {
        switch(sb.st_mode & S_IFMT) {
            case S_IFBLK:
            case S_IFCHR:
            case S_IFIFO:
                break;

            default:
                if(!opt.set.over) {
                    if(!prompt_over(opt.output, opt.set.pass)) {
                        err = EXIT_SUCCESS;
                        printf("Not overwriting - exiting\n");
                        goto out;
                    }
                }
        }
    }

    fd_out = open(opt.output, O_CREAT|O_WRONLY|O_TRUNC, 0666);
    if(fd_out == -1) {
        err = EXIT_FAILURE;
        printf("%s: %s\n", opt.output, strerror(errno));
        goto out;
    }

    /* Create and cook header */
    tmplen = opt.blklen + opt.keylen;
    hlen = tmplen + (tmplen % opt.blklen);

    AMALLOC(hbuf, (hlen*2) + opt.blklen, err);
    if(err)
        goto out;

    if(enc == AKMOS_FORCE_DECRYPT) {
        tbuf = hbuf;
        if(read(fd_in, hbuf, hlen) != hlen) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.input, strerror(errno));
            goto out;
        }
    } else {
        tbuf = hbuf + hlen;
        err = secur_rand_buf(hbuf, hlen);
        if(err)
            goto out;
    }

    err = akmos_cipher_ex(enc, opt.algo, opt.mode, keybuf, opt.keylen, NULL, hbuf, hlen, tbuf);
    if(err) {
        akmos_perror(err);
        goto out;
    }

    if(enc == AKMOS_FORCE_ENCRYPT) {
        if(write(fd_out, tbuf, hlen) != hlen) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.output, strerror(errno));
            goto out;
        }
    }

    header.iv = hbuf;
    header.key = hbuf + opt.blklen;

    /* noise */
    tmplen = ((uint32_t)header.iv[0] ^ (uint32_t)header.iv[1]) % opt.blklen;

    if(enc == AKMOS_FORCE_ENCRYPT) {
        err = secur_rand_buf(hbuf + (hlen * 2), tmplen);
        if(err)
            goto out;

        if(write(fd_out, hbuf + (hlen*2), tmplen) != tmplen) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.output, strerror(errno));
            goto out;
        }
    } else {
        if(read(fd_in, hbuf + (hlen*2), tmplen) != tmplen) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.input, strerror(errno));
            goto out;
        }
    }

    /* Create and init cipher contexts */
    err = akmos_cipher_init(&ctx, opt.algo, opt.mode, enc);
    if(err) {
        akmos_perror(err);
        goto out;
    }

    /* Setup cipher key and IV */
    err = akmos_cipher_setkey(ctx, header.key, opt.keylen);
    if(err) {
        akmos_perror(err);
        goto out;
    }

    if(opt.mode != AKMOS_MODE_ECB)
        akmos_cipher_setiv(ctx, header.iv);

    /* enc/dec input to output */
    AMALLOC(buf, BUFLEN + opt.blklen, err);
    if(err)
        goto out;
    memset(buf, 0, BUFLEN + opt.blklen);

    rbuf = buf;
    wbuf = buf + BUFSIZ;

    rlen = read(fd_in, rbuf, BUFSIZ);
    while(1) {
        wlen = read(fd_in, wbuf, BUFSIZ);
        if(rlen == -1 || wlen == -1) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.input, strerror(errno));
            goto out;
        }

        akmos_cipher_crypt(ctx, rbuf, rlen, rbuf);

        if(!wlen)
            break;

        if(write(fd_out, rbuf, rlen) != rlen) {
            err = EXIT_FAILURE;
            printf("%s: %s\n", opt.output, strerror(errno));
            goto out;
        }

        tbuf = rbuf; rbuf = wbuf; wbuf = tbuf;
        tmplen = rlen; rlen = wlen; wlen = tmplen;
    }

    switch(opt.mode) {
        case AKMOS_MODE_ECB:
        case AKMOS_MODE_CBC:
        case AKMOS_MODE_CFB:
            err = lb_padbuf(ctx, rbuf, &rlen, opt.blklen, enc);
            if(err)
                goto out;

            break;

        default:
            break;
    }

    if(write(fd_out, rbuf, rlen) != rlen) {
        err = EXIT_FAILURE;
        printf("%s: %s\n", opt.output, strerror(errno));
        goto out;
    }

out:
    if(fd_in > 0)
        close(fd_in);

    if(fd_out > 0)
        close(fd_out);

    if(keybuf) {
        akmos_memzero(keybuf, keylen);
        free(keybuf);
    }

    if(buf) {
        akmos_memzero(buf, BUFLEN + opt.blklen);
        free(buf);
    }

    if(hbuf) {
        akmos_memzero(hbuf, (hlen * 2) + opt.blklen);
        free(hbuf);
    }

    if(ctx)
        akmos_cipher_free(ctx);

    return err;
}
