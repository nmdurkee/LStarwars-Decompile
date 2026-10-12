/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x682290; label: FUN_00682290
 */

float * FUN_00682290(float param_1,float param_2,float param_3)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST1;
  float local_14;
  int local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar2 = param_2;
  iVar1 = (int)param_1;
  if (*(short *)((int)param_1 + 0x186) <= *(short *)((int)param_1 + 0x18a)) {
    *(undefined2 *)((int)param_1 + 0x18a) = 0;
  }
  if (*(char *)((int)param_2 + 0x2e) != '\a') {
    uVar3 = (uint)*(short *)((int)param_1 + 0x18a);
    uVar4 = uVar3 & 0x8000001f;
    local_10 = *(int *)((int)param_1 + 0x100 +
                       ((int)(uVar3 + ((int)uVar3 >> 0x1f & 0x1fU)) >> 5) * 4);
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
    }
    iVar5 = (uVar4 + 1) * 0x20;
    *(float *)(iVar5 + 0xc + local_10) = param_3;
    pfVar6 = (float *)(iVar5 + local_10);
    *(float *)((int)param_1 + 0x324) = param_3;
    pfVar6[7] = 64.0 / *(float *)((int)param_2 + 0xa4);
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_c = (float)((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x58) -
                     (float10)*(float *)((int)fVar2 + 0x58));
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_8 = (float)((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x5c) -
                     (float10)*(float *)((int)fVar2 + 0x5c));
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_4 = (float)((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x60) -
                     (float10)*(float *)((int)fVar2 + 0x60));
    FUN_005c11d0(&local_c,&local_c,(int)param_1 + 0x80);
    *pfVar6 = local_c;
    pfVar6[1] = local_8;
    pfVar6[2] = local_4;
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_c = (float)((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x4c) -
                     (float10)*(float *)((int)fVar2 + 0x4c));
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_8 = (float)(((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x50) -
                      (float10)*(float *)((int)fVar2 + 0x50)) +
                     (float10)*(float *)((int)fVar2 + 0x48));
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    local_4 = (float)((fVar7 + fVar7) * (float10)*(float *)((int)fVar2 + 0x54) -
                     (float10)*(float *)((int)fVar2 + 0x54));
    FUN_005c11d0(&local_c,&local_c,(int)param_1 + 0x80);
    pfVar6[4] = local_c;
    pfVar6[5] = local_8;
    pfVar6[6] = local_4;
    iVar5 = FUN_00653840(*(undefined4 *)((int)fVar2 + 0xa0),pfVar6[5],
                         pfVar6[1] - *(float *)((int)param_1 + 0x2e0),&param_2,&local_14);
    if (iVar5 != 0) {
      if (param_2 <= local_14) {
        param_1 = local_14;
      }
      else {
        param_1 = param_2;
      }
      if (0.0 < param_1) {
        if (param_2 <= local_14) {
          param_1 = local_14;
        }
        else {
          param_1 = param_2;
        }
        if (param_1 < *(float *)((int)fVar2 + 0xa4)) {
          fVar7 = (float10)FUN_00653940();
          if (DAT_02947b70 < DAT_008108ec + DAT_008108e8) {
            **(int **)(DAT_02923198 + DAT_02947b70 * 4) = local_10;
            fVar8 = extraout_ST1;
            if (extraout_ST1 < fVar7) {
              fVar8 = fVar7;
            }
            param_1 = (float)fVar8;
            *(float *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 4) = param_1 + param_3;
            *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 8) = 5;
            *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = 0;
            *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x1c) =
                 *(undefined2 *)(iVar1 + 0x182);
            *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x20) = 0;
            *(undefined2 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x1e) = 0;
            *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x24) =
                 *(undefined4 *)(iVar1 + 0x2e0);
            *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x28) =
                 *(undefined4 *)(iVar1 + 0x2e4);
            uVar3 = (int)*(short *)(iVar1 + 0x18a) & 0x8000001f;
            if ((int)uVar3 < 0) {
              uVar3 = (uVar3 - 1 | 0xffffffe0) + 1;
            }
            *(uint *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x14) = uVar3;
            fVar8 = extraout_ST1;
            if (extraout_ST1 < fVar7) {
              fVar8 = fVar7;
            }
            *(float *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0x18) = (float)fVar8;
            FUN_006551d0(*(undefined4 *)(DAT_02923198 + DAT_02947b70 * 4),&DAT_0292fbfc);
            DAT_02947b70 = DAT_02947b70 + 1;
            DAT_02962058 = 0;
          }
          else {
            DAT_02962058 = 0;
          }
        }
      }
    }
    if (*(code **)(iVar1 + 0x1c4) != (code *)0x0) {
      (**(code **)(iVar1 + 0x1c4))(iVar1,fVar2,pfVar6);
    }
    *(short *)(iVar1 + 0x18a) = *(short *)(iVar1 + 0x18a) + 1;
    *pfVar6 = *(float *)(iVar1 + 0x19c) + *pfVar6;
    pfVar6[1] = *(float *)(iVar1 + 0x1a0) + pfVar6[1];
    pfVar6[2] = *(float *)(iVar1 + 0x1a4) + pfVar6[2];
    pfVar6[4] = *(float *)(iVar1 + 0x1a8) + pfVar6[4];
    pfVar6[5] = *(float *)(iVar1 + 0x1ac) + pfVar6[5];
    pfVar6[6] = *(float *)(iVar1 + 0x1b0) + pfVar6[6];
    if (*(int *)((int)fVar2 + 0x2a8) == 0) {
      FUN_00600260(fVar2);
    }
    return pfVar6;
  }
  return (float *)0x0;
}

