/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a7430; label: FUN_006a7430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int * FUN_006a7430(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t asStack_38 [4];
  int iStack_28;
  int local_14;
  int *local_8;
  
  if (*(int *)(param_2[1] + 0x1f8) == 0) {
    return (int *)0x0;
  }
  iVar1 = *param_2;
  iStack_28 = *(int *)(param_3 + 0x484) * 4;
  asStack_38[3] = param_1;
  asStack_38[2] = 0x6a7468;
  piVar3 = (int *)FUN_006a1550();
  iVar2 = *(int *)(param_2[1] + 0x200);
  iStack_28 = 0x6a7483;
  iVar6 = 0;
  local_8 = piVar3;
  if (0 < *(int *)(param_3 + 0x484)) {
    do {
      asStack_38[4 - iVar2] = iVar1 * 4;
      asStack_38[3 - iVar2] = param_1;
      asStack_38[2 - iVar2] = 0x6a74b1;
      iVar4 = FUN_006a1550();
      *local_8 = iVar4;
      local_14 = 0;
      if (0 < iVar1) {
        param_2 = (int *)0x0;
        do {
          iVar5 = 0;
          iVar4 = (int)param_2;
          if (0 < iVar2) {
            do {
              *(int *)(&stack0xffffffdc + iVar2 * -4 + iVar5 * 4) =
                   *(int *)(param_4 + iVar6 * 4) + iVar4;
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 4;
            } while (iVar5 < iVar2);
          }
          asStack_38[4 - iVar2] = (size_t)FUN_006a73e0;
          asStack_38[3 - iVar2] = 4;
          asStack_38[2 - iVar2] = iVar2;
          asStack_38[1 - iVar2] = (size_t)(&stack0xffffffdc + iVar2 * -4);
          asStack_38[-iVar2] = 0x6a74f2;
          _qsort((void *)asStack_38[1 - iVar2],asStack_38[2 - iVar2],asStack_38[3 - iVar2],
                 (_PtFuncCompare *)asStack_38[4 - iVar2]);
          iVar5 = 0;
          iVar4 = (int)param_2;
          if (0 < iVar2) {
            do {
              *(int *)(iVar4 + *local_8) =
                   *(int *)(&stack0xffffffdc + iVar5 * 4 + iVar2 * -4) -
                   *(int *)(param_4 + iVar6 * 4) >> 2;
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 4;
            } while (iVar5 < iVar2);
          }
          local_14 = local_14 + iVar2;
          param_2 = (int *)((int)param_2 + iVar2 * 4);
        } while (local_14 < iVar1);
      }
      iVar6 = iVar6 + 1;
      local_8 = local_8 + 1;
    } while (iVar6 < *(int *)(param_3 + 0x484));
  }
  return piVar3;
}

