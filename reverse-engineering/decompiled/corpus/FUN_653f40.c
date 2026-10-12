/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x653f40; label: FUN_00653f40
 */

float * FUN_00653f40(int param_1,int param_2,float param_3)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  iVar1 = param_1;
  if (*(short *)(param_1 + 0x186) <= *(short *)(param_1 + 0x18a)) {
    *(undefined2 *)(param_1 + 0x18a) = 0;
  }
  if (*(char *)(param_2 + 0x2e) == '\a') {
    return (float *)0x0;
  }
  uVar7 = (uint)*(short *)(param_1 + 0x18a);
  uVar8 = uVar7 & 0x8000001f;
  if ((int)uVar8 < 0) {
    uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
  }
  pfVar9 = (float *)((uVar8 + 1) * 0x20 +
                    *(int *)(param_1 + 0x100 +
                            ((int)(uVar7 + ((int)uVar7 >> 0x1f & 0x1fU)) >> 5) * 4));
  *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + 1;
  pfVar9[3] = param_3;
  *(float *)(param_1 + 0x324) = param_3;
  pfVar9[7] = 64.0 / *(float *)(param_2 + 0xa4);
  FUN_005b3830(local_c,param_2 + 100,param_3 - *(float *)(param_1 + 0x1e0));
  FUN_005b37d0(local_c,local_c,param_2 + 0x58);
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  local_14 = local_c[0];
  local_10 = 0.0;
  local_18 = 0.0;
  FUN_005b3690(&local_18,&local_18,uVar4);
  FUN_005b3620(&local_18,&local_18,uVar3);
  FUN_005c11d0(&local_18,&local_18,param_1 + 0x80);
  *pfVar9 = local_18;
  pfVar9[1] = local_14;
  pfVar9[2] = local_10;
  fVar12 = (float10)FUN_005b9d90(&DAT_00810900);
  local_14 = (float)(((fVar12 + fVar12) * (float10)*(float *)(param_2 + 0x4c) -
                     (float10)*(float *)(param_2 + 0x4c)) + (float10)*(float *)(param_2 + 0x48));
  local_10 = 0.0;
  local_18 = 0.0;
  FUN_005b3690(&local_18,&local_18,uVar4);
  FUN_005b3620(&local_18,&local_18,uVar3);
  FUN_005c11d0(&local_18,&local_18,param_1 + 0x80);
  pfVar9[4] = local_18;
  pfVar9[5] = local_14;
  pfVar9[6] = local_10;
  if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
    (**(code **)(param_1 + 0x1c4))(param_1,param_2,pfVar9);
  }
  pfVar10 = (float *)(param_1 + 0x19c);
  param_1 = 0;
  *pfVar9 = *pfVar10 + *pfVar9;
  pfVar9[1] = *(float *)(iVar1 + 0x1a0) + pfVar9[1];
  pfVar9[2] = *(float *)(iVar1 + 0x1a4) + pfVar9[2];
  pfVar9[4] = *(float *)(iVar1 + 0x1a8) + pfVar9[4];
  pfVar9[5] = *(float *)(iVar1 + 0x1ac) + pfVar9[5];
  pfVar9[6] = *(float *)(iVar1 + 0x1b0) + pfVar9[6];
  if ('\0' < *(char *)(param_2 + 0x410)) {
    do {
      if (*(short *)(iVar1 + 0x186) <= *(short *)(iVar1 + 0x18a)) {
        *(undefined2 *)(iVar1 + 0x18a) = 0;
      }
      uVar8 = (uint)*(short *)(iVar1 + 0x18a);
      uVar7 = uVar8 & 0x8000001f;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xffffffe0) + 1;
      }
      pfVar5 = (float *)((uVar7 + 1) * 0x20 +
                        *(int *)(iVar1 + 0x100 +
                                ((int)(((int)uVar8 >> 0x1f & 0x1fU) + uVar8) >> 5) * 4));
      *(short *)(iVar1 + 0x18a) = *(short *)(iVar1 + 0x18a) + 1;
      pfVar10 = pfVar9;
      pfVar11 = pfVar5;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar11 = pfVar11 + 1;
      }
      param_1 = param_1 + 1;
      pfVar5[3] = (float)param_1 * *(float *)(param_2 + 0x414) + pfVar5[3];
    } while (param_1 < *(char *)(param_2 + 0x410));
  }
  if (*(int *)(param_2 + 0x2a8) == 0) {
    FUN_00600260(param_2);
  }
  fVar12 = (float10)0;
  if (fVar12 == (float10)*(float *)(param_2 + 0x50)) {
    *(undefined2 *)(iVar1 + 0x1d0) = 0;
  }
  else {
    sVar2 = FUN_006e6b90();
    *(short *)(iVar1 + 0x1d0) = *(short *)(iVar1 + 0x1d0) + sVar2;
    fVar12 = extraout_ST0;
  }
  if (fVar12 != (float10)*(float *)(param_2 + 0x54)) {
    sVar2 = FUN_006e6b90();
    *(short *)(iVar1 + 0x1d2) = *(short *)(iVar1 + 0x1d2) + sVar2;
    return pfVar9;
  }
  *(undefined2 *)(iVar1 + 0x1d2) = 0;
  return pfVar9;
}

