/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59a720; label: FUN_0059a720
 */

void FUN_0059a720(float param_1,float *param_2,float param_3,float param_4,byte *param_5,
                 byte *param_6,byte *param_7,byte *param_8)

{
  float fVar1;
  float fVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = param_5;
  iVar3 = (int)param_1;
  fVar1 = (*(float *)((int)param_1 + 0x150) - *(float *)((int)param_1 + 0x144)) * 0.015625;
  fVar2 = (*(float *)((int)param_1 + 0x158) - *(float *)((int)param_1 + 0x14c)) * 0.015625;
  if (param_5 != (byte *)0x0) {
    param_1 = (*param_2 - param_3) - *(float *)((int)param_1 + 0x144);
    if ((param_1 == 0.0) || (fVar1 == 0.0)) {
      param_1 = 0.0;
    }
    else {
      param_1 = param_1 / fVar1;
    }
    param_5._0_1_ = (byte)(int)ROUND(param_1);
    *pbVar4 = (byte)param_5;
    if (0x3f < (byte)param_5) {
      *pbVar4 = 0x3f;
    }
  }
  if (param_7 != (byte *)0x0) {
    param_1 = (*param_2 + param_3) - *(float *)(iVar3 + 0x144);
    if ((param_1 == 0.0) || (fVar1 == 0.0)) {
      param_1 = 0.0;
    }
    else {
      param_1 = param_1 / fVar1;
    }
    param_5._0_1_ = (byte)(int)ROUND(param_1);
    *param_7 = (byte)param_5;
    if (0x3f < (byte)param_5) {
      *param_7 = 0x3f;
    }
  }
  if (param_6 != (byte *)0x0) {
    param_1 = (param_2[2] - param_4) - *(float *)(iVar3 + 0x14c);
    if ((param_1 == 0.0) || (fVar2 == 0.0)) {
      param_1 = 0.0;
    }
    else {
      param_1 = param_1 / fVar2;
    }
    param_5._0_1_ = (byte)(int)ROUND(param_1);
    *param_6 = (byte)param_5;
    if (0x3f < (byte)param_5) {
      *param_6 = 0x3f;
    }
  }
  if (param_8 != (byte *)0x0) {
    fVar1 = (param_2[2] + param_4) - *(float *)(iVar3 + 0x14c);
    if ((fVar1 == 0.0) || (fVar2 == 0.0)) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = fVar1 / fVar2;
    }
    param_5._0_1_ = (byte)(int)ROUND(fVar1);
    *param_8 = (byte)param_5;
    if (0x3f < (byte)param_5) {
      *param_8 = 0x3f;
      return;
    }
  }
  return;
}

