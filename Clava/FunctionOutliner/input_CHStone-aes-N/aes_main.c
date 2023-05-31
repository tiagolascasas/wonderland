#include <stdio.h>
int main_result;
int key_type;
int nb;
int round_var;
int key[32];
int statemt[32];
int word[4][120];
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/

/*aes.c*/

/*
 * Copyright (C) 2005
 * Akira Iwata & Masayuki Sato
 * Akira Iwata Laboratory,
 * Nagoya Institute of Technology in Japan.
 *
 * All rights reserved.
 *
 * This software is written by Masayuki Sato.
 * And if you want to contact us, send an email to Kimitake Wakayama
 * (wakayama@elcom.nitech.ac.jp)
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this software must
 *    display the following acknowledgment:
 *    "This product includes software developed by Akira Iwata Laboratory,
 *    Nagoya Institute of Technology in Japan (http://mars.elcom.nitech.ac.jp/)."
 *
 * 4. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by Akira Iwata Laboratory,
 *     Nagoya Institute of Technology in Japan (http://mars.elcom.nitech.ac.jp/)."
 *
 *   THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.
 *   AKIRA IWATA LABORATORY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 *   SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS,
 *   IN NO EVENT SHALL AKIRA IWATA LABORATORY BE LIABLE FOR ANY SPECIAL,
 *   INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 *   FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 *   NEGLIGENCE OR OTHER TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION
 *   WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

/************** data type define **************************/

/*key generate*/
int KeySchedule(int, int *);
int SubByte(int);
/*encrypto decrypto*/
void ByteSub_ShiftRow(int *, int);
void InversShiftRow_ByteSub(int *, int);
int MixColumn_AddRoundKey(int *, int, int);
int AddRoundKey_InversMixColumn(int *, int, int);
int AddRoundKey(int *, int, int);
int encrypt(int *, int *, int);
int decrypt(int *, int *, int);
int encrypt(int statemt[32], int key[32], int key_type)
{
    int i;
    int const out_enc_statemt[16] = {0x39, 0x25, 0x84, 0x1d, 0x2, 0xdc, 0x9, 0xfb, 0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0xb, 0x32};
    int decomp_0;
    decomp_0 = KeySchedule(key_type, key);
    /*
    +--------------------------------------------------------------------------+
    | * Test Vector (added for CHStone)                                        |
    |     out_enc_statemt : expected output data for "encrypt"                 |
    +--------------------------------------------------------------------------+
    */
    switch (key_type)
    {
    case 128128:;
        round_var = 0;
        nb = 4;
        break;
    case 192128:;
        round_var = 2;
        nb = 4;
        break;
    case 256128:;
        round_var = 4;
        nb = 4;
        break;
    case 128192:;
    case 192192:;
        round_var = 2;
        nb = 6;
        break;
    case 256192:;
        round_var = 4;
        nb = 6;
        break;
    case 128256:;
    case 192256:;
    case 256256:;
        round_var = 4;
        nb = 8;
        break;
    }
    int decomp_1;
    decomp_1 = AddRoundKey(statemt, key_type, 0);
    for (i = 1; i <= round_var + 9; ++i)
    {
        ByteSub_ShiftRow(statemt, nb);
        int decomp_3;
        decomp_3 = MixColumn_AddRoundKey(statemt, nb, i);
    }
    ByteSub_ShiftRow(statemt, nb);
    int decomp_5;
    decomp_5 = AddRoundKey(statemt, key_type, i);
    // printf ("encrypted message \t");
    // for (i = 0; i < nb * 4; ++i)
    // {
    // if (statemt[i] < 16)
    // printf ("0");
    // printf ("%x", statemt[i]);
    // }
    for (i = 0; i < 16; i++)
    {
        int decomp_0;
        int decomp_6;
        decomp_6 = statemt[i] != out_enc_statemt[i];
        decomp_0 = decomp_6;
        if (decomp_0)
        {
            int decomp_7;
            decomp_7 = printf("Encrypt test fail. Expected %d, got %d", out_enc_statemt[i], statemt[i]);
            int decomp_8;
            decomp_8 = main_result + 1;
            main_result = decomp_8;
        }
    }

    return 0;
    // main_result += isDiff;
    // main_result += (statemt[i] != out_enc_statemt[i]);
}

