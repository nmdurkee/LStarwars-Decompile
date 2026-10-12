/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a7250; label: FUN_006a7250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006a7250(undefined4 param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int local_18;
  int local_10;
  
  iVar1 = *param_3;
  iVar5 = FUN_006a1550(param_1,*(int *)(param_4 + 0x484) * 4);
  iVar2 = *(int *)(param_2 + 0xa0 + *(int *)param_3[1] * 0x3c);
  local_10 = 0;
  if (*(int *)(param_4 + 0x484) < 1) {
    return iVar5;
  }
  piVar7 = (int *)(param_4 + 0x888);
  do {
    puVar3 = *(undefined4 **)(param_5 + piVar7[-0x100] * 4);
    iVar4 = *(int *)(param_5 + *piVar7 * 4);
    iVar6 = FUN_006a1550(param_1,iVar1 * 4);
    *(int *)(iVar5 + local_10 * 4) = iVar6;
    iVar8 = 0;
    if (0 < iVar2) {
      puVar9 = puVar3;
      local_18 = iVar2;
      do {
        fVar10 = (float10)FUN_006a70c0(*puVar9,*(undefined4 *)((iVar4 - (int)puVar3) + (int)puVar9))
        ;
        *(float *)((iVar6 - (int)puVar3) + (int)puVar9) = (float)fVar10;
        puVar9 = puVar9 + 1;
        local_18 = local_18 + -1;
        iVar8 = iVar2;
      } while (local_18 != 0);
    }
    if (iVar8 < iVar1) {
      puVar9 = puVar3 + iVar8;
      iVar8 = iVar1 - iVar8;
      do {
        fVar10 = (float10)FUN_006a7190(*puVar9,*(undefined4 *)((int)puVar9 + (iVar4 - (int)puVar3)))
        ;
        *(float *)((int)puVar9 + (iVar6 - (int)puVar3)) = (float)fVar10;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_10 = local_10 + 1;
    piVar7 = piVar7 + 1;
  } while (local_10 < *(int *)(param_4 + 0x484));
  return iVar5;
}

