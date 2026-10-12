/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c8540; label: FUN_005c8540
 */

void FUN_005c8540(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float local_24;
  
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  *param_3 = param_2[4] + *param_3;
  param_3[1] = param_2[5] + param_3[1];
  param_3[2] = param_2[6] + param_3[2];
  *param_3 = param_2[8] + *param_3;
  param_3[1] = param_2[9] + param_3[1];
  param_3[2] = param_2[10] + param_3[2];
  *param_3 = param_2[0xc] + *param_3;
  param_3[1] = param_2[0xd] + param_3[1];
  param_3[2] = param_2[0xe] + param_3[2];
  *param_3 = param_2[0x10] + *param_3;
  param_3[1] = param_2[0x11] + param_3[1];
  param_3[2] = param_2[0x12] + param_3[2];
  *param_3 = param_2[0x14] + *param_3;
  param_3[1] = param_2[0x15] + param_3[1];
  param_3[2] = param_2[0x16] + param_3[2];
  *param_3 = param_2[0x18] + *param_3;
  param_3[1] = param_2[0x19] + param_3[1];
  param_3[2] = param_2[0x1a] + param_3[2];
  *param_3 = param_2[0x1c] + *param_3;
  param_3[1] = param_2[0x1d] + param_3[1];
  param_3[2] = param_2[0x1e] + param_3[2];
  *param_3 = *param_3 * 0.125;
  param_2 = param_2 + 6;
  iVar5 = 2;
  param_3[1] = param_3[1] * 0.125;
  param_3[2] = param_3[2] * 0.125;
  *param_5 = 0.0;
  do {
    fVar1 = (param_3[2] - param_2[-4]) * (param_3[2] - param_2[-4]) +
            (param_3[1] - param_2[-5]) * (param_3[1] - param_2[-5]) +
            (*param_3 - param_2[-6]) * (*param_3 - param_2[-6]);
    if (*param_5 < fVar1) {
      *param_5 = fVar1;
    }
    fVar1 = (param_3[2] - *param_2) * (param_3[2] - *param_2) +
            (param_3[1] - param_2[-1]) * (param_3[1] - param_2[-1]) +
            (*param_3 - param_2[-2]) * (*param_3 - param_2[-2]);
    if (*param_5 < fVar1) {
      *param_5 = fVar1;
    }
    fVar1 = (param_3[2] - param_2[4]) * (param_3[2] - param_2[4]) +
            (param_3[1] - param_2[3]) * (param_3[1] - param_2[3]) +
            (*param_3 - param_2[2]) * (*param_3 - param_2[2]);
    if (*param_5 < fVar1) {
      *param_5 = fVar1;
    }
    fVar1 = (param_3[2] - param_2[8]) * (param_3[2] - param_2[8]) +
            (param_3[1] - param_2[7]) * (param_3[1] - param_2[7]) +
            (*param_3 - param_2[6]) * (*param_3 - param_2[6]);
    if (*param_5 < fVar1) {
      *param_5 = fVar1;
    }
    param_2 = param_2 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  fVar6 = (float10)FUN_005c0240(fVar1);
  *param_5 = (float)fVar6;
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  fVar3 = param_3[1];
  fVar4 = param_3[2];
  *param_4 = *param_3 - *param_1 * 100.0;
  param_4[1] = fVar3 - fVar1 * 100.0;
  param_4[2] = fVar4 - fVar2 * 100.0;
  param_4[3] = local_24;
  return;
}

