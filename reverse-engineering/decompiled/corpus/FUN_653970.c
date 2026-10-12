/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x653970; label: FUN_00653970
 */

float * FUN_00653970(int param_1,int param_2,float param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_1;
  if (*(short *)(param_1 + 0x186) <= *(short *)(param_1 + 0x18a)) {
    *(undefined2 *)(param_1 + 0x18a) = 0;
  }
  sVar1 = *(short *)(param_1 + 0x18a);
  if (*(char *)(param_2 + 0x2e) == '\a') {
    iVar3 = (int)sVar1 / 0xc;
    uVar4 = (int)sVar1 % 0xc;
  }
  else {
    uVar4 = (uint)sVar1;
    iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 0x1fU)) >> 5;
    uVar4 = uVar4 & 0x8000001f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
    }
  }
  pfVar6 = (float *)((uVar4 + 1) * 0x20 + *(int *)(param_1 + 0x100 + iVar3 * 4));
  *(short *)(param_1 + 0x18a) = sVar1 + 1;
  pfVar6[3] = param_3;
  *(float *)(param_1 + 0x324) = param_3;
  pfVar6[7] = 64.0 / *(float *)(param_2 + 0xa4);
  FUN_005b3830(&local_c,param_2 + 100,param_3 - *(float *)(param_1 + 0x1e0));
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_18 = (float)((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x58) -
                    (float10)*(float *)(param_2 + 0x58));
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_14 = (float)((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x5c) -
                    (float10)*(float *)(param_2 + 0x5c));
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_10 = (float)((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x60) -
                    (float10)*(float *)(param_2 + 0x60));
  FUN_005c11d0(&local_18,&local_18,param_1 + 0x80);
  *pfVar6 = local_c + local_18;
  pfVar6[1] = local_8 + local_14;
  pfVar6[2] = local_4 + local_10;
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_18 = (float)((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x4c) -
                    (float10)*(float *)(param_2 + 0x4c));
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_14 = (float)(((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x50) -
                     (float10)*(float *)(param_2 + 0x50)) + (float10)*(float *)(param_2 + 0x48));
  fVar9 = (float10)FUN_005b9d90(&DAT_00810900);
  local_10 = (float)((fVar9 + fVar9) * (float10)*(float *)(param_2 + 0x54) -
                    (float10)*(float *)(param_2 + 0x54));
  FUN_005c11d0(&local_18,&local_18,param_1 + 0x80);
  pfVar6[4] = local_18;
  pfVar6[5] = local_14;
  pfVar6[6] = local_10;
  if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
    (**(code **)(param_1 + 0x1c4))(param_1,param_2,pfVar6);
  }
  pfVar7 = (float *)(param_1 + 0x19c);
  param_1 = 0;
  *pfVar6 = *pfVar7 + *pfVar6;
  pfVar6[1] = *(float *)(iVar2 + 0x1a0) + pfVar6[1];
  pfVar6[2] = *(float *)(iVar2 + 0x1a4) + pfVar6[2];
  pfVar6[4] = *(float *)(iVar2 + 0x1a8) + pfVar6[4];
  pfVar6[5] = *(float *)(iVar2 + 0x1ac) + pfVar6[5];
  pfVar6[6] = *(float *)(iVar2 + 0x1b0) + pfVar6[6];
  if ('\0' < *(char *)(param_2 + 0x410)) {
    do {
      if (*(short *)(iVar2 + 0x186) <= *(short *)(iVar2 + 0x18a)) {
        *(undefined2 *)(iVar2 + 0x18a) = 0;
      }
      sVar1 = *(short *)(iVar2 + 0x18a);
      if (*(char *)(param_2 + 0x2e) == '\a') {
        iVar3 = (int)sVar1 / 0xc;
        uVar4 = (int)sVar1 % 0xc;
      }
      else {
        uVar4 = (uint)sVar1;
        iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar4 = uVar4 & 0x8000001f;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
        }
      }
      pfVar5 = (float *)((uVar4 + 1) * 0x20 + *(int *)(iVar2 + 0x100 + iVar3 * 4));
      *(short *)(iVar2 + 0x18a) = sVar1 + 1;
      param_1 = param_1 + 1;
      pfVar7 = pfVar6;
      pfVar8 = pfVar5;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar8 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar8 = pfVar8 + 1;
      }
      pfVar5[3] = (float)param_1 * *(float *)(param_2 + 0x414) + pfVar5[3];
    } while (param_1 < *(char *)(param_2 + 0x410));
  }
  if (*(int *)(param_2 + 0x2a8) == 0) {
    FUN_00600260(param_2);
  }
  return pfVar6;
}

