/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ad8e0; label: FUN_005ad8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005ad8e0(int param_1,float *param_2,float *param_3,undefined4 *param_4,int param_5,
                  float *param_6,undefined4 *param_7,float param_8,float param_9,int param_10,
                  int param_11,undefined4 param_12)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  float fVar6;
  ushort uVar7;
  float fVar8;
  float fVar9;
  int *piVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  float10 fVar18;
  float local_54;
  int *local_50;
  float *local_4c;
  int *local_48;
  float *local_44;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  iVar12 = FUN_005806a0(param_12,PTR_DAT_00802c54);
  fVar8 = _DAT_0087aa54;
  uVar7 = DAT_0087a958;
  fVar6 = _DAT_0087a930;
  uVar5 = DAT_0087a838;
  uVar4 = DAT_0087a834;
  local_44 = (float *)0x0;
  local_4c = (float *)0x0;
  if ((param_1 != 0) && (iVar12 != 0)) {
    local_54 = 1e+09;
    local_30 = *param_7;
    local_2c = param_7[1];
    local_18 = *param_6 - param_8;
    local_28 = param_7[2];
    local_50 = (int *)0x0;
    local_48 = (int *)0x0;
    local_10 = param_6[2] - param_8;
    local_c = *param_6 + param_8;
    local_4 = param_8 + param_6[2];
    if ((param_10 != 0) && ((*(uint *)(iVar12 + 0x60) & 0x20000) != 0)) {
      local_2c = 0;
      FUN_005b3b30(&local_30,&local_30);
    }
    piVar17 = *(int **)(param_1 + 0xc);
    iVar16 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      do {
        uVar2 = *(ushort *)(*piVar17 + 0x13a);
        fVar9 = local_54;
        piVar10 = local_50;
        pfVar11 = local_4c;
        if ((((((uVar2 & 4) != 0) && ((uVar2 & 2) != 0)) && ((uVar2 & 0x30) == 0)) &&
            ((iVar3 = *(int *)(*piVar17 + 0x1c), iVar3 != 0 &&
             (pfVar13 = (float *)FUN_005cf9e0(iVar3 + 4), pfVar13 != (float *)0x0)))) &&
           (((local_18 <= *pfVar13 && ((*pfVar13 <= local_c && (local_10 <= pfVar13[2])))) &&
            (pfVar13[2] <= local_4)))) {
          if (param_11 == 0) {
            fVar18 = (float10)FUN_005b3c50(pfVar13,param_6,local_24);
          }
          else {
            fVar18 = (float10)FUN_005b3cf0(pfVar13,param_6,local_24);
          }
          fVar1 = (float)fVar18;
          if (fVar1 < param_9) {
            if (param_10 == 0) {
              uVar14 = FUN_005be2d0(*pfVar13 - *param_6,pfVar13[2] - param_6[2]);
              FUN_005b3620(&local_30,&DAT_0080250c,uVar14);
            }
            if ((*(uint *)(iVar12 + 0x60) & 0x20000) != 0) {
              local_20 = 0;
            }
            FUN_005b3b30(local_24,local_24);
            fVar18 = (float10)FUN_005b39e0(local_24,&local_30);
            if ((fVar6 <= fVar1) || (param_10 == 0)) {
              uVar15 = (uint)uVar4;
              if (fVar8 <= fVar1) {
                uVar15 = (uint)uVar5;
              }
            }
            else {
              uVar15 = (uint)uVar7;
            }
            piVar10 = local_48;
            pfVar11 = local_44;
            if ((((float)fVar18 <= (float)(&DAT_029899a0)[(int)(uVar15 + 0x4000) >> 1 & 0x7fff]) ||
                (local_54 <= fVar1)) ||
               ((fVar9 = fVar1, piVar10 = piVar17, pfVar11 = pfVar13, param_5 != 0 &&
                (piVar17 == *(int **)(param_5 + 0xcc8))))) {
              local_44 = pfVar11;
              local_48 = piVar10;
              fVar9 = local_54;
              piVar10 = local_50;
              pfVar11 = local_4c;
            }
          }
        }
        local_4c = pfVar11;
        local_50 = piVar10;
        local_54 = fVar9;
        iVar16 = iVar16 + 1;
        piVar17 = piVar17 + 2;
      } while (iVar16 < *(int *)(param_1 + 4));
      if (local_50 != (int *)0x0) {
        *param_3 = *local_4c;
        param_3[1] = local_4c[1];
        param_3[2] = local_4c[2];
        *param_2 = local_54;
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        return local_50;
      }
      if (local_48 != (int *)0x0) {
        *param_3 = *local_44;
        param_3[1] = local_44[1];
        param_3[2] = local_44[2];
        *param_2 = 1e+09;
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        return local_48;
      }
    }
  }
  return (int *)0x0;
}

