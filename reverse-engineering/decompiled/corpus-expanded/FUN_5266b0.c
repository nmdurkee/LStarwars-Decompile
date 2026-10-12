/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x5266b0; label: FUN_005266b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005266b0(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  int *piVar6;
  int iVar7;
  int local_8;
  
  if ((((param_1 != 0) && (param_2 != 0)) &&
      (iVar7 = *(int *)(DAT_009238e4 + 0x4868), *(int *)(iVar7 + 0x28) != 0)) &&
     ((*(int *)(iVar7 + 0x28) - iVar7) + -0x40 >> 5 < 0x10)) {
    iVar7 = 0;
    piVar6 = (int *)(param_1 + 0x30);
    do {
      if (*piVar6 == param_2) {
        iVar3 = (iVar7 * 3 + 0xc) * 4;
        puVar1 = (ushort *)(iVar3 + 8 + param_1);
        uVar2 = *puVar1;
        uVar5 = __allshl();
        if ((uVar2 & uVar5) == 0) {
          *puVar1 = uVar2 | uVar5;
          return 1;
        }
        uVar4 = ~uVar5;
        *puVar1 = uVar4 & uVar2;
        local_8 = 0;
        goto LAB_00526760;
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 3;
    } while (iVar7 < 8);
  }
  return 0;
LAB_00526760:
  if ((*(int *)(iVar3 + param_1) != 0) && ((*(ushort *)(param_1 + 0x38 + iVar7 * 0xc) & uVar5) != 0)
     ) {
    *(ushort *)(param_1 + 0x96) = *(ushort *)(param_1 + 0x96) & uVar4;
    goto LAB_00526795;
  }
  local_8 = local_8 + 1;
  if (7 < local_8) {
LAB_00526795:
    local_8 = 0;
    while ((*(int *)(iVar3 + param_2) == 0 ||
           ((*(ushort *)(param_2 + 0x38 + iVar7 * 0xc) & uVar5) == 0))) {
      local_8 = local_8 + 1;
      if (7 < local_8) {
        return 0xffffffff;
      }
    }
    *(ushort *)(param_2 + 0x96) = *(ushort *)(param_2 + 0x96) & uVar4;
    return 0xffffffff;
  }
  goto LAB_00526760;
}

