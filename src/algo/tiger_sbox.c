/*
 *   Copyright (c) 2015-2016, Andrew Romanenko <melanhit@gmail.com>
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

#include <stdint.h>

const uint64_t akmos_tiger_sbox[4][256] = {
    {
        UINT64_C(0x02aab17cf7e90c5e), UINT64_C(0xac424b03e243a8ec),
        UINT64_C(0x72cd5be30dd5fcd3), UINT64_C(0x6d019b93f6f97f3a),
        UINT64_C(0xcd9978ffd21f9193), UINT64_C(0x7573a1c9708029e2),
        UINT64_C(0xb164326b922a83c3), UINT64_C(0x46883eee04915870),
        UINT64_C(0xeaace3057103ece6), UINT64_C(0xc54169b808a3535c),
        UINT64_C(0x4ce754918ddec47c), UINT64_C(0x0aa2f4dfdc0df40c),
        UINT64_C(0x10b76f18a74dbefa), UINT64_C(0xc6ccb6235ad1ab6a),
        UINT64_C(0x13726121572fe2ff), UINT64_C(0x1a488c6f199d921e),
        UINT64_C(0x4bc9f9f4da0007ca), UINT64_C(0x26f5e6f6e85241c7),
        UINT64_C(0x859079dbea5947b6), UINT64_C(0x4f1885c5c99e8c92),
        UINT64_C(0xd78e761ea96f864b), UINT64_C(0x8e36428c52b5c17d),
        UINT64_C(0x69cf6827373063c1), UINT64_C(0xb607c93d9bb4c56e),
        UINT64_C(0x7d820e760e76b5ea), UINT64_C(0x645c9cc6f07fdc42),
        UINT64_C(0xbf38a078243342e0), UINT64_C(0x5f6b343c9d2e7d04),
        UINT64_C(0xf2c28aeb600b0ec6), UINT64_C(0x6c0ed85f7254bcac),
        UINT64_C(0x71592281a4db4fe5), UINT64_C(0x1967fa69ce0fed9f),
        UINT64_C(0xfd5293f8b96545db), UINT64_C(0xc879e9d7f2a7600b),
        UINT64_C(0x860248920193194e), UINT64_C(0xa4f9533b2d9cc0b3),
        UINT64_C(0x9053836c15957613), UINT64_C(0xdb6dcf8afc357bf1),
        UINT64_C(0x18beea7a7a370f57), UINT64_C(0x037117ca50b99066),
        UINT64_C(0x6ab30a9774424a35), UINT64_C(0xf4e92f02e325249b),
        UINT64_C(0x7739db07061ccae1), UINT64_C(0xd8f3b49ceca42a05),
        UINT64_C(0xbd56be3f51382f73), UINT64_C(0x45faed5843b0bb28),
        UINT64_C(0x1c813d5c11bf1f83), UINT64_C(0x8af0e4b6d75fa169),
        UINT64_C(0x33ee18a487ad9999), UINT64_C(0x3c26e8eab1c94410),
        UINT64_C(0xb510102bc0a822f9), UINT64_C(0x141eef310ce6123b),
        UINT64_C(0xfc65b90059ddb154), UINT64_C(0xe0158640c5e0e607),
        UINT64_C(0x884e079826c3a3cf), UINT64_C(0x930d0d9523c535fd),
        UINT64_C(0x35638d754e9a2b00), UINT64_C(0x4085fccf40469dd5),
        UINT64_C(0xc4b17ad28be23a4c), UINT64_C(0xcab2f0fc6a3e6a2e),
        UINT64_C(0x2860971a6b943fcd), UINT64_C(0x3dde6ee212e30446),
        UINT64_C(0x6222f32ae01765ae), UINT64_C(0x5d550bb5478308fe),
        UINT64_C(0xa9efa98da0eda22a), UINT64_C(0xc351a71686c40da7),
        UINT64_C(0x1105586d9c867c84), UINT64_C(0xdcffee85fda22853),
        UINT64_C(0xccfbd0262c5eef76), UINT64_C(0xbaf294cb8990d201),
        UINT64_C(0xe69464f52afad975), UINT64_C(0x94b013afdf133e14),
        UINT64_C(0x06a7d1a32823c958), UINT64_C(0x6f95fe5130f61119),
        UINT64_C(0xd92ab34e462c06c0), UINT64_C(0xed7bde33887c71d2),
        UINT64_C(0x79746d6e6518393e), UINT64_C(0x5ba419385d713329),
        UINT64_C(0x7c1ba6b948a97564), UINT64_C(0x31987c197bfdac67),
        UINT64_C(0xde6c23c44b053d02), UINT64_C(0x581c49fed002d64d),
        UINT64_C(0xdd474d6338261571), UINT64_C(0xaa4546c3e473d062),
        UINT64_C(0x928fce349455f860), UINT64_C(0x48161bbacaab94d9),
        UINT64_C(0x63912430770e6f68), UINT64_C(0x6ec8a5e602c6641c),
        UINT64_C(0x87282515337ddd2b), UINT64_C(0x2cda6b42034b701b),
        UINT64_C(0xb03d37c181cb096d), UINT64_C(0xe108438266c71c6f),
        UINT64_C(0x2b3180c7eb51b255), UINT64_C(0xdf92b82f96c08bbc),
        UINT64_C(0x5c68c8c0a632f3ba), UINT64_C(0x5504cc861c3d0556),
        UINT64_C(0xabbfa4e55fb26b8f), UINT64_C(0x41848b0ab3baceb4),
        UINT64_C(0xb334a273aa445d32), UINT64_C(0xbca696f0a85ad881),
        UINT64_C(0x24f6ec65b528d56c), UINT64_C(0x0ce1512e90f4524a),
        UINT64_C(0x4e9dd79d5506d35a), UINT64_C(0x258905fac6ce9779),
        UINT64_C(0x2019295b3e109b33), UINT64_C(0xf8a9478b73a054cc),
        UINT64_C(0x2924f2f934417eb0), UINT64_C(0x3993357d536d1bc4),
        UINT64_C(0x38a81ac21db6ff8b), UINT64_C(0x47c4fbf17d6016bf),
        UINT64_C(0x1e0faadd7667e3f5), UINT64_C(0x7abcff62938beb96),
        UINT64_C(0xa78dad948fc179c9), UINT64_C(0x8f1f98b72911e50d),
        UINT64_C(0x61e48eae27121a91), UINT64_C(0x4d62f7ad31859808),
        UINT64_C(0xeceba345ef5ceaeb), UINT64_C(0xf5ceb25ebc9684ce),
        UINT64_C(0xf633e20cb7f76221), UINT64_C(0xa32cdf06ab8293e4),
        UINT64_C(0x985a202ca5ee2ca4), UINT64_C(0xcf0b8447cc8a8fb1),
        UINT64_C(0x9f765244979859a3), UINT64_C(0xa8d516b1a1240017),
        UINT64_C(0x0bd7ba3ebb5dc726), UINT64_C(0xe54bca55b86adb39),
        UINT64_C(0x1d7a3afd6c478063), UINT64_C(0x519ec608e7669edd),
        UINT64_C(0x0e5715a2d149aa23), UINT64_C(0x177d4571848ff194),
        UINT64_C(0xeeb55f3241014c22), UINT64_C(0x0f5e5ca13a6e2ec2),
        UINT64_C(0x8029927b75f5c361), UINT64_C(0xad139fabc3d6e436),
        UINT64_C(0x0d5df1a94ccf402f), UINT64_C(0x3e8bd948bea5dfc8),
        UINT64_C(0xa5a0d357bd3ff77e), UINT64_C(0xa2d12e251f74f645),
        UINT64_C(0x66fd9e525e81a082), UINT64_C(0x2e0c90ce7f687a49),
        UINT64_C(0xc2e8bcbeba973bc5), UINT64_C(0x000001bce509745f),
        UINT64_C(0x423777bbe6dab3d6), UINT64_C(0xd1661c7eaef06eb5),
        UINT64_C(0xa1781f354daacfd8), UINT64_C(0x2d11284a2b16affc),
        UINT64_C(0xf1fc4f67fa891d1f), UINT64_C(0x73ecc25dcb920ada),
        UINT64_C(0xae610c22c2a12651), UINT64_C(0x96e0a810d356b78a),
        UINT64_C(0x5a9a381f2fe7870f), UINT64_C(0xd5ad62ede94e5530),
        UINT64_C(0xd225e5e8368d1427), UINT64_C(0x65977b70c7af4631),
        UINT64_C(0x99f889b2de39d74f), UINT64_C(0x233f30bf54e1d143),
        UINT64_C(0x9a9675d3d9a63c97), UINT64_C(0x5470554ff334f9a8),
        UINT64_C(0x166acb744a4f5688), UINT64_C(0x70c74caab2e4aead),
        UINT64_C(0xf0d091646f294d12), UINT64_C(0x57b82a89684031d1),
        UINT64_C(0xefd95a5a61be0b6b), UINT64_C(0x2fbd12e969f2f29a),
        UINT64_C(0x9bd37013feff9fe8), UINT64_C(0x3f9b0404d6085a06),
        UINT64_C(0x4940c1f3166cfe15), UINT64_C(0x09542c4dcdf3defb),
        UINT64_C(0xb4c5218385cd5ce3), UINT64_C(0xc935b7dc4462a641),
        UINT64_C(0x3417f8a68ed3b63f), UINT64_C(0xb80959295b215b40),
        UINT64_C(0xf99cdaef3b8c8572), UINT64_C(0x018c0614f8fcb95d),
        UINT64_C(0x1b14accd1a3acdf3), UINT64_C(0x84d471f200bb732d),
        UINT64_C(0xc1a3110e95e8da16), UINT64_C(0x430a7220bf1a82b8),
        UINT64_C(0xb77e090d39df210e), UINT64_C(0x5ef4bd9f3cd05e9d),
        UINT64_C(0x9d4ff6da7e57a444), UINT64_C(0xda1d60e183d4a5f8),
        UINT64_C(0xb287c38417998e47), UINT64_C(0xfe3edc121bb31886),
        UINT64_C(0xc7fe3ccc980ccbef), UINT64_C(0xe46fb590189bfd03),
        UINT64_C(0x3732fd469a4c57dc), UINT64_C(0x7ef700a07cf1ad65),
        UINT64_C(0x59c64468a31d8859), UINT64_C(0x762fb0b4d45b61f6),
        UINT64_C(0x155baed099047718), UINT64_C(0x68755e4c3d50baa6),
        UINT64_C(0xe9214e7f22d8b4df), UINT64_C(0x2addbf532eac95f4),
        UINT64_C(0x32ae3909b4bd0109), UINT64_C(0x834df537b08e3450),
        UINT64_C(0xfa209da84220728d), UINT64_C(0x9e691d9b9efe23f7),
        UINT64_C(0x0446d288c4ae8d7f), UINT64_C(0x7b4cc524e169785b),
        UINT64_C(0x21d87f0135ca1385), UINT64_C(0xcebb400f137b8aa5),
        UINT64_C(0x272e2b66580796be), UINT64_C(0x3612264125c2b0de),
        UINT64_C(0x057702bdad1efbb2), UINT64_C(0xd4babb8eacf84be9),
        UINT64_C(0x91583139641bc67b), UINT64_C(0x8bdc2de08036e024),
        UINT64_C(0x603c8156f49f68ed), UINT64_C(0xf7d236f7dbef5111),
        UINT64_C(0x9727c4598ad21e80), UINT64_C(0xa08a0896670a5fd7),
        UINT64_C(0xcb4a8f4309eba9cb), UINT64_C(0x81af564b0f7036a1),
        UINT64_C(0xc0b99aa778199abd), UINT64_C(0x959f1ec83fc8e952),
        UINT64_C(0x8c505077794a81b9), UINT64_C(0x3acaaf8f056338f0),
        UINT64_C(0x07b43f50627a6778), UINT64_C(0x4a44ab49f5eccc77),
        UINT64_C(0x3bc3d6e4b679ee98), UINT64_C(0x9cc0d4d1cf14108c),
        UINT64_C(0x4406c00b206bc8a0), UINT64_C(0x82a18854c8d72d89),
        UINT64_C(0x67e366b35c3c432c), UINT64_C(0xb923dd61102b37f2),
        UINT64_C(0x56ab2779d884271d), UINT64_C(0xbe83e1b0ff1525af),
        UINT64_C(0xfb7c65d4217e49a9), UINT64_C(0x6bdbe0e76d48e7d4),
        UINT64_C(0x08df828745d9179e), UINT64_C(0x22ea6a9add53bd34),
        UINT64_C(0xe36e141c5622200a), UINT64_C(0x7f805d1b8cb750ee),
        UINT64_C(0xafe5c7a59f58e837), UINT64_C(0xe27f996a4fb1c23c),
        UINT64_C(0xd3867dfb0775f0d0), UINT64_C(0xd0e673de6e88891a),
        UINT64_C(0x123aeb9eafb86c25), UINT64_C(0x30f1d5d5c145b895),
        UINT64_C(0xbb434a2dee7269e7), UINT64_C(0x78cb67ecf931fa38),
        UINT64_C(0xf33b0372323bbf9c), UINT64_C(0x52d66336fb279c74),
        UINT64_C(0x505f33ac0afb4eaa), UINT64_C(0xe8a5cd99a2cce187),
        UINT64_C(0x534974801e2d30bb), UINT64_C(0x8d2d5711d5876d90),
        UINT64_C(0x1f1a412891bc038e), UINT64_C(0xd6e2e71d82e56648),
        UINT64_C(0x74036c3a497732b7), UINT64_C(0x89b67ed96361f5ab),
        UINT64_C(0xffed95d8f1ea02a2), UINT64_C(0xe72b3bd61464d43d),
        UINT64_C(0xa6300f170bdc4820), UINT64_C(0xebc18760ed78a77a)
    },
    {
        UINT64_C(0xe6a6be5a05a12138), UINT64_C(0xb5a122a5b4f87c98),
        UINT64_C(0x563c6089140b6990), UINT64_C(0x4c46cb2e391f5dd5),
        UINT64_C(0xd932addbc9b79434), UINT64_C(0x08ea70e42015aff5),
        UINT64_C(0xd765a6673e478cf1), UINT64_C(0xc4fb757eab278d99),
        UINT64_C(0xdf11c6862d6e0692), UINT64_C(0xddeb84f10d7f3b16),
        UINT64_C(0x6f2ef604a665ea04), UINT64_C(0x4a8e0f0ff0e0dfb3),
        UINT64_C(0xa5edeef83dbcba51), UINT64_C(0xfc4f0a2a0ea4371e),
        UINT64_C(0xe83e1da85cb38429), UINT64_C(0xdc8ff882ba1b1ce2),
        UINT64_C(0xcd45505e8353e80d), UINT64_C(0x18d19a00d4db0717),
        UINT64_C(0x34a0cfeda5f38101), UINT64_C(0x0be77e518887caf2),
        UINT64_C(0x1e341438b3c45136), UINT64_C(0xe05797f49089ccf9),
        UINT64_C(0xffd23f9df2591d14), UINT64_C(0x543dda228595c5cd),
        UINT64_C(0x661f81fd99052a33), UINT64_C(0x8736e641db0f7b76),
        UINT64_C(0x15227725418e5307), UINT64_C(0xe25f7f46162eb2fa),
        UINT64_C(0x48a8b2126c13d9fe), UINT64_C(0xafdc541792e76eea),
        UINT64_C(0x03d912bfc6d1898f), UINT64_C(0x31b1aafa1b83f51b),
        UINT64_C(0xf1ac2796e42ab7d9), UINT64_C(0x40a3a7d7fcd2ebac),
        UINT64_C(0x1056136d0afbbcc5), UINT64_C(0x7889e1dd9a6d0c85),
        UINT64_C(0xd33525782a7974aa), UINT64_C(0xa7e25d09078ac09b),
        UINT64_C(0xbd4138b3eac6edd0), UINT64_C(0x920abfbe71eb9e70),
        UINT64_C(0xa2a5d0f54fc2625c), UINT64_C(0xc054e36b0b1290a3),
        UINT64_C(0xf6dd59ff62fe932b), UINT64_C(0x3537354511a8ac7d),
        UINT64_C(0xca845e9172fadcd4), UINT64_C(0x84f82b60329d20dc),
        UINT64_C(0x79c62ce1cd672f18), UINT64_C(0x8b09a2add124642c),
        UINT64_C(0xd0c1e96a19d9e726), UINT64_C(0x5a786a9b4ba9500c),
        UINT64_C(0x0e020336634c43f3), UINT64_C(0xc17b474aeb66d822),
        UINT64_C(0x6a731ae3ec9baac2), UINT64_C(0x8226667ae0840258),
        UINT64_C(0x67d4567691caeca5), UINT64_C(0x1d94155c4875adb5),
        UINT64_C(0x6d00fd985b813fdf), UINT64_C(0x51286efcb774cd06),
        UINT64_C(0x5e8834471fa744af), UINT64_C(0xf72ca0aee761ae2e),
        UINT64_C(0xbe40e4cdaee8e09a), UINT64_C(0xe9970bbb5118f665),
        UINT64_C(0x726e4beb33df1964), UINT64_C(0x703b000729199762),
        UINT64_C(0x4631d816f5ef30a7), UINT64_C(0xb880b5b51504a6be),
        UINT64_C(0x641793c37ed84b6c), UINT64_C(0x7b21ed77f6e97d96),
        UINT64_C(0x776306312ef96b73), UINT64_C(0xae528948e86ff3f4),
        UINT64_C(0x53dbd7f286a3f8f8), UINT64_C(0x16cadce74cfc1063),
        UINT64_C(0x005c19bdfa52c6dd), UINT64_C(0x68868f5d64d46ad3),
        UINT64_C(0x3a9d512ccf1e186a), UINT64_C(0x367e62c2385660ae),
        UINT64_C(0xe359e7ea77dcb1d7), UINT64_C(0x526c0773749abe6e),
        UINT64_C(0x735ae5f9d09f734b), UINT64_C(0x493fc7cc8a558ba8),
        UINT64_C(0xb0b9c1533041ab45), UINT64_C(0x321958ba470a59bd),
        UINT64_C(0x852db00b5f46c393), UINT64_C(0x91209b2bd336b0e5),
        UINT64_C(0x6e604f7d659ef19f), UINT64_C(0xb99a8ae2782ccb24),
        UINT64_C(0xccf52ab6c814c4c7), UINT64_C(0x4727d9afbe11727b),
        UINT64_C(0x7e950d0c0121b34d), UINT64_C(0x756f435670ad471f),
        UINT64_C(0xf5add442615a6849), UINT64_C(0x4e87e09980b9957a),
        UINT64_C(0x2acfa1df50aee355), UINT64_C(0xd898263afd2fd556),
        UINT64_C(0xc8f4924dd80c8fd6), UINT64_C(0xcf99ca3d754a173a),
        UINT64_C(0xfe477bacaf91bf3c), UINT64_C(0xed5371f6d690c12d),
        UINT64_C(0x831a5c285e687094), UINT64_C(0xc5d3c90a3708a0a4),
        UINT64_C(0x0f7f903717d06580), UINT64_C(0x19f9bb13b8fdf27f),
        UINT64_C(0xb1bd6f1b4d502843), UINT64_C(0x1c761ba38fff4012),
        UINT64_C(0x0d1530c4e2e21f3b), UINT64_C(0x8943ce69a7372c8a),
        UINT64_C(0xe5184e11feb5ce66), UINT64_C(0x618bdb80bd736621),
        UINT64_C(0x7d29bad68b574d0b), UINT64_C(0x81bb613e25e6fe5b),
        UINT64_C(0x071c9c10bc07913f), UINT64_C(0xc7beeb7909ac2d97),
        UINT64_C(0xc3e58d353bc5d757), UINT64_C(0xeb017892f38f61e8),
        UINT64_C(0xd4effb9c9b1cc21a), UINT64_C(0x99727d26f494f7ab),
        UINT64_C(0xa3e063a2956b3e03), UINT64_C(0x9d4a8b9a4aa09c30),
        UINT64_C(0x3f6ab7d500090fb4), UINT64_C(0x9cc0f2a057268ac0),
        UINT64_C(0x3dee9d2dedbf42d1), UINT64_C(0x330f49c87960a972),
        UINT64_C(0xc6b2720287421b41), UINT64_C(0x0ac59ec07c00369c),
        UINT64_C(0xef4eac49cb353425), UINT64_C(0xf450244eef0129d8),
        UINT64_C(0x8acc46e5caf4deb6), UINT64_C(0x2ffeab63989263f7),
        UINT64_C(0x8f7cb9fe5d7a4578), UINT64_C(0x5bd8f7644e634635),
        UINT64_C(0x427a7315bf2dc900), UINT64_C(0x17d0c4aa2125261c),
        UINT64_C(0x3992486c93518e50), UINT64_C(0xb4cbfee0a2d7d4c3),
        UINT64_C(0x7c75d6202c5ddd8d), UINT64_C(0xdbc295d8e35b6c61),
        UINT64_C(0x60b369d302032b19), UINT64_C(0xce42685fdce44132),
        UINT64_C(0x06f3ddb9ddf65610), UINT64_C(0x8ea4d21db5e148f0),
        UINT64_C(0x20b0fce62fcd496f), UINT64_C(0x2c1b912358b0ee31),
        UINT64_C(0xb28317b818f5a308), UINT64_C(0xa89c1e189ca6d2cf),
        UINT64_C(0x0c6b18576aaadbc8), UINT64_C(0xb65deaa91299fae3),
        UINT64_C(0xfb2b794b7f1027e7), UINT64_C(0x04e4317f443b5beb),
        UINT64_C(0x4b852d325939d0a6), UINT64_C(0xd5ae6beefb207ffc),
        UINT64_C(0x309682b281c7d374), UINT64_C(0xbae309a194c3b475),
        UINT64_C(0x8cc3f97b13b49f05), UINT64_C(0x98a9422ff8293967),
        UINT64_C(0x244b16b01076ff7c), UINT64_C(0xf8bf571c663d67ee),
        UINT64_C(0x1f0d6758eee30da1), UINT64_C(0xc9b611d97adeb9b7),
        UINT64_C(0xb7afd5887b6c57a2), UINT64_C(0x6290ae846b984fe1),
        UINT64_C(0x94df4cdeacc1a5fd), UINT64_C(0x058a5bd1c5483aff),
        UINT64_C(0x63166cc142ba3c37), UINT64_C(0x8db8526eb2f76f40),
        UINT64_C(0xe10880036f0d6d4e), UINT64_C(0x9e0523c9971d311d),
        UINT64_C(0x45ec2824cc7cd691), UINT64_C(0x575b8359e62382c9),
        UINT64_C(0xfa9e400dc4889995), UINT64_C(0xd1823ecb45721568),
        UINT64_C(0xdafd983b8206082f), UINT64_C(0xaa7d29082386a8cb),
        UINT64_C(0x269fcd4403b87588), UINT64_C(0x1b91f5f728bdd1e0),
        UINT64_C(0xe4669f39040201f6), UINT64_C(0x7a1d7c218cf04ade),
        UINT64_C(0x65623c29d79ce5ce), UINT64_C(0x2368449096c00bb1),
        UINT64_C(0xab9bf1879da503ba), UINT64_C(0xbc23ecb1a458058e),
        UINT64_C(0x9a58df01bb401ecc), UINT64_C(0xa070e868a85f143d),
        UINT64_C(0x4ff188307df2239e), UINT64_C(0x14d565b41a641183),
        UINT64_C(0xee13337452701602), UINT64_C(0x950e3dcf3f285e09),
        UINT64_C(0x59930254b9c80953), UINT64_C(0x3bf299408930da6d),
        UINT64_C(0xa955943f53691387), UINT64_C(0xa15edecaa9cb8784),
        UINT64_C(0x29142127352be9a0), UINT64_C(0x76f0371fff4e7afb),
        UINT64_C(0x0239f450274f2228), UINT64_C(0xbb073af01d5e868b),
        UINT64_C(0xbfc80571c10e96c1), UINT64_C(0xd267088568222e23),
        UINT64_C(0x9671a3d48e80b5b0), UINT64_C(0x55b5d38ae193bb81),
        UINT64_C(0x693ae2d0a18b04b8), UINT64_C(0x5c48b4ecadd5335f),
        UINT64_C(0xfd743b194916a1ca), UINT64_C(0x2577018134be98c4),
        UINT64_C(0xe77987e83c54a4ad), UINT64_C(0x28e11014da33e1b9),
        UINT64_C(0x270cc59e226aa213), UINT64_C(0x71495f756d1a5f60),
        UINT64_C(0x9be853fb60afef77), UINT64_C(0xadc786a7f7443dbf),
        UINT64_C(0x0904456173b29a82), UINT64_C(0x58bc7a66c232bd5e),
        UINT64_C(0xf306558c673ac8b2), UINT64_C(0x41f639c6b6c9772a),
        UINT64_C(0x216defe99fda35da), UINT64_C(0x11640cc71c7be615),
        UINT64_C(0x93c43694565c5527), UINT64_C(0xea038e6246777839),
        UINT64_C(0xf9abf3ce5a3e2469), UINT64_C(0x741e768d0fd312d2),
        UINT64_C(0x0144b883ced652c6), UINT64_C(0xc20b5a5ba33f8552),
        UINT64_C(0x1ae69633c3435a9d), UINT64_C(0x97a28ca4088cfdec),
        UINT64_C(0x8824a43c1e96f420), UINT64_C(0x37612fa66eeea746),
        UINT64_C(0x6b4cb165f9cf0e5a), UINT64_C(0x43aa1c06a0abfb4a),
        UINT64_C(0x7f4dc26ff162796b), UINT64_C(0x6cbacc8e54ed9b0f),
        UINT64_C(0xa6b7ffefd2bb253e), UINT64_C(0x2e25bc95b0a29d4f),
        UINT64_C(0x86d6a58bdef1388c), UINT64_C(0xded74ac576b6f054),
        UINT64_C(0x8030bdbc2b45805d), UINT64_C(0x3c81af70e94d9289),
        UINT64_C(0x3eff6dda9e3100db), UINT64_C(0xb38dc39fdfcc8847),
        UINT64_C(0x123885528d17b87e), UINT64_C(0xf2da0ed240b1b642),
        UINT64_C(0x44cefadcd54bf9a9), UINT64_C(0x1312200e433c7ee6),
        UINT64_C(0x9ffcc84f3a78c748), UINT64_C(0xf0cd1f72248576bb),
        UINT64_C(0xec6974053638cfe4), UINT64_C(0x2ba7b67c0cec4e4c),
        UINT64_C(0xac2f4df3e5ce32ed), UINT64_C(0xcb33d14326ea4c11),
        UINT64_C(0xa4e9044cc77e58bc), UINT64_C(0x5f513293d934fcef),
        UINT64_C(0x5dc9645506e55444), UINT64_C(0x50de418f317de40a),
        UINT64_C(0x388cb31a69dde259), UINT64_C(0x2db4a83455820a86),
        UINT64_C(0x9010a91e84711ae9), UINT64_C(0x4df7f0b7b1498371),
        UINT64_C(0xd62a2eabc0977179), UINT64_C(0x22fac097aa8d5c0e)
    },
    {
        UINT64_C(0xF49FCC2FF1DAF39B), UINT64_C(0x487FD5C66FF29281),
        UINT64_C(0xE8A30667FCDCA83F), UINT64_C(0x2C9B4BE3D2FCCE63),
        UINT64_C(0xDA3FF74B93FBBBC2), UINT64_C(0x2FA165D2FE70BA66),
        UINT64_C(0xA103E279970E93D4), UINT64_C(0xBECDEC77B0E45E71),
        UINT64_C(0xCFB41E723985E497), UINT64_C(0xB70AAA025EF75017),
        UINT64_C(0xD42309F03840B8E0), UINT64_C(0x8EFC1AD035898579),
        UINT64_C(0x96C6920BE2B2ABC5), UINT64_C(0x66AF4163375A9172),
        UINT64_C(0x2174ABDCCA7127FB), UINT64_C(0xB33CCEA64A72FF41),
        UINT64_C(0xF04A4933083066A5), UINT64_C(0x8D970ACDD7289AF5),
        UINT64_C(0x8F96E8E031C8C25E), UINT64_C(0xF3FEC02276875D47),
        UINT64_C(0xEC7BF310056190DD), UINT64_C(0xF5ADB0AEBB0F1491),
        UINT64_C(0x9B50F8850FD58892), UINT64_C(0x4975488358B74DE8),
        UINT64_C(0xA3354FF691531C61), UINT64_C(0x0702BBE481D2C6EE),
        UINT64_C(0x89FB24057DEDED98), UINT64_C(0xAC3075138596E902),
        UINT64_C(0x1D2D3580172772ED), UINT64_C(0xEB738FC28E6BC30D),
        UINT64_C(0x5854EF8F63044326), UINT64_C(0x9E5C52325ADD3BBE),
        UINT64_C(0x90AA53CF325C4623), UINT64_C(0xC1D24D51349DD067),
        UINT64_C(0x2051CFEEA69EA624), UINT64_C(0x13220F0A862E7E4F),
        UINT64_C(0xCE39399404E04864), UINT64_C(0xD9C42CA47086FCB7),
        UINT64_C(0x685AD2238A03E7CC), UINT64_C(0x066484B2AB2FF1DB),
        UINT64_C(0xFE9D5D70EFBF79EC), UINT64_C(0x5B13B9DD9C481854),
        UINT64_C(0x15F0D475ED1509AD), UINT64_C(0x0BEBCD060EC79851),
        UINT64_C(0xD58C6791183AB7F8), UINT64_C(0xD1187C5052F3EEE4),
        UINT64_C(0xC95D1192E54E82FF), UINT64_C(0x86EEA14CB9AC6CA2),
        UINT64_C(0x3485BEB153677D5D), UINT64_C(0xDD191D781F8C492A),
        UINT64_C(0xF60866BAA784EBF9), UINT64_C(0x518F643BA2D08C74),
        UINT64_C(0x8852E956E1087C22), UINT64_C(0xA768CB8DC410AE8D),
        UINT64_C(0x38047726BFEC8E1A), UINT64_C(0xA67738B4CD3B45AA),
        UINT64_C(0xAD16691CEC0DDE19), UINT64_C(0xC6D4319380462E07),
        UINT64_C(0xC5A5876D0BA61938), UINT64_C(0x16B9FA1FA58FD840),
        UINT64_C(0x188AB1173CA74F18), UINT64_C(0xABDA2F98C99C021F),
        UINT64_C(0x3E0580AB134AE816), UINT64_C(0x5F3B05B773645ABB),
        UINT64_C(0x2501A2BE5575F2F6), UINT64_C(0x1B2F74004E7E8BA9),
        UINT64_C(0x1CD7580371E8D953), UINT64_C(0x7F6ED89562764E30),
        UINT64_C(0xB15926FF596F003D), UINT64_C(0x9F65293DA8C5D6B9),
        UINT64_C(0x6ECEF04DD690F84C), UINT64_C(0x4782275FFF33AF88),
        UINT64_C(0xE41433083F820801), UINT64_C(0xFD0DFE409A1AF9B5),
        UINT64_C(0x4325A3342CDB396B), UINT64_C(0x8AE77E62B301B252),
        UINT64_C(0xC36F9E9F6655615A), UINT64_C(0x85455A2D92D32C09),
        UINT64_C(0xF2C7DEA949477485), UINT64_C(0x63CFB4C133A39EBA),
        UINT64_C(0x83B040CC6EBC5462), UINT64_C(0x3B9454C8FDB326B0),
        UINT64_C(0x56F56A9E87FFD78C), UINT64_C(0x2DC2940D99F42BC6),
        UINT64_C(0x98F7DF096B096E2D), UINT64_C(0x19A6E01E3AD852BF),
        UINT64_C(0x42A99CCBDBD4B40B), UINT64_C(0xA59998AF45E9C559),
        UINT64_C(0x366295E807D93186), UINT64_C(0x6B48181BFAA1F773),
        UINT64_C(0x1FEC57E2157A0A1D), UINT64_C(0x4667446AF6201AD5),
        UINT64_C(0xE615EBCACFB0F075), UINT64_C(0xB8F31F4F68290778),
        UINT64_C(0x22713ED6CE22D11E), UINT64_C(0x3057C1A72EC3C93B),
        UINT64_C(0xCB46ACC37C3F1F2F), UINT64_C(0xDBB893FD02AAF50E),
        UINT64_C(0x331FD92E600B9FCF), UINT64_C(0xA498F96148EA3AD6),
        UINT64_C(0xA8D8426E8B6A83EA), UINT64_C(0xA089B274B7735CDC),
        UINT64_C(0x87F6B3731E524A11), UINT64_C(0x118808E5CBC96749),
        UINT64_C(0x9906E4C7B19BD394), UINT64_C(0xAFED7F7E9B24A20C),
        UINT64_C(0x6509EADEEB3644A7), UINT64_C(0x6C1EF1D3E8EF0EDE),
        UINT64_C(0xB9C97D43E9798FB4), UINT64_C(0xA2F2D784740C28A3),
        UINT64_C(0x7B8496476197566F), UINT64_C(0x7A5BE3E6B65F069D),
        UINT64_C(0xF96330ED78BE6F10), UINT64_C(0xEEE60DE77A076A15),
        UINT64_C(0x2B4BEE4AA08B9BD0), UINT64_C(0x6A56A63EC7B8894E),
        UINT64_C(0x02121359BA34FEF4), UINT64_C(0x4CBF99F8283703FC),
        UINT64_C(0x398071350CAF30C8), UINT64_C(0xD0A77A89F017687A),
        UINT64_C(0xF1C1A9EB9E423569), UINT64_C(0x8C7976282DEE8199),
        UINT64_C(0x5D1737A5DD1F7ABD), UINT64_C(0x4F53433C09A9FA80),
        UINT64_C(0xFA8B0C53DF7CA1D9), UINT64_C(0x3FD9DCBC886CCB77),
        UINT64_C(0xC040917CA91B4720), UINT64_C(0x7DD00142F9D1DCDF),
        UINT64_C(0x8476FC1D4F387B58), UINT64_C(0x23F8E7C5F3316503),
        UINT64_C(0x032A2244E7E37339), UINT64_C(0x5C87A5D750F5A74B),
        UINT64_C(0x082B4CC43698992E), UINT64_C(0xDF917BECB858F63C),
        UINT64_C(0x3270B8FC5BF86DDA), UINT64_C(0x10AE72BB29B5DD76),
        UINT64_C(0x576AC94E7700362B), UINT64_C(0x1AD112DAC61EFB8F),
        UINT64_C(0x691BC30EC5FAA427), UINT64_C(0xFF246311CC327143),
        UINT64_C(0x3142368E30E53206), UINT64_C(0x71380E31E02CA396),
        UINT64_C(0x958D5C960AAD76F1), UINT64_C(0xF8D6F430C16DA536),
        UINT64_C(0xC8FFD13F1BE7E1D2), UINT64_C(0x7578AE66004DDBE1),
        UINT64_C(0x05833F01067BE646), UINT64_C(0xBB34B5AD3BFE586D),
        UINT64_C(0x095F34C9A12B97F0), UINT64_C(0x247AB64525D60CA8),
        UINT64_C(0xDCDBC6F3017477D1), UINT64_C(0x4A2E14D4DECAD24D),
        UINT64_C(0xBDB5E6D9BE0A1EEB), UINT64_C(0x2A7E70F7794301AB),
        UINT64_C(0xDEF42D8A270540FD), UINT64_C(0x01078EC0A34C22C1),
        UINT64_C(0xE5DE511AF4C16387), UINT64_C(0x7EBB3A52BD9A330A),
        UINT64_C(0x77697857AA7D6435), UINT64_C(0x004E831603AE4C32),
        UINT64_C(0xE7A21020AD78E312), UINT64_C(0x9D41A70C6AB420F2),
        UINT64_C(0x28E06C18EA1141E6), UINT64_C(0xD2B28CBD984F6B28),
        UINT64_C(0x26B75F6C446E9D83), UINT64_C(0xBA47568C4D418D7F),
        UINT64_C(0xD80BADBFE6183D8E), UINT64_C(0x0E206D7F5F166044),
        UINT64_C(0xE258A43911CBCA3E), UINT64_C(0x723A1746B21DC0BC),
        UINT64_C(0xC7CAA854F5D7CDD3), UINT64_C(0x7CAC32883D261D9C),
        UINT64_C(0x7690C26423BA942C), UINT64_C(0x17E55524478042B8),
        UINT64_C(0xE0BE477656A2389F), UINT64_C(0x4D289B5E67AB2DA0),
        UINT64_C(0x44862B9C8FBBFD31), UINT64_C(0xB47CC8049D141365),
        UINT64_C(0x822C1B362B91C793), UINT64_C(0x4EB14655FB13DFD8),
        UINT64_C(0x1ECBBA0714E2A97B), UINT64_C(0x6143459D5CDE5F14),
        UINT64_C(0x53A8FBF1D5F0AC89), UINT64_C(0x97EA04D81C5E5B00),
        UINT64_C(0x622181A8D4FDB3F3), UINT64_C(0xE9BCD341572A1208),
        UINT64_C(0x1411258643CCE58A), UINT64_C(0x9144C5FEA4C6E0A4),
        UINT64_C(0x0D33D06565CF620F), UINT64_C(0x54A48D489F219CA1),
        UINT64_C(0xC43E5EAC6D63C821), UINT64_C(0xA9728B3A72770DAF),
        UINT64_C(0xD7934E7B20DF87EF), UINT64_C(0xE35503B61A3E86E5),
        UINT64_C(0xCAE321FBC819D504), UINT64_C(0x129A50B3AC60BFA6),
        UINT64_C(0xCD5E68EA7E9FB6C3), UINT64_C(0xB01C90199483B1C7),
        UINT64_C(0x3DE93CD5C295376C), UINT64_C(0xAED52EDF2AB9AD13),
        UINT64_C(0x2E60F512C0A07884), UINT64_C(0xBC3D86A3E36210C9),
        UINT64_C(0x35269D9B163951CE), UINT64_C(0x0C7D6E2AD0CDB5FA),
        UINT64_C(0x59E86297D87F5733), UINT64_C(0x298EF221898DB0E7),
        UINT64_C(0x55000029D1A5AA7E), UINT64_C(0x8BC08AE1B5061B45),
        UINT64_C(0xC2C31C2B6C92703A), UINT64_C(0x94CC596BAF25EF42),
        UINT64_C(0x0A1D73DB22540456), UINT64_C(0x04B6A0F9D9C4179A),
        UINT64_C(0xEFFDAFA2AE3D3C60), UINT64_C(0xF7C8075BB49496C4),
        UINT64_C(0x9CC5C7141D1CD4E3), UINT64_C(0x78BD1638218E5534),
        UINT64_C(0xB2F11568F850246A), UINT64_C(0xEDFABCFA9502BC29),
        UINT64_C(0x796CE5F2DA23051B), UINT64_C(0xAAE128B0DC93537C),
        UINT64_C(0x3A493DA0EE4B29AE), UINT64_C(0xB5DF6B2C416895D7),
        UINT64_C(0xFCABBD25122D7F37), UINT64_C(0x70810B58105DC4B1),
        UINT64_C(0xE10FDD37F7882A90), UINT64_C(0x524DCAB5518A3F5C),
        UINT64_C(0x3C9E85878451255B), UINT64_C(0x4029828119BD34E2),
        UINT64_C(0x74A05B6F5D3CECCB), UINT64_C(0xB610021542E13ECA),
        UINT64_C(0x0FF979D12F59E2AC), UINT64_C(0x6037DA27E4F9CC50),
        UINT64_C(0x5E92975A0DF1847D), UINT64_C(0xD66DE190D3E623FE),
        UINT64_C(0x5032D6B87B568048), UINT64_C(0x9A36B7CE8235216E),
        UINT64_C(0x80272A7A24F64B4A), UINT64_C(0x93EFED8B8C6916F7),
        UINT64_C(0x37DDBFF44CCE1555), UINT64_C(0x4B95DB5D4B99BD25),
        UINT64_C(0x92D3FDA169812FC0), UINT64_C(0xFB1A4A9A90660BB6),
        UINT64_C(0x730C196946A4B9B2), UINT64_C(0x81E289AA7F49DA68),
        UINT64_C(0x64669A0F83B1A05F), UINT64_C(0x27B3FF7D9644F48B),
        UINT64_C(0xCC6B615C8DB675B3), UINT64_C(0x674F20B9BCEBBE95),
        UINT64_C(0x6F31238275655982), UINT64_C(0x5AE488713E45CF05),
        UINT64_C(0xBF619F9954C21157), UINT64_C(0xEABAC46040A8EAE9),
        UINT64_C(0x454C6FE9F2C0C1CD), UINT64_C(0x419CF6496412691C),
        UINT64_C(0xD3DC3BEF265B0F70), UINT64_C(0x6D0E60F5C3578A9E)
    },
    {
        UINT64_C(0x5b0e608526323c55), UINT64_C(0x1a46c1a9fa1b59f5),
        UINT64_C(0xa9e245a17c4c8ffa), UINT64_C(0x65ca5159db2955d7),
        UINT64_C(0x05db0a76ce35afc2), UINT64_C(0x81eac77ea9113d45),
        UINT64_C(0x528ef88ab6ac0a0d), UINT64_C(0xa09ea253597be3ff),
        UINT64_C(0x430ddfb3ac48cd56), UINT64_C(0xc4b3a67af45ce46f),
        UINT64_C(0x4ececfd8fbe2d05e), UINT64_C(0x3ef56f10b39935f0),
        UINT64_C(0x0b22d6829cd619c6), UINT64_C(0x17fd460a74df2069),
        UINT64_C(0x6cf8cc8e8510ed40), UINT64_C(0xd6c824bf3a6ecaa7),
        UINT64_C(0x61243d581a817049), UINT64_C(0x048bacb6bbc163a2),
        UINT64_C(0xd9a38ac27d44cc32), UINT64_C(0x7fddff5baaf410ab),
        UINT64_C(0xad6d495aa804824b), UINT64_C(0xe1a6a74f2d8c9f94),
        UINT64_C(0xd4f7851235dee8e3), UINT64_C(0xfd4b7f886540d893),
        UINT64_C(0x247c20042aa4bfda), UINT64_C(0x096ea1c517d1327c),
        UINT64_C(0xd56966b4361a6685), UINT64_C(0x277da5c31221057d),
        UINT64_C(0x94d59893a43acff7), UINT64_C(0x64f0c51ccdc02281),
        UINT64_C(0x3d33bcc4ff6189db), UINT64_C(0xe005cb184ce66af1),
        UINT64_C(0xff5ccd1d1db99bea), UINT64_C(0xb0b854a7fe42980f),
        UINT64_C(0x7bd46a6a718d4b9f), UINT64_C(0xd10fa8cc22a5fd8c),
        UINT64_C(0xd31484952be4bd31), UINT64_C(0xc7fa975fcb243847),
        UINT64_C(0x4886ed1e5846c407), UINT64_C(0x28cddb791eb70b04),
        UINT64_C(0xc2b00be2f573417f), UINT64_C(0x5c9590452180f877),
        UINT64_C(0x7a6bddfff370eb00), UINT64_C(0xce509e38d6d9d6a4),
        UINT64_C(0xebeb0f00647fa702), UINT64_C(0x1dcc06cf76606f06),
        UINT64_C(0xe4d9f28ba286ff0a), UINT64_C(0xd85a305dc918c262),
        UINT64_C(0x475b1d8732225f54), UINT64_C(0x2d4fb51668ccb5fe),
        UINT64_C(0xa679b9d9d72bba20), UINT64_C(0x53841c0d912d43a5),
        UINT64_C(0x3b7eaa48bf12a4e8), UINT64_C(0x781e0e47f22f1ddf),
        UINT64_C(0xeff20ce60ab50973), UINT64_C(0x20d261d19dffb742),
        UINT64_C(0x16a12b03062a2e39), UINT64_C(0x1960eb2239650495),
        UINT64_C(0x251c16fed50eb8b8), UINT64_C(0x9ac0c330f826016e),
        UINT64_C(0xed152665953e7671), UINT64_C(0x02d63194a6369570),
        UINT64_C(0x5074f08394b1c987), UINT64_C(0x70ba598c90b25ce1),
        UINT64_C(0x794a15810b9742f6), UINT64_C(0x0d5925e9fcaf8c6c),
        UINT64_C(0x3067716cd868744e), UINT64_C(0x910ab077e8d7731b),
        UINT64_C(0x6a61bbdb5ac42f61), UINT64_C(0x93513efbf0851567),
        UINT64_C(0xf494724b9e83e9d5), UINT64_C(0xe887e1985c09648d),
        UINT64_C(0x34b1d3c675370cfd), UINT64_C(0xdc35e433bc0d255d),
        UINT64_C(0xd0aab84234131be0), UINT64_C(0x08042a50b48b7eaf),
        UINT64_C(0x9997c4ee44a3ab35), UINT64_C(0x829a7b49201799d0),
        UINT64_C(0x263b8307b7c54441), UINT64_C(0x752f95f4fd6a6ca6),
        UINT64_C(0x927217402c08c6e5), UINT64_C(0x2a8ab754a795d9ee),
        UINT64_C(0xa442f7552f72943d), UINT64_C(0x2c31334e19781208),
        UINT64_C(0x4fa98d7ceaee6291), UINT64_C(0x55c3862f665db309),
        UINT64_C(0xbd0610175d53b1f3), UINT64_C(0x46fe6cb840413f27),
        UINT64_C(0x3fe03792df0cfa59), UINT64_C(0xcfe700372eb85e8f),
        UINT64_C(0xa7be29e7adbce118), UINT64_C(0xe544ee5cde8431dd),
        UINT64_C(0x8a781b1b41f1873e), UINT64_C(0xa5c94c78a0d2f0e7),
        UINT64_C(0x39412e2877b60728), UINT64_C(0xa1265ef3afc9a62c),
        UINT64_C(0xbcc2770c6a2506c5), UINT64_C(0x3ab66dd5dce1ce12),
        UINT64_C(0xe65499d04a675b37), UINT64_C(0x7d8f523481bfd216),
        UINT64_C(0x0f6f64fcec15f389), UINT64_C(0x74efbe618b5b13c8),
        UINT64_C(0xacdc82b714273e1d), UINT64_C(0xdd40bfe003199d17),
        UINT64_C(0x37e99257e7e061f8), UINT64_C(0xfa52626904775aaa),
        UINT64_C(0x8bbbf63a463d56f9), UINT64_C(0xf0013f1543a26e64),
        UINT64_C(0xa8307e9f879ec898), UINT64_C(0xcc4c27a4150177cc),
        UINT64_C(0x1b432f2cca1d3348), UINT64_C(0xde1d1f8f9f6fa013),
        UINT64_C(0x606602a047a7ddd6), UINT64_C(0xd237ab64cc1cb2c7),
        UINT64_C(0x9b938e7225fcd1d3), UINT64_C(0xec4e03708e0ff476),
        UINT64_C(0xfeb2fbda3d03c12d), UINT64_C(0xae0bced2ee43889a),
        UINT64_C(0x22cb8923ebfb4f43), UINT64_C(0x69360d013cf7396d),
        UINT64_C(0x855e3602d2d4e022), UINT64_C(0x073805bad01f784c),
        UINT64_C(0x33e17a133852f546), UINT64_C(0xdf4874058ac7b638),
        UINT64_C(0xba92b29c678aa14a), UINT64_C(0x0ce89fc76cfaadcd),
        UINT64_C(0x5f9d4e0908339e34), UINT64_C(0xf1afe9291f5923b9),
        UINT64_C(0x6e3480f60f4a265f), UINT64_C(0xeebf3a2ab29b841c),
        UINT64_C(0xe21938a88f91b4ad), UINT64_C(0x57dfeff845c6d3c3),
        UINT64_C(0x2f006b0bf62caaf2), UINT64_C(0x62f479ef6f75ee78),
        UINT64_C(0x11a55ad41c8916a9), UINT64_C(0xf229d29084fed453),
        UINT64_C(0x42f1c27b16b000e6), UINT64_C(0x2b1f76749823c074),
        UINT64_C(0x4b76eca3c2745360), UINT64_C(0x8c98f463b91691bd),
        UINT64_C(0x14bcc93cf1ade66a), UINT64_C(0x8885213e6d458397),
        UINT64_C(0x8e177df0274d4711), UINT64_C(0xb49b73b5503f2951),
        UINT64_C(0x10168168c3f96b6b), UINT64_C(0x0e3d963b63cab0ae),
        UINT64_C(0x8dfc4b5655a1db14), UINT64_C(0xf789f1356e14de5c),
        UINT64_C(0x683e68af4e51dac1), UINT64_C(0xc9a84f9d8d4b0fd9),
        UINT64_C(0x3691e03f52a0f9d1), UINT64_C(0x5ed86e46e1878e80),
        UINT64_C(0x3c711a0e99d07150), UINT64_C(0x5a0865b20c4e9310),
        UINT64_C(0x56fbfc1fe4f0682e), UINT64_C(0xea8d5de3105edf9b),
        UINT64_C(0x71abfdb12379187a), UINT64_C(0x2eb99de1bee77b9c),
        UINT64_C(0x21ecc0ea33cf4523), UINT64_C(0x59a4d7521805c7a1),
        UINT64_C(0x3896f5eb56ae7c72), UINT64_C(0xaa638f3db18f75dc),
        UINT64_C(0x9f39358dabe9808e), UINT64_C(0xb7defa91c00b72ac),
        UINT64_C(0x6b5541fd62492d92), UINT64_C(0x6dc6dee8f92e4d5b),
        UINT64_C(0x353f57abc4beea7e), UINT64_C(0x735769d6da5690ce),
        UINT64_C(0x0a234aa642391484), UINT64_C(0xf6f9508028f80d9d),
        UINT64_C(0xb8e319a27ab3f215), UINT64_C(0x31ad9c1151341a4d),
        UINT64_C(0x773c22a57bef5805), UINT64_C(0x45c7561a07968633),
        UINT64_C(0xf913da9e249dbe36), UINT64_C(0xda652d9b78a64c68),
        UINT64_C(0x4c27a97f3bc334ef), UINT64_C(0x76621220e66b17f4),
        UINT64_C(0x967743899acd7d0b), UINT64_C(0xf3ee5bcae0ed6782),
        UINT64_C(0x409f753600c879fc), UINT64_C(0x06d09a39b5926db6),
        UINT64_C(0x6f83aeb0317ac588), UINT64_C(0x01e6ca4a86381f21),
        UINT64_C(0x66ff3462d19f3025), UINT64_C(0x72207c24ddfd3bfb),
        UINT64_C(0x4af6b6d3e2ece2eb), UINT64_C(0x9c994dbec7ea08de),
        UINT64_C(0x49ace597b09a8bc4), UINT64_C(0xb38c4766cf0797ba),
        UINT64_C(0x131b9373c57c2a75), UINT64_C(0xb1822cce61931e58),
        UINT64_C(0x9d7555b909ba1c0c), UINT64_C(0x127fafdd937d11d2),
        UINT64_C(0x29da3badc66d92e4), UINT64_C(0xa2c1d57154c2ecbc),
        UINT64_C(0x58c5134d82f6fe24), UINT64_C(0x1c3ae3515b62274f),
        UINT64_C(0xe907c82e01cb8126), UINT64_C(0xf8ed091913e37fcb),
        UINT64_C(0x3249d8f9c80046c9), UINT64_C(0x80cf9bede388fb63),
        UINT64_C(0x1881539a116cf19e), UINT64_C(0x5103f3f76bd52457),
        UINT64_C(0x15b7e6f5ae47f7a8), UINT64_C(0xdbd7c6ded47e9ccf),
        UINT64_C(0x44e55c410228bb1a), UINT64_C(0xb647d4255edb4e99),
        UINT64_C(0x5d11882bb8aafc30), UINT64_C(0xf5098bbb29d3212a),
        UINT64_C(0x8fb5ea14e90296b3), UINT64_C(0x677b942157dd025a),
        UINT64_C(0xfb58e7c0a390acb5), UINT64_C(0x89d3674c83bd4a01),
        UINT64_C(0x9e2da4df4bf3b93b), UINT64_C(0xfcc41e328cab4829),
        UINT64_C(0x03f38c96ba582c52), UINT64_C(0xcad1bdbd7fd85db2),
        UINT64_C(0xbbb442c16082ae83), UINT64_C(0xb95fe86ba5da9ab0),
        UINT64_C(0xb22e04673771a93f), UINT64_C(0x845358c9493152d8),
        UINT64_C(0xbe2a488697b4541e), UINT64_C(0x95a2dc2dd38e6966),
        UINT64_C(0xc02c11ac923c852b), UINT64_C(0x2388b1990df2a87b),
        UINT64_C(0x7c8008fa1b4f37be), UINT64_C(0x1f70d0c84d54e503),
        UINT64_C(0x5490adec7ece57d4), UINT64_C(0x002b3c27d9063a3a),
        UINT64_C(0x7eaea3848030a2bf), UINT64_C(0xc602326ded2003c0),
        UINT64_C(0x83a7287d69a94086), UINT64_C(0xc57a5fcb30f57a8a),
        UINT64_C(0xb56844e479ebe779), UINT64_C(0xa373b40f05dcbce9),
        UINT64_C(0xd71a786e88570ee2), UINT64_C(0x879cbacdbde8f6a0),
        UINT64_C(0x976ad1bcc164a32f), UINT64_C(0xab21e25e9666d78b),
        UINT64_C(0x901063aae5e5c33c), UINT64_C(0x9818b34448698d90),
        UINT64_C(0xe36487ae3e1e8abb), UINT64_C(0xafbdf931893bdcb4),
        UINT64_C(0x6345a0dc5fbbd519), UINT64_C(0x8628fe269b9465ca),
        UINT64_C(0x1e5d01603f9c51ec), UINT64_C(0x4de44006a15049b7),
        UINT64_C(0xbf6c70e5f776cbb1), UINT64_C(0x411218f2ef552bed),
        UINT64_C(0xcb0c0708705a36a3), UINT64_C(0xe74d14754f986044),
        UINT64_C(0xcd56d9430ea8280e), UINT64_C(0xc12591d7535f5065),
        UINT64_C(0xc83223f1720aef96), UINT64_C(0xc3a0396f7363a51f)
    }
};