int decrypt(int statemt[32], int key[32], int key_type)
{
    int i;
    int const out_dec_statemt[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x7, 0x34};
    int decomp_9;
    decomp_9 = KeySchedule(key_type, key);
#pragma clava begin_outline
    /*
    +--------------------------------------------------------------------------+
    | * Test Vector (added for CHStone)                                        |
    |     out_enc_statemt : expected output data for "decrypt"                 |
    +--------------------------------------------------------------------------+
    */
    switch (key_type)
    {
    case 128128:;
        round_var = 10;
        nb = 4;
        break;
    case 128192:;
    case 192192:;
        round_var = 12;
        nb = 6;
        break;
    case 192128:;
        round_var = 12;
        nb = 4;
        break;
    case 128256:;
    case 192256:;
        round_var = 14;
        nb = 8;
        break;
    case 256128:;
        round_var = 14;
        nb = 4;
        break;
    case 256192:;
        round_var = 14;
        nb = 6;
        break;
    case 256256:;
        round_var = 14;
        nb = 8;
        break;
    }
#pragma clava end_outline
    int decomp_10;
    decomp_10 = AddRoundKey(statemt, key_type, round_var);
    InversShiftRow_ByteSub(statemt, nb);
    for (i = round_var - 1; i >= 1; --i)
    {
        int decomp_12;
        decomp_12 = AddRoundKey_InversMixColumn(statemt, nb, i);
        InversShiftRow_ByteSub(statemt, nb);
    }
    int decomp_14;
    decomp_14 = AddRoundKey(statemt, key_type, 0);
// printf ("\ndecrypto message\t");
// for (i = 0; i < ((key_type % 1000) / 8); ++i)
// {
// if (statemt[i] < 16)
// printf ("0");
// printf ("%x", statemt[i]);
// }
#pragma clava begin_outline
    for (i = 0; i < 16; i++)
    {
        int decomp_1;
        int decomp_15;
        decomp_15 = statemt[i] != out_dec_statemt[i];
        decomp_1 = decomp_15;
        if (decomp_1)
        {
            int decomp_16;
            decomp_16 = printf("Decrypt test fail. Expected %d, got %d", out_dec_statemt[i], statemt[i]);
            int decomp_17;
            decomp_17 = main_result + 1;
            main_result = decomp_17;
        }
    }
#pragma clava end_outline

    return 0;
}

int const Rcon0[30] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91};
/***************** key expand *************************/
int KeySchedule(int key_type, int key[32])
{
#pragma clava begin_outline
    int nk;
    int nb;
    int round_var;
    int i;
    int j;
    int temp[4];
    switch (key_type)
    {
    case 128128:;
        nk = 4;
        nb = 4;
        round_var = 10;
        break;
    case 128192:;
        nk = 4;
        nb = 6;
        round_var = 12;
        break;
    case 128256:;
        nk = 4;
        nb = 8;
        round_var = 14;
        break;
    case 192128:;
        nk = 6;
        nb = 4;
        round_var = 12;
        break;
    case 192192:;
        nk = 6;
        nb = 6;
        round_var = 12;
        break;
    case 192256:;
        nk = 6;
        nb = 8;
        round_var = 14;
        break;
    case 256128:;
        nk = 8;
        nb = 4;
        round_var = 14;
        break;
    case 256192:;
        nk = 8;
        nb = 6;
        round_var = 14;
        break;
    case 256256:;
        nk = 8;
        nb = 8;
        round_var = 14;
        break;
    }
    for (j = 0; j < nk; ++j)
    {
        for (i = 0; i < 4; ++i)
        {
            word[i][j] = key[i + j * 4];
            /*0 word*/
        }
    }
#pragma clava end_outline
    /*expanded key is generated*/
    for (j = nk; j < nb * (round_var + 1); ++j)
    {
        int decomp_2;
        int decomp_18;
        decomp_18 = (j % nk) == 0;
        decomp_2 = decomp_18;
        /*RotByte*/
        if (decomp_2)
        {
            int decomp_19;
            decomp_19 = SubByte(word[1][j - 1]);
            int decomp_20;
            decomp_20 = decomp_19 ^ Rcon0[(j / nk) - 1];
            temp[0] = decomp_20;
            int decomp_21;
            decomp_21 = SubByte(word[2][j - 1]);
            temp[1] = decomp_21;
            int decomp_22;
            decomp_22 = SubByte(word[3][j - 1]);
            temp[2] = decomp_22;
            int decomp_23;
            decomp_23 = SubByte(word[0][j - 1]);
            temp[3] = decomp_23;
        }
        int decomp_3;
        int decomp_24;
        decomp_24 = (j % nk) != 0;
        decomp_3 = decomp_24;
        if (decomp_3)
        {
            temp[0] = word[0][j - 1];
            temp[1] = word[1][j - 1];
            temp[2] = word[2][j - 1];
            temp[3] = word[3][j - 1];
        }
        int decomp_4;
        int decomp_25;
        decomp_25 = nk > 6;
        decomp_4 = decomp_25;
        int decomp_5;
        int decomp_26;
        decomp_26 = j % nk;
        decomp_5 = decomp_26;
        int decomp_6;
        int decomp_27;
        decomp_27 = decomp_5 == 4;
        decomp_6 = decomp_27;
        int decomp_7;
        int decomp_28;
        decomp_28 = decomp_4 && decomp_6;
        decomp_7 = decomp_28;
        if (decomp_7)
            for (i = 0; i < 4; ++i)
            {
                int decomp_29;
                decomp_29 = SubByte(temp[i]);
                temp[i] = decomp_29;
            }
        for (i = 0; i < 4; ++i)
        {
            int decomp_30;
            decomp_30 = word[i][j - nk] ^ temp[i];
            word[i][j] = decomp_30;
        }
    }

    return 0;
}

