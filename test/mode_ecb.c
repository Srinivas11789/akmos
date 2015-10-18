/*
 *   Copyright (c) 2015, Andrew Romanenko <melanhit@gmail.com>
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
#include <fcntl.h>
#include <errno.h>

#include <akmos.h>

#include "test.h"

static int ecb_crypt(test_ecb_t *ectx, akmos_algo_id algo, size_t keylen, size_t blklen, int *res)
{
    akmos_cipher_ctx *ctx;
    uint8_t buf[1024], *key, *ct;
    int err;
    size_t i, j;

    key = buf;
    ct = key + keylen;

    /* test encryption */
    err = akmos_cipher_ex(AKMOS_FORCE_ENCRYPT, algo, AKMOS_MODE_ECB, ectx->key, keylen, NULL, ectx->pt, blklen, ct);
    if(err)
        return akmos_perror(err);

    if(memcmp(ct, ectx->ct0, blklen) != 0) {
        *res = TEST_FAIL;
        return EXIT_SUCCESS;
    }

    memcpy(key, ectx->key, keylen);

    for(i = 0; i < TEST_CNT; i++) {
        err = akmos_cipher_init(&ctx, algo, AKMOS_MODE_ECB, AKMOS_FORCE_ENCRYPT);
        if(err)
            goto out;

        for(j = 0; j < keylen; j++)
            key[j] ^= ct[j % blklen];

        err = akmos_cipher_setkey(ctx, key, keylen);
        if(err)
            goto out;

        for(j = 0; j < TEST_CNT; j++)
            akmos_cipher_crypt(ctx, ct, blklen, ct);

        akmos_cipher_free(ctx);
    }

    if(memcmp(ct, ectx->ct1, blklen) != 0) {
        *res = TEST_FAIL;
        return EXIT_SUCCESS;
    }

    /* test decryption */
    for(i = 0; i < TEST_CNT; i++) {
        err = akmos_cipher_init(&ctx, algo, AKMOS_MODE_ECB, AKMOS_FORCE_DECRYPT);
        if(err)
            goto out;

        err = akmos_cipher_setkey(ctx, key, keylen);
        if(err)
            goto out;

        for(j = 0; j < TEST_CNT; j++)
            akmos_cipher_crypt(ctx, ct, blklen, ct);

        for(j = 0; j < keylen; j++)
            key[j] ^= ct[j % blklen];

        akmos_cipher_free(ctx);
    }

    if(memcmp(key, ectx->key, keylen) != 0) {
        *res = TEST_FAIL;
        return EXIT_SUCCESS;
    }

    err = akmos_cipher_ex(AKMOS_FORCE_DECRYPT, algo, AKMOS_MODE_ECB, key, keylen, NULL, ct, blklen, ct);
    if(err)
        return akmos_perror(err);

    if(memcmp(ct, ectx->pt, blklen) != 0) {
        *res = TEST_FAIL;
        return EXIT_SUCCESS;
    }

out:
    if(err) {
        akmos_cipher_free(ctx);
        return akmos_perror(err);
    }

    return EXIT_SUCCESS;
}

static int ecb_test(akmos_algo_id algo, size_t keylen, char *argv0, int *res)
{
    char path[512];
    uint8_t buf[BUFSIZ];
    size_t blklen;
    ssize_t len;
    int fd, err;

    test_ecb_t ectx;

    err = test_path_cipher(algo, AKMOS_MODE_ECB, keylen, argv0, path);
    if(err)
        return err;

    fd = open(path, O_RDONLY);
    if(fd == -1) {
        printf("%s: %s\n", path, strerror(errno));
        return EXIT_FAILURE;
    }

    len = read(fd, buf, BUFSIZ);
    if(len == -1) {
        printf("%s: %s\n", path, strerror(errno));
        return EXIT_FAILURE;
    }

    close(fd);

    if((!keylen) || ((keylen % 8) != 0)) {
        printf("Invalid keylen %zd\n", keylen);
        return EXIT_FAILURE;
    }

    keylen /= 8;
    blklen = akmos_blklen(algo);
    if(!blklen) {
        akmos_perror(AKMOS_ERR_ALGOID);
        return EXIT_FAILURE;
    }

    if(len != ((keylen + blklen * 3))) {
        printf("Invalid data in \"%s\"\n", path);
        return EXIT_FAILURE;
    }

    ectx.key = buf;
    ectx.pt  = buf + keylen;
    ectx.ct0 = ectx.pt + blklen;
    ectx.ct1 = ectx.ct0 + blklen;

    err = ecb_crypt(&ectx, algo, keylen, blklen, res);
    if(err)
        return err;

    return EXIT_SUCCESS;
}

int test_mode_ecb(akmos_algo_id algo, char *argv0)
{
    char pname[128];
    int err, res;
    size_t i, keylen;
    const akmos_cipher_xalgo_t *xalgo;

    xalgo = akmos_xalgo_cipher(algo);
    if(!xalgo)
        return akmos_perror(AKMOS_ERR_ALGOID);

    res = TEST_PASS;
    for(i = xalgo->keymin; i <= xalgo->keymax; i += xalgo->keystep) {
        err = ecb_test(algo, i*8, argv0, &res);
        if(err)
            return err;

        if(res == TEST_FAIL)
            break;
    }

    sprintf(pname, "%s-%s", akmos_mode2str(AKMOS_MODE_ECB), akmos_algo2str(algo));
    test_print(pname, res);
    test_total(res);

    return EXIT_SUCCESS;
}