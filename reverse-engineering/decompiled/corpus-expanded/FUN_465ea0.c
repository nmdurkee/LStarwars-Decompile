/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x465ea0; label: FUN_00465ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00465ea0(int param_1)

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
  piVar5 = (int *)FUN_00552670(iVar2,iVar1,0x14);
  bVar3 = *(byte *)(*(int *)(param_1 + 0x128) + 0x107);
  *(ushort *)((int)piVar5 + 6) = (ushort)bVar3;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)bVar3 * 0x2c);
  *piVar5 = iVar6;
  iVar6 = FUN_005a0760(iVar2,iVar1,0,*(undefined2 *)(*(int *)(param_1 + 0x128) + 0xe6));
  piVar5[2] = iVar6;
  param_1 = 0;
  if (*(short *)((int)piVar5 + 6) != 0) {
    local_4 = 0;
    do {
      uVar7 = FUN_005a05f0(iVar2,iVar1,piVar5[2],*(undefined4 *)(iVar4 + 0x2960));
      *(undefined4 *)(*piVar5 + 0x1c + local_4) = uVar7;
      local_4 = local_4 + 0x2c;
      param_1 = param_1 + 1;
    } while (param_1 < (int)(uint)*(ushort *)((int)piVar5 + 6));
  }
  *(int **)(iVar4 + 0x5114) = piVar5;
  return piVar5;
}