int const Sbox[16][16] = {{0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76}, {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0}, {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15}, {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75}, {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84}, {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf}, {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8}, {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2}, {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73}, {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb}, {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79}, {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08}, {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a}, {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e}, {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf}, {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}};
int const invSbox[16][16] = {{0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb}, {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb}, {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e}, {0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25}, {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92}, {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84}, {0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06}, {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b}, {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73}, {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e}, {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b}, {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4}, {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f}, {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef}, {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61}, {0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}};
/********** ByteSub & ShiftRow **********/
void ByteSub_ShiftRow(int statemt[32], int nb)
{
    int temp;
    switch (nb)
    {
    case 4:;
        temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = temp;
        temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = temp;
        temp = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = temp;
        temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = temp;
        statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
        break;
    case 6:;
        temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = Sbox[statemt[17] >> 4][statemt[17] & 0xf];
        statemt[17] = Sbox[statemt[21] >> 4][statemt[21] & 0xf];
        statemt[21] = temp;
        temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = Sbox[statemt[18] >> 4][statemt[18] & 0xf];
        statemt[18] = temp;
        temp = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = Sbox[statemt[22] >> 4][statemt[22] & 0xf];
        statemt[22] = temp;
        temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = temp;
        temp = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = Sbox[statemt[19] >> 4][statemt[19] & 0xf];
        statemt[19] = temp;
        temp = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = Sbox[statemt[23] >> 4][statemt[23] & 0xf];
        statemt[23] = temp;
        statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
        statemt[16] = Sbox[statemt[16] >> 4][statemt[16] & 0xf];
        statemt[20] = Sbox[statemt[20] >> 4][statemt[20] & 0xf];
        break;
    case 8:;
        temp = Sbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = Sbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = Sbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = Sbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = Sbox[statemt[17] >> 4][statemt[17] & 0xf];
        statemt[17] = Sbox[statemt[21] >> 4][statemt[21] & 0xf];
        statemt[21] = Sbox[statemt[25] >> 4][statemt[25] & 0xf];
        statemt[25] = Sbox[statemt[29] >> 4][statemt[29] & 0xf];
        statemt[29] = temp;
        temp = Sbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = Sbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = Sbox[statemt[26] >> 4][statemt[26] & 0xf];
        statemt[26] = Sbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = Sbox[statemt[18] >> 4][statemt[18] & 0xf];
        statemt[18] = Sbox[statemt[30] >> 4][statemt[30] & 0xf];
        statemt[30] = Sbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = Sbox[statemt[22] >> 4][statemt[22] & 0xf];
        statemt[22] = temp;
        temp = Sbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = Sbox[statemt[19] >> 4][statemt[19] & 0xf];
        statemt[19] = temp;
        temp = Sbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = Sbox[statemt[23] >> 4][statemt[23] & 0xf];
        statemt[23] = temp;
        temp = Sbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = Sbox[statemt[27] >> 4][statemt[27] & 0xf];
        statemt[27] = temp;
        temp = Sbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = Sbox[statemt[31] >> 4][statemt[31] & 0xf];
        statemt[31] = temp;
        statemt[0] = Sbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = Sbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = Sbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = Sbox[statemt[12] >> 4][statemt[12] & 0xf];
        statemt[16] = Sbox[statemt[16] >> 4][statemt[16] & 0xf];
        statemt[20] = Sbox[statemt[20] >> 4][statemt[20] & 0xf];
        statemt[24] = Sbox[statemt[24] >> 4][statemt[24] & 0xf];
        statemt[28] = Sbox[statemt[28] >> 4][statemt[28] & 0xf];
        break;
    }
}

