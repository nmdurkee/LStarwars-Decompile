/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d29f0; label: FUN_004d29f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d29f0(int param_1,undefined4 param_2,float param_3,undefined1 *param_4)

{
  ushort uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  undefined1 local_19;
  float local_18;
  int local_10;
  undefined1 local_c [12];
  
  iVar6 = 0;
  if (*(int *)(param_1 + 0x50c0) != 0) {
    iVar4 = 0;
    local_18 = param_3;
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x50c8) + 0x94 + iVar6);
        iVar5 = *(int *)(param_1 + 0x50c8) + iVar6;
        if (((((uVar2 & 0x4000) != 0) && ((uVar2 & 0x8000) != 0)) && ((uVar2 & 1) == 0)) &&
           (((uVar2 & 0x800000) != 0 && ((*(uint *)(iVar5 + 0x98) & 0x1000000) != 0)))) {
          fVar7 = (float10)FUN_005b3c50(iVar5 + 0x4c,param_2,local_c);
          if ((float)fVar7 < local_18) {
            local_18 = (float)fVar7;
            local_10 = iVar5;
          }
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0x114;
      } while (iVar4 < *(int *)(param_1 + 0x50c0));
    }
    local_19 = 0;
    if (((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
        (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af68)) &&
       (piVar3 = *(int **)(param_1 + 0x46b8), piVar3 != (int *)0x0)) {
      iVar6 = *piVar3;
      iVar4 = 0;
      if ((short)piVar3[2] != 0) {
        do {
          uVar1 = *(ushort *)(iVar6 + 0x13a);
          if (((((uVar1 & 4) != 0) && ((uVar1 & 2) != 0)) && ((uVar1 & 0x30) == 0)) &&
             ((*(int *)(iVar6 + 0x1c) != 0 &&
              (iVar5 = FUN_005cf9e0(*(int *)(iVar6 + 0x1c) + 4), iVar5 != 0)))) {
            fVar7 = (float10)FUN_005b3c50(iVar5,param_2,local_c);
            if ((float)fVar7 < local_18) {
              local_19 = 1;
              local_18 = (float)fVar7;
              local_10 = iVar6;
            }
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x13c;
        } while (iVar4 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x46b8) + 8));
      }
    }
    if (((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
        (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af68)) &&
       ((iVar6 = *(int *)(param_1 + 0x46a4), iVar6 != 0 && (iVar4 = 0, *(short *)(iVar6 + 0xc) != 0)
        ))) {
      do {
        iVar6 = **(int **)(*(int *)(iVar6 + 4) + iVar4 * 4);
        if ((((*(uint *)(iVar6 + 0x94) & 2) != 0) && ((*(uint *)(iVar6 + 0x94) & 1) != 0)) &&
           ((*(byte *)(iVar6 + 0x9c) & 0x80) == 0)) {
          fVar7 = (float10)FUN_005b3c50(iVar6 + 0x28,param_2,local_c);
          if ((float)fVar7 < local_18) {
            local_19 = 2;
            local_18 = (float)fVar7;
            local_10 = iVar6;
          }
        }
        iVar6 = *(int *)(param_1 + 0x46a4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(ushort *)(iVar6 + 0xc));
    }
    if (local_10 != 0) {
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = local_19;
      }
      return local_10;
    }
  }
  return 0;
}

