/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c9b60; label: FUN_005c9b60
 */

void FUN_005c9b60(float *param_1,float param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  
  if (*param_1 < param_2 == (*param_1 == param_2)) {
    if (param_2 < 1.0) {
      param_2 = 1.0;
    }
  }
  else {
    if (*param_1 == 1.0) {
      *param_3 = 1.0;
      param_3[2] = 0.0;
      param_3[4] = 0.0;
      param_3[3] = 1.4013e-45;
      return;
    }
    param_2 = *param_1 - 0.01;
  }
  *param_3 = param_2;
  iVar1 = FUN_006e6b90();
  fVar2 = (float)(iVar1 + -1 >> 5);
  param_3[2] = fVar2;
  if ((int)param_1[2] <= (int)fVar2) {
    param_3[2] = (float)((int)param_1[2] + -1);
  }
  fVar2 = *param_3 - (float)((int)param_3[2] << 5);
  param_3[1] = fVar2;
  FUN_005b7cc0(fVar2);
  iVar1 = FUN_006e6b90();
  fVar2 = (float)(iVar1 + -1);
  param_3[5] = fVar2;
  uVar3 = (uint)fVar2 & 0x80000007;
  param_3[4] = (float)((int)((int)fVar2 + ((int)fVar2 >> 0x1f & 7U)) >> 3 & 0xff);
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
  }
  param_3[3] = (float)(uint)(byte)(('\x01' << ((char)uVar3 + 1U & 0x1f)) - 1);
  return;
}

