/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467040; label: FUN_00467040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00467040(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int local_4;
  
  iVar4 = param_1;
  iVar1 = param_1 + 0x108;
  iVar2 = param_1 + 0x104;
  piVar5 = (int *)FUN_00552670(iVar2,iVar1,0x158);
  bVar3 = *(byte *)(*(int *)(param_1 + 0x128) + 0xfe);
  *(ushort *)(piVar5 + 3) = (ushort)bVar3;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)bVar3 * 0xa4);
  *piVar5 = iVar6;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)*(ushort *)(piVar5 + 3) * 4);
  piVar5[2] = iVar6;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)*(ushort *)(piVar5 + 3) * 4);
  piVar5[1] = iVar6;
  iVar6 = FUN_005a0760(iVar2,iVar1,8,*(undefined2 *)(*(int *)(param_1 + 0x128) + 0xe4));
  piVar5[5] = iVar6;
  param_1 = 0;
  if ((short)piVar5[3] != 0) {
    local_4 = 0;
    do {
      uVar7 = FUN_005a05f0(iVar2,iVar1,piVar5[5],*(undefined4 *)(iVar4 + 0x2960));
      *(undefined4 *)(*piVar5 + 0x28 + local_4) = uVar7;
      local_4 = local_4 + 0xa4;
      param_1 = param_1 + 1;
    } while (param_1 < (int)(uint)*(ushort *)(piVar5 + 3));
  }
  *(int **)(iVar4 + 0x46ac) = piVar5;
  return piVar5;
}

