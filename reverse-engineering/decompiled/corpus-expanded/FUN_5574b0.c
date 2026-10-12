/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5574b0; label: FUN_005574b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005574b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int local_4;
  
  iVar3 = param_1;
  iVar1 = param_1 + 0x108;
  iVar2 = param_1 + 0x104;
  piVar5 = (int *)FUN_00552670(iVar2,iVar1,0x14);
  uVar4 = (ushort)*(byte *)(*(int *)(param_1 + 0x128) + 0xef);
  *(ushort *)((int)piVar5 + 10) = uVar4;
  iVar6 = FUN_00552670(iVar2,iVar1,uVar4 * 0xa0);
  *piVar5 = iVar6;
  iVar6 = FUN_00552670(iVar2,iVar1,(uint)*(ushort *)((int)piVar5 + 10) * 4);
  piVar5[1] = iVar6;
  iVar6 = FUN_005a0760(iVar2,iVar1,4,*(undefined2 *)(*(int *)(param_1 + 0x128) + 0xe0));
  piVar5[4] = iVar6;
  param_1 = 0;
  if (*(short *)((int)piVar5 + 10) != 0) {
    local_4 = 0;
    do {
      uVar7 = FUN_005a05f0(iVar2,iVar1,piVar5[4],*(undefined4 *)(iVar3 + 0x2960));
      *(undefined4 *)(*piVar5 + 0x34 + local_4) = uVar7;
      local_4 = local_4 + 0xa0;
      param_1 = param_1 + 1;
    } while (param_1 < (int)(uint)*(ushort *)((int)piVar5 + 10));
  }
  *(int **)(iVar3 + 0x46a4) = piVar5;
  return piVar5;
}

