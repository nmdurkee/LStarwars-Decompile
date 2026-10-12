/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab840; label: FUN_005ab840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005ab840(int param_1)

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
  piVar5 = (int *)FUN_00552670(iVar2,iVar1,0x10);
  bVar3 = *(byte *)(*(int *)(param_1 + 0x128) + 0x106);
  *(ushort *)((int)piVar5 + 10) = (ushort)bVar3;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)bVar3 * 0x13c);
  *piVar5 = iVar6;
  iVar6 = FUN_005a0760(iVar2,iVar1,4,(uint)*(ushort *)((int)piVar5 + 10) * 2);
  piVar5[1] = iVar6;
  param_1 = 0;
  if (*(short *)((int)piVar5 + 10) != 0) {
    local_4 = 0;
    do {
      uVar7 = FUN_005a05f0(iVar2,iVar1,piVar5[1],*(undefined4 *)(iVar4 + 0x2960));
      *(undefined4 *)(*piVar5 + 0x18 + local_4) = uVar7;
      local_4 = local_4 + 0x13c;
      param_1 = param_1 + 1;
    } while (param_1 < (int)(uint)*(ushort *)((int)piVar5 + 10));
  }
  *(int **)(iVar4 + 0x46b8) = piVar5;
  return piVar5;
}

