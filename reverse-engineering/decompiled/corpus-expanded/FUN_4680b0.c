/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x4680b0; label: FUN_004680b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004680b0(int param_1,float *param_2,float *param_3,undefined4 *param_4,int param_5,
                  float *param_6,undefined4 *param_7,float param_8,float param_9,int param_10,
                  int param_11,undefined4 param_12)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  ushort uVar7;
  float fVar8;
  ushort uVar9;
  float fVar10;
  float fVar11;
  int *piVar12;
  float *pfVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  float10 fVar17;
  float local_5c;
  int local_58;
  int *local_54;
  float *local_50;
  int *local_4c;
  float *local_48;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  iVar14 = FUN_005806a0(param_12,PTR_DAT_00802c54);
  fVar10 = _DAT_0087aa54;
  uVar9 = DAT_0087a958;
  fVar8 = _DAT_0087a930;
  uVar7 = DAT_0087a838;
  uVar6 = DAT_0087a834;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) && (iVar14 != 0)) {
    local_5c = 1e+09;
    local_30 = *param_7;
    local_2c = param_7[1];
    local_18 = *param_6 - param_8;
    local_28 = param_7[2];
    local_54 = (int *)0x0;
    local_4c = (int *)0x0;
    local_48 = (float *)0x0;
    local_10 = param_6[2] - param_8;
    local_50 = (float *)0x0;
    local_c = *param_6 + param_8;
    local_4 = param_8 + param_6[2];
    if ((param_10 != 0) && ((*(uint *)(iVar14 + 0x60) & 0x20000) != 0)) {
      local_2c = 0;
      FUN_005b3b30(&local_30,&local_30);
    }
    iVar3 = *(int *)(param_1 + 0x10);
    local_58 = 0;
    if (*(short *)(iVar3 + 0x12) != 0) {
      do {
        piVar4 = *(int **)(*(int *)(iVar3 + 8) + local_58 * 4);
        iVar5 = *piVar4;
        uVar16 = *(uint *)(iVar5 + 0xa0);
        fVar11 = local_5c;
        piVar12 = local_54;
        pfVar13 = local_50;
        if ((((uVar16 & 2) != 0) && ((uVar16 & 1) != 0)) &&
           (((uVar16 & 0x10000) == 0 &&
            ((((pfVar1 = (float *)(iVar5 + 0x1c), local_18 <= *(float *)(iVar5 + 0x1c) &&
               (*pfVar1 <= local_c)) && (local_10 <= *(float *)(iVar5 + 0x24))) &&
             (*(float *)(iVar5 + 0x24) <= local_4)))))) {
          if (param_11 == 0) {
            fVar17 = (float10)FUN_005b3c50(pfVar1,param_6,local_24);
          }
          else {
            fVar17 = (float10)FUN_005b3cf0(pfVar1,param_6,local_24);
          }
          fVar2 = (float)fVar17;
          if (fVar2 < param_9) {
            if (param_10 == 0) {
              uVar15 = FUN_005be2d0(*pfVar1 - *param_6,*(float *)(iVar5 + 0x24) - param_6[2]);
              FUN_005b3620(&local_30,&DAT_0080250c,uVar15);
            }
            if ((*(uint *)(iVar14 + 0x60) & 0x20000) != 0) {
              local_20 = 0;
            }
            FUN_005b3b30(local_24,local_24);
            fVar17 = (float10)FUN_005b39e0(local_24,&local_30);
            if ((fVar8 <= fVar2) || (param_10 == 0)) {
              uVar16 = (uint)uVar6;
              if (fVar10 <= fVar2) {
                uVar16 = (uint)uVar7;
              }
            }
            else {
              uVar16 = (uint)uVar9;
            }
            piVar12 = local_4c;
            pfVar13 = local_48;
            if ((((float)fVar17 <= (float)(&DAT_029899a0)[(int)(uVar16 + 0x4000) >> 1 & 0x7fff]) ||
                (local_5c <= fVar2)) ||
               ((fVar11 = fVar2, piVar12 = piVar4, pfVar13 = pfVar1, param_5 != 0 &&
                (piVar4 == *(int **)(param_5 + 0xcc8))))) {
              local_48 = pfVar13;
              local_4c = piVar12;
              fVar11 = local_5c;
              piVar12 = local_54;
              pfVar13 = local_50;
            }
          }
        }
        local_50 = pfVar13;
        local_54 = piVar12;
        local_5c = fVar11;
        local_58 = local_58 + 1;
      } while (local_58 < (int)(uint)*(ushort *)(iVar3 + 0x12));
      if (local_54 != (int *)0x0) {
        *param_3 = *local_50;
        param_3[1] = local_50[1];
        param_3[2] = local_50[2];
        *param_2 = local_5c;
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        return local_54;
      }
      if (local_4c != (int *)0x0) {
        *param_3 = *local_48;
        param_3[1] = local_48[1];
        param_3[2] = local_48[2];
        *param_2 = 1e+09;
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        return local_4c;
      }
    }
  }
  return (int *)0x0;
}

