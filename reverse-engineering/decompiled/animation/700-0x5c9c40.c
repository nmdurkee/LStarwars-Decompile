
void FUN_005c9c40(float *param_1,float param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  
  if (((int)*param_1 < 0x414e4934) || (0x414e4935 < (int)*param_1)) {
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
    iVar2 = FUN_006e6b90();
    fVar3 = (float)(iVar2 + -1 >> 5);
    param_3[2] = fVar3;
    if ((int)*(short *)(param_1 + 2) <= (int)fVar3) {
      param_3[2] = (float)(*(short *)(param_1 + 2) + -1);
    }
    fVar3 = *param_3 - (float)((int)param_3[2] << 5);
    param_3[1] = fVar3;
    FUN_005b7cc0(fVar3);
    iVar2 = FUN_006e6b90();
    fVar3 = (float)(iVar2 + -1);
    param_3[5] = fVar3;
    uVar4 = (uint)fVar3 & 0x80000007;
    param_3[4] = (float)((int)((int)fVar3 + ((int)fVar3 >> 0x1f & 7U)) >> 3 & 0xff);
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    param_3[3] = (float)(uint)(byte)(('\x01' << ((char)uVar4 + 1U & 0x1f)) - 1);
    return;
  }
  fVar3 = 1.0;
  if ((1.0 <= param_2) &&
     (fVar1 = (float)*(ushort *)((int)param_1 + 10), fVar3 = param_2,
     fVar1 < param_2 != (fVar1 == param_2))) {
    *param_3 = fVar1 - 0.01;
    return;
  }
  *param_3 = fVar3;
  return;
}