int SubByte(int in)
{

    return Sbox[(in / 16)][(in % 16)];
}

/********** InversShiftRow & ByteSub **********/
void InversShiftRow_ByteSub(int statemt[32], int nb)
{
    int temp;
    switch (nb)
    {
    case 4:;
        temp = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = temp;
        temp = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = temp;
        temp = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = temp;
        temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = temp;
        statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
        break;
    case 6:;
        temp = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
        statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
        statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = temp;
        temp = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
        statemt[22] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = temp;
        temp = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
        statemt[18] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = temp;
        temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = temp;
        temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
        statemt[19] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = temp;
        temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
        statemt[23] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = temp;
        statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
        statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
        statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
        break;
    case 8:;
        temp = invSbox[statemt[29] >> 4][statemt[29] & 0xf];
        statemt[29] = invSbox[statemt[25] >> 4][statemt[25] & 0xf];
        statemt[25] = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
        statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
        statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
        statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
        statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
        statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
        statemt[1] = temp;
        temp = invSbox[statemt[30] >> 4][statemt[30] & 0xf];
        statemt[30] = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
        statemt[18] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
        statemt[6] = invSbox[statemt[26] >> 4][statemt[26] & 0xf];
        statemt[26] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
        statemt[14] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
        statemt[2] = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
        statemt[22] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
        statemt[10] = temp;
        temp = invSbox[statemt[31] >> 4][statemt[31] & 0xf];
        statemt[31] = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
        statemt[15] = temp;
        temp = invSbox[statemt[27] >> 4][statemt[27] & 0xf];
        statemt[27] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
        statemt[11] = temp;
        temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
        statemt[23] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
        statemt[7] = temp;
        temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
        statemt[19] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
        statemt[3] = temp;
        statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
        statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
        statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
        statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
        statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
        statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
        statemt[24] = invSbox[statemt[24] >> 4][statemt[24] & 0xf];
        statemt[28] = invSbox[statemt[28] >> 4][statemt[28] & 0xf];
        break;
    }
}

