/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603f10; label: FUN_00603f10
 */

void FUN_00603f10(float *param_1,float *param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (3 < param_4) {
    iVar4 = (param_4 - 4U >> 2) + 1;
    iVar3 = iVar4 * 4;
    pfVar1 = param_2;
    pfVar2 = param_1;
    do {
      *pfVar2 = param_3[8] * pfVar1[2] + pfVar1[1] * param_3[4] + *pfVar1 * *param_3 + param_3[0xc];
      pfVar2[1] = param_3[9] * pfVar1[2] + param_3[5] * pfVar1[1] + *pfVar1 * param_3[1] +
                  param_3[0xd];
      pfVar2[2] = param_3[10] * pfVar1[2] + param_3[6] * pfVar1[1] + *pfVar1 * param_3[2] +
                  param_3[0xe];
      pfVar2[3] = pfVar1[5] * param_3[8] + pfVar1[4] * param_3[4] + *param_3 * pfVar1[3] +
                  param_3[0xc];
      pfVar2[4] = param_3[9] * pfVar1[5] + pfVar1[3] * param_3[1] + pfVar1[4] * param_3[5] +
                  param_3[0xd];
      pfVar2[5] = param_3[10] * pfVar1[5] + pfVar1[3] * param_3[2] + pfVar1[4] * param_3[6] +
                  param_3[0xe];
      pfVar2[6] = pfVar1[8] * param_3[8] + pfVar1[7] * param_3[4] + *param_3 * pfVar1[6] +
                  param_3[0xc];
      pfVar2[7] = pfVar1[8] * param_3[9] + pfVar1[6] * param_3[1] + pfVar1[7] * param_3[5] +
                  param_3[0xd];
      param_1 = pfVar2 + 0xc;
      param_2 = pfVar1 + 0xc;
      iVar4 = iVar4 + -1;
      pfVar2[8] = pfVar1[8] * param_3[10] + pfVar1[6] * param_3[2] + pfVar1[7] * param_3[6] +
                  param_3[0xe];
      pfVar2[9] = pfVar1[0xb] * param_3[8] + pfVar1[10] * param_3[4] + *param_3 * pfVar1[9] +
                  param_3[0xc];
      pfVar2[10] = pfVar1[0xb] * param_3[9] + pfVar1[9] * param_3[1] + pfVar1[10] * param_3[5] +
                   param_3[0xd];
      pfVar2[0xb] = pfVar1[0xb] * param_3[10] + pfVar1[9] * param_3[2] + pfVar1[10] * param_3[6] +
                    param_3[0xe];
      pfVar1 = param_2;
      pfVar2 = param_1;
    } while (iVar4 != 0);
  }
  if (iVar3 < param_4) {
    param_4 = param_4 - iVar3;
    do {
      param_4 = param_4 + -1;
      *param_1 = param_3[8] * param_2[2] + param_2[1] * param_3[4] + *param_2 * *param_3 +
                 param_3[0xc];
      param_1[1] = param_3[9] * param_2[2] + param_3[5] * param_2[1] + *param_2 * param_3[1] +
                   param_3[0xd];
      param_1[2] = param_3[10] * param_2[2] + param_3[6] * param_2[1] + *param_2 * param_3[2] +
                   param_3[0xe];
      param_2 = param_2 + 3;
      param_1 = param_1 + 3;
    } while (param_4 != 0);
  }
  return;
}

