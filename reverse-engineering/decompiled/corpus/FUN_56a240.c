/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x56a240; label: FUN_0056a240
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0056a240(int param_1,float *param_2,undefined4 *param_3,float param_4,float param_5,
                int param_6,int param_7,undefined4 param_8)

{
  float *pfVar1;
  float fVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  ushort uVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  float10 fVar16;
  int local_54;
  int iStack_4c;
  float local_48;
  int local_44;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_4;
  
  iVar10 = FUN_0055f450();
  iVar11 = FUN_005806a0(param_8,iVar10);
  fVar7 = _DAT_0087aa54;
  uVar6 = DAT_0087a958;
  fVar5 = _DAT_0087a930;
  uVar4 = DAT_0087a838;
  uVar3 = DAT_0087a834;
  iVar15 = *(int *)(iVar10 + 0x50c8);
  if ((iVar15 != 0) &&
     ((DAT_00950bc8 == (code *)0x0 || (iVar12 = (*DAT_00950bc8)(iVar10,param_1), iVar12 == 0)))) {
    local_48 = 1e+08;
    local_30 = *param_3;
    local_2c = param_3[1];
    local_54 = 0;
    local_44 = 0;
    local_28 = param_3[2];
    fStack_18 = *param_2 - param_4;
    fStack_10 = param_2[2] - param_4;
    fStack_c = *param_2 + param_4;
    fStack_4 = param_4 + param_2[2];
    if ((param_6 != 0) && ((*(uint *)(iVar11 + 0x60) & 0x20000) != 0)) {
      local_2c = 0;
      FUN_005b3b30(&local_30,&local_30);
    }
    iVar12 = *(int *)(iVar10 + 0x50cc);
    iStack_4c = iVar12;
    if (iVar12 < 1) {
      iStack_4c = *(int *)(iVar10 + 0x50c0);
    }
    if (iVar12 == 0) {
      iVar15 = *(int *)(iVar10 + 0x50c8);
    }
    iVar12 = 0;
    if (0 < iStack_4c) {
      do {
        if (*(int *)(iVar10 + 0x50cc) != 0) {
          iVar15 = *(int *)(*(int *)(iVar10 + 0x50d0) + iVar12 * 4);
        }
        iVar8 = local_54;
        fVar9 = local_48;
        if (((((((*(uint *)(iVar15 + 0x98) & 0x8000) != 0) &&
               (uVar14 = *(uint *)(iVar15 + 0x94), (uVar14 & 1) == 0)) &&
              ((uVar14 & 0x8800000) != 0)) && ((uVar14 & 0x4000) != 0)) &&
            ((((*(uint *)(iVar15 + 0x98) & 0x20) == 0 || (DAT_0087baf0 != 0)) &&
             ((pfVar1 = (float *)(iVar15 + 0x4c), fStack_18 <= *(float *)(iVar15 + 0x4c) &&
              ((*pfVar1 <= fStack_c && (fStack_10 <= *(float *)(iVar15 + 0x54))))))))) &&
           (*(float *)(iVar15 + 0x54) <= fStack_4)) {
          if (param_7 == 0) {
            fVar16 = (float10)FUN_005b3c50(pfVar1,param_2,auStack_24);
          }
          else {
            fVar16 = (float10)FUN_005b3cf0(pfVar1,param_2,auStack_24);
          }
          fVar2 = (float)fVar16;
          if (fVar2 < param_5) {
            if (param_6 == 0) {
              uVar13 = FUN_005be2d0(*pfVar1 - *param_2,*(float *)(iVar15 + 0x54) - param_2[2]);
              FUN_005b3620(&local_30,&DAT_0080250c,uVar13);
            }
            if ((*(uint *)(iVar11 + 0x60) & 0x20000) != 0) {
              uStack_20 = 0;
            }
            FUN_005b3b30(auStack_24,auStack_24);
            fVar16 = (float10)FUN_005b39e0(auStack_24,&local_30);
            if ((fVar5 <= fVar2) || (param_6 == 0)) {
              uVar14 = (uint)uVar3;
              if (fVar7 <= fVar2) {
                uVar14 = (uint)uVar4;
              }
            }
            else {
              uVar14 = (uint)uVar6;
            }
            iVar8 = local_44;
            if ((((float)fVar16 <= (float)(&DAT_029899a0)[(int)(uVar14 + 0x4000) >> 1 & 0x7fff]) ||
                (local_48 <= fVar2)) ||
               ((iVar8 = iVar15, fVar9 = fVar2, param_1 != 0 &&
                (iVar15 == *(int *)(param_1 + 0xcc8))))) {
              local_44 = iVar8;
              iVar8 = local_54;
              fVar9 = local_48;
            }
          }
        }
        local_48 = fVar9;
        local_54 = iVar8;
        iVar12 = iVar12 + 1;
        iVar15 = iVar15 + 0x114;
      } while (iVar12 < iStack_4c);
      if ((local_54 == 0) && (local_44 != 0)) {
        local_54 = local_44;
      }
    }
    return local_54;
  }
  return 0;
}