/********* MixColumn ***********/
int MixColumn_AddRoundKey(int statemt[32], int nb, int n)
{
    int ret[32];
    int j;
    register int x;
    for (j = 0; j < nb; ++j)
    {
        ret[j * 4] = (statemt[j * 4] << 1);
        int decomp_8;
        int decomp_31;
        decomp_31 = (ret[j * 4] >> 8) == 1;
        decomp_8 = decomp_31;
        if (decomp_8)
        {
            int decomp_32;
            decomp_32 = ret[j * 4] ^ 283;
            ret[j * 4] = decomp_32;
        }
        x = statemt[1 + j * 4];
        int decomp_33;
        decomp_33 = x ^ (x << 1);
        x = decomp_33;
        int decomp_9;
        int decomp_34;
        decomp_34 = (x >> 8) == 1;
        decomp_9 = decomp_34;
        if (decomp_9)
        {
            int decomp_35;
            decomp_35 = ret[j * 4] ^ (x ^ 283);
            ret[j * 4] = decomp_35;
        }
        else
        {
            int decomp_36;
            decomp_36 = ret[j * 4] ^ x;
            ret[j * 4] = decomp_36;
        }
        int decomp_37;
        decomp_37 = statemt[2 + j * 4] ^ statemt[3 + j * 4];
        int decomp_38;
        decomp_38 = decomp_37 ^ word[0][j + nb * n];
        int decomp_39;
        decomp_39 = ret[j * 4] ^ decomp_38;
        ret[j * 4] = decomp_39;
        ret[1 + j * 4] = (statemt[1 + j * 4] << 1);
        int decomp_10;
        int decomp_40;
        decomp_40 = (ret[1 + j * 4] >> 8) == 1;
        decomp_10 = decomp_40;
        if (decomp_10)
        {
            int decomp_41;
            decomp_41 = ret[1 + j * 4] ^ 283;
            ret[1 + j * 4] = decomp_41;
        }
        x = statemt[2 + j * 4];
        int decomp_42;
        decomp_42 = x ^ (x << 1);
        x = decomp_42;
        int decomp_11;
        int decomp_43;
        decomp_43 = (x >> 8) == 1;
        decomp_11 = decomp_43;
        if (decomp_11)
        {
            int decomp_44;
            decomp_44 = ret[1 + j * 4] ^ (x ^ 283);
            ret[1 + j * 4] = decomp_44;
        }
        else
        {
            int decomp_45;
            decomp_45 = ret[1 + j * 4] ^ x;
            ret[1 + j * 4] = decomp_45;
        }
        int decomp_46;
        decomp_46 = statemt[3 + j * 4] ^ statemt[j * 4];
        int decomp_47;
        decomp_47 = decomp_46 ^ word[1][j + nb * n];
        int decomp_48;
        decomp_48 = ret[1 + j * 4] ^ decomp_47;
        ret[1 + j * 4] = decomp_48;
        ret[2 + j * 4] = (statemt[2 + j * 4] << 1);
        int decomp_12;
        int decomp_49;
        decomp_49 = (ret[2 + j * 4] >> 8) == 1;
        decomp_12 = decomp_49;
        if (decomp_12)
        {
            int decomp_50;
            decomp_50 = ret[2 + j * 4] ^ 283;
            ret[2 + j * 4] = decomp_50;
        }
        x = statemt[3 + j * 4];
        int decomp_51;
        decomp_51 = x ^ (x << 1);
        x = decomp_51;
        int decomp_13;
        int decomp_52;
        decomp_52 = (x >> 8) == 1;
        decomp_13 = decomp_52;
        if (decomp_13)
        {
            int decomp_53;
            decomp_53 = ret[2 + j * 4] ^ (x ^ 283);
            ret[2 + j * 4] = decomp_53;
        }
        else
        {
            int decomp_54;
            decomp_54 = ret[2 + j * 4] ^ x;
            ret[2 + j * 4] = decomp_54;
        }
        int decomp_55;
        decomp_55 = statemt[j * 4] ^ statemt[1 + j * 4];
        int decomp_56;
        decomp_56 = decomp_55 ^ word[2][j + nb * n];
        int decomp_57;
        decomp_57 = ret[2 + j * 4] ^ decomp_56;
        ret[2 + j * 4] = decomp_57;
        ret[3 + j * 4] = (statemt[3 + j * 4] << 1);
        int decomp_14;
        int decomp_58;
        decomp_58 = (ret[3 + j * 4] >> 8) == 1;
        decomp_14 = decomp_58;
        if (decomp_14)
        {
            int decomp_59;
            decomp_59 = ret[3 + j * 4] ^ 283;
            ret[3 + j * 4] = decomp_59;
        }
        x = statemt[j * 4];
        int decomp_60;
        decomp_60 = x ^ (x << 1);
        x = decomp_60;
        int decomp_15;
        int decomp_61;
        decomp_61 = (x >> 8) == 1;
        decomp_15 = decomp_61;
        if (decomp_15)
        {
            int decomp_62;
            decomp_62 = ret[3 + j * 4] ^ (x ^ 283);
            ret[3 + j * 4] = decomp_62;
        }
        else
        {
            int decomp_63;
            decomp_63 = ret[3 + j * 4] ^ x;
            ret[3 + j * 4] = decomp_63;
        }
        int decomp_64;
        decomp_64 = statemt[1 + j * 4] ^ statemt[2 + j * 4];
        int decomp_65;
        decomp_65 = decomp_64 ^ word[3][j + nb * n];
        int decomp_66;
        decomp_66 = ret[3 + j * 4] ^ decomp_65;
        ret[3 + j * 4] = decomp_66;
    }
    for (j = 0; j < nb; ++j)
    {
        statemt[j * 4] = ret[j * 4];
        statemt[1 + j * 4] = ret[1 + j * 4];
        statemt[2 + j * 4] = ret[2 + j * 4];
        statemt[3 + j * 4] = ret[3 + j * 4];
    }

    return 0;
}

