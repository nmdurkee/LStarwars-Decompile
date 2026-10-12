/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x6826a0; label: FUN_006826a0
 */

float * FUN_006826a0(int param_1,int param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float local_48;
  float local_44;
  float local_40;
  float local_3c [4];
  undefined4 local_2c;
  float local_28;
  undefined1 local_24 [12];
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  local_3c[0] = 1.0;
  local_3c[1] = 0.0;
  local_3c[2] = 0.0;
  if (*(short *)(param_1 + 0x186) <= *(short *)(param_1 + 0x18a)) {
    *(undefined2 *)(param_1 + 0x18a) = 0;
  }
  if (*(char *)(param_2 + 0x2e) != '\a') {
    uVar4 = (uint)*(short *)(param_1 + 0x18a);
    uVar5 = uVar4 & 0x8000001f;
    iVar1 = *(int *)(param_1 + 0x100 + ((int)(uVar4 + ((int)uVar4 >> 0x1f & 0x1fU)) >> 5) * 4);
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xffffffe0) + 1;
    }
    iVar6 = (uVar5 + 1) * 0x20;
    *(float *)(iVar6 + 0xc + iVar1) = param_3;
    pfVar7 = (float *)(iVar6 + iVar1);
    *(float *)(param_1 + 0x324) = param_3;
    pfVar7[7] = 64.0 / *(float *)(param_2 + 0xa4);
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_48 = (float)((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x58) -
                      (float10)*(float *)(param_2 + 0x58));
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_44 = (float)((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x5c) -
                      (float10)*(float *)(param_2 + 0x5c));
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_40 = (float)((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x60) -
                      (float10)*(float *)(param_2 + 0x60));
    FUN_005c11d0(&local_48,&local_48,param_1 + 0x80);
    *pfVar7 = local_48;
    pfVar7[1] = local_44;
    pfVar7[2] = local_40;
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_48 = (float)((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x4c) -
                      (float10)*(float *)(param_2 + 0x4c));
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_44 = (float)(((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x50) -
                       (float10)*(float *)(param_2 + 0x50)) + (float10)*(float *)(param_2 + 0x48));
    fVar8 = (float10)FUN_005b9d90(&DAT_00810900);
    local_40 = (float)((fVar8 + fVar8) * (float10)*(float *)(param_2 + 0x54) -
                      (float10)*(float *)(param_2 + 0x54));
    FUN_005c11d0(&local_48,&local_48,param_1 + 0x80);
    pfVar7[4] = local_48;
    pfVar7[5] = local_44;
    pfVar7[6] = local_40;
    FUN_005b3620(local_3c,local_3c,(int)*(short *)(param_1 + 0x2de));
    FUN_005b3830(local_24,local_3c,*(undefined4 *)(param_1 + 0x2e0));
    local_3c[3] = pfVar7[4] * *(float *)(param_2 + 0xa4) + *pfVar7;
    local_2c = 0;
    local_28 = pfVar7[6] * *(float *)(param_2 + 0xa4) + pfVar7[2];
    FUN_005b3800(local_18,local_24,pfVar7);
    FUN_005b3800(local_c,local_24,local_3c + 3);
    fVar2 = local_3c[2] * local_10 + local_3c[0] * local_18[0];
    fVar3 = local_3c[2] * local_4 + local_c[0] * local_3c[0];
    if (((fVar2 < 0.0) && (0.0 < fVar3)) || ((0.0 < fVar2 && (fVar3 < 0.0)))) {
      fVar2 = ((0.0 - fVar2) / (fVar3 - fVar2)) * *(float *)(param_2 + 0xa4);
      do {
      } while (DAT_02962058 != 0);
      DAT_02962058 = 1;
      if (DAT_02947b70 < DAT_008108ec + DAT_008108e8) {
        **(int **)(DAT_02923198 + DAT_02947b70 * 4) = iVar1;
        *(float *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 4) = fVar2 + param_3;
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 8) = 6;
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = 0;
        *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x1c) =
             *(undefined2 *)(param_1 + 0x182);
        *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x20) =
             *(undefined2 *)(param_1 + 0x2de);
        *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x1e) = 0;
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x24) =
             *(undefined4 *)(param_1 + 0x2e0);
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x28) =
             *(undefined4 *)(param_1 + 0x2e4);
        uVar4 = (int)*(short *)(param_1 + 0x18a) & 0x8000001f;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
        }
        *(uint *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x14) = uVar4;
        *(float *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x18) = fVar2;
        FUN_006551d0(*(undefined4 *)(DAT_02923198 + DAT_02947b70 * 4),&DAT_0292fbfc);
        DAT_02947b70 = DAT_02947b70 + 1;
      }
      DAT_02962058 = 0;
    }
    if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c4))(param_1,param_2,pfVar7);
    }
    *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + 1;
    *pfVar7 = *(float *)(param_1 + 0x19c) + *pfVar7;
    pfVar7[1] = *(float *)(param_1 + 0x1a0) + pfVar7[1];
    pfVar7[2] = *(float *)(param_1 + 0x1a4) + pfVar7[2];
    pfVar7[4] = *(float *)(param_1 + 0x1a8) + pfVar7[4];
    pfVar7[5] = *(float *)(param_1 + 0x1ac) + pfVar7[5];
    pfVar7[6] = *(float *)(param_1 + 0x1b0) + pfVar7[6];
    if (*(int *)(param_2 + 0x2a8) == 0) {
      FUN_00600260(param_2);
    }
    return pfVar7;
  }
  return (float *)0x0;
}

