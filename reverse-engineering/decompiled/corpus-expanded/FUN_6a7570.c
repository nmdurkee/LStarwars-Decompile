/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a7570; label: FUN_006a7570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

void FUN_006a7570(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  size_t asStack_28 [4];
  undefined4 uStack_18;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(param_1[1] + 0x200);
  uStack_18 = 0x6a7594;
  iVar4 = iVar2 * -4;
  iVar3 = *(int *)(param_1[1] + 0x1fc);
  iVar9 = iVar2;
  for (iVar8 = iVar3; iVar8 < iVar1; iVar8 = iVar8 + iVar9) {
    if (iVar1 < iVar8 + iVar9) {
      iVar9 = iVar1 - iVar8;
    }
    iVar5 = 0;
    if (0 < iVar9) {
      iVar6 = param_2 + iVar8 * 4;
      do {
        *(int *)(&stack0xffffffec + iVar5 * 4 + iVar4) = iVar6;
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar5 < iVar9);
    }
    asStack_28[4 - iVar2] = (size_t)FUN_006a73e0;
    asStack_28[3 - iVar2] = 4;
    asStack_28[2 - iVar2] = iVar9;
    asStack_28[1 - iVar2] = (size_t)(&stack0xffffffec + iVar4);
    asStack_28[-iVar2] = 0x6a75dd;
    _qsort((void *)asStack_28[1 - iVar2],asStack_28[2 - iVar2],asStack_28[3 - iVar2],
           (_PtFuncCompare *)asStack_28[4 - iVar2]);
    iVar5 = 0;
    if (0 < iVar9) {
      piVar7 = (int *)(param_3 + (iVar8 - iVar3) * 4);
      do {
        iVar6 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        *piVar7 = *(int *)(&stack0xffffffec + iVar6 + iVar4) - param_2 >> 2;
        piVar7 = piVar7 + 1;
      } while (iVar5 < iVar9);
    }
  }
  return;
}