/********* InversMixColumn ***********/
int AddRoundKey_InversMixColumn(int statemt[32], int nb, int n)
{
    int ret[32];
    int i;
    int j;
    register int x;
    for (j = 0; j < nb; ++j)
    {
        int decomp_67;
        decomp_67 = statemt[j * 4] ^ word[0][j + nb * n];
        statemt[j * 4] = decomp_67;
        int decomp_68;
        decomp_68 = statemt[1 + j * 4] ^ word[1][j + nb * n];
        statemt[1 + j * 4] = decomp_68;
        int decomp_69;
        decomp_69 = statemt[2 + j * 4] ^ word[2][j + nb * n];
        statemt[2 + j * 4] = decomp_69;
        int decomp_70;
        decomp_70 = statemt[3 + j * 4] ^ word[3][j + nb * n];
        statemt[3 + j * 4] = decomp_70;
    }
    for (j = 0; j < nb; ++j)
        for (i = 0; i < 4; ++i)
        {
            x = (statemt[i + j * 4] << 1);
            int decomp_16;
            int decomp_71;
            decomp_71 = (x >> 8) == 1;
            decomp_16 = decomp_71;
            if (decomp_16)
            {
                int decomp_72;
                decomp_72 = x ^ 283;
                x = decomp_72;
            }
            int decomp_73;
            decomp_73 = x ^ statemt[i + j * 4];
            x = decomp_73;
            x = (x << 1);
            int decomp_17;
            int decomp_74;
            decomp_74 = (x >> 8) == 1;
            decomp_17 = decomp_74;
            if (decomp_17)
            {
                int decomp_75;
                decomp_75 = x ^ 283;
                x = decomp_75;
            }
            int decomp_76;
            decomp_76 = x ^ statemt[i + j * 4];
            x = decomp_76;
            x = (x << 1);
            int decomp_18;
            int decomp_77;
            decomp_77 = (x >> 8) == 1;
            decomp_18 = decomp_77;
            if (decomp_18)
            {
                int decomp_78;
                decomp_78 = x ^ 283;
                x = decomp_78;
            }
            ret[i + j * 4] = x;
            x = (statemt[(i + 1) % 4 + j * 4] << 1);
            int decomp_19;
            int decomp_79;
            decomp_79 = (x >> 8) == 1;
            decomp_19 = decomp_79;
            if (decomp_19)
            {
                int decomp_80;
                decomp_80 = x ^ 283;
                x = decomp_80;
            }
            x = (x << 1);
            int decomp_20;
            int decomp_81;
            decomp_81 = (x >> 8) == 1;
            decomp_20 = decomp_81;
            if (decomp_20)
            {
                int decomp_82;
                decomp_82 = x ^ 283;
                x = decomp_82;
            }
            int decomp_83;
            decomp_83 = x ^ statemt[(i + 1) % 4 + j * 4];
            x = decomp_83;
            x = (x << 1);
            int decomp_21;
            int decomp_84;
            decomp_84 = (x >> 8) == 1;
            decomp_21 = decomp_84;
            if (decomp_21)
            {
                int decomp_85;
                decomp_85 = x ^ 283;
                x = decomp_85;
            }
            int decomp_86;
            decomp_86 = x ^ statemt[(i + 1) % 4 + j * 4];
            x = decomp_86;
            int decomp_87;
            decomp_87 = ret[i + j * 4] ^ x;
            ret[i + j * 4] = decomp_87;
            x = (statemt[(i + 2) % 4 + j * 4] << 1);
            int decomp_22;
            int decomp_88;
            decomp_88 = (x >> 8) == 1;
            decomp_22 = decomp_88;
            if (decomp_22)
            {
                int decomp_89;
                decomp_89 = x ^ 283;
                x = decomp_89;
            }
            int decomp_90;
            decomp_90 = x ^ statemt[(i + 2) % 4 + j * 4];
            x = decomp_90;
            x = (x << 1);
            int decomp_23;
            int decomp_91;
            decomp_91 = (x >> 8) == 1;
            decomp_23 = decomp_91;
            if (decomp_23)
            {
                int decomp_92;
                decomp_92 = x ^ 283;
                x = decomp_92;
            }
            x = (x << 1);
            int decomp_24;
            int decomp_93;
            decomp_93 = (x >> 8) == 1;
            decomp_24 = decomp_93;
            if (decomp_24)
            {
                int decomp_94;
                decomp_94 = x ^ 283;
                x = decomp_94;
            }
            int decomp_95;
            decomp_95 = x ^ statemt[(i + 2) % 4 + j * 4];
            x = decomp_95;
            int decomp_96;
            decomp_96 = ret[i + j * 4] ^ x;
            ret[i + j * 4] = decomp_96;
            x = (statemt[(i + 3) % 4 + j * 4] << 1);
            int decomp_25;
            int decomp_97;
            decomp_97 = (x >> 8) == 1;
            decomp_25 = decomp_97;
            if (decomp_25)
            {
                int decomp_98;
                decomp_98 = x ^ 283;
                x = decomp_98;
            }
            x = (x << 1);
            int decomp_26;
            int decomp_99;
            decomp_99 = (x >> 8) == 1;
            decomp_26 = decomp_99;
            if (decomp_26)
            {
                int decomp_100;
                decomp_100 = x ^ 283;
                x = decomp_100;
            }
            x = (x << 1);
            int decomp_27;
            int decomp_101;
            decomp_101 = (x >> 8) == 1;
            decomp_27 = decomp_101;
            if (decomp_27)
            {
                int decomp_102;
                decomp_102 = x ^ 283;
                x = decomp_102;
            }
            int decomp_103;
            decomp_103 = x ^ statemt[(i + 3) % 4 + j * 4];
            x = decomp_103;
            int decomp_104;
            decomp_104 = ret[i + j * 4] ^ x;
            ret[i + j * 4] = decomp_104;
        }
    for (i = 0; i < nb; ++i)
    {
        statemt[i * 4] = ret[i * 4];
        statemt[1 + i * 4] = ret[1 + i * 4];
        statemt[2 + i * 4] = ret[2 + i * 4];
        statemt[3 + i * 4] = ret[3 + i * 4];
    }

    return 0;
}

/********* AddRoundKey ***********/
int AddRoundKey(int statemt[32], int key_type, int n)
{
    int j;
    int nb;
    switch (key_type)
    {
    case 128128:;
    case 192128:;
    case 256128:;
        nb = 4;
        break;
    case 128192:;
    case 192192:;
    case 256192:;
        nb = 6;
        break;
    case 128256:;
    case 192256:;
    case 256256:;
        nb = 8;
        break;
    }
    for (j = 0; j < nb; ++j)
    {
        int decomp_105;
        decomp_105 = statemt[j * 4] ^ word[0][j + nb * n];
        statemt[j * 4] = decomp_105;
        int decomp_106;
        decomp_106 = statemt[1 + j * 4] ^ word[1][j + nb * n];
        statemt[1 + j * 4] = decomp_106;
        int decomp_107;
        decomp_107 = statemt[2 + j * 4] ^ word[2][j + nb * n];
        statemt[2 + j * 4] = decomp_107;
        int decomp_108;
        decomp_108 = statemt[3 + j * 4] ^ word[3][j + nb * n];
        statemt[3 + j * 4] = decomp_108;
    }

    return 0;
}

/****************** main *****************************/
int aes_main()
{
#pragma clava begin_outline
    statemt[0] = 50;
    statemt[1] = 67;
    statemt[2] = 246;
    statemt[3] = 168;
    statemt[4] = 136;
    statemt[5] = 90;
    statemt[6] = 48;
    statemt[7] = 141;
    statemt[8] = 49;
    statemt[9] = 49;
    statemt[10] = 152;
    statemt[11] = 162;
    statemt[12] = 224;
    statemt[13] = 55;
    statemt[14] = 7;
    statemt[15] = 52;
    key[0] = 43;
    key[1] = 126;
    key[2] = 21;
    key[3] = 22;
    key[4] = 40;
    key[5] = 174;
    key[6] = 210;
    key[7] = 166;
    key[8] = 171;
    key[9] = 247;
    key[10] = 21;
    key[11] = 136;
    key[12] = 9;
    key[13] = 207;
    key[14] = 79;
    key[15] = 60;
#pragma clava end_outline
    int decomp_109;
    decomp_109 = encrypt(statemt, key, 128128);
    int decomp_110;
    decomp_110 = decrypt(statemt, key, 128128);

    return 0;
    /*
    +--------------------------------------------------------------------------+
    | * Test Vectors (added for CHStone)                                       |
    |     statemt, key : input data                                            |
    +--------------------------------------------------------------------------+
    */
}

int main()
{
    main_result = 0;
    int decomp_111;
    decomp_111 = aes_main();

    return main_result;
#pragma kernel
    //  printf("\n%d\n", main_result);
}
