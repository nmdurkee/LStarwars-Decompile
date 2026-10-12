/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5af970; label: FUN_005af970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005af970(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x516c) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x516c) + 4) == 0)) {
    iVar3 = FUN_006217e0();
    uVar4 = FUN_006217e0();
    *(undefined4 *)(*(int *)(param_1 + 0x516c) + 4) = uVar4;
    iVar6 = **(int **)(param_1 + 0x516c);
    iVar5 = 0;
    if (0 < (*(int **)(param_1 + 0x516c))[1]) {
      do {
        FUN_006216f0(iVar6,0x10);
        FUN_00621900(iVar6 + 0x10);
        uVar2 = FUN_00621890();
        *(undefined2 *)(iVar6 + 0x1c) = uVar2;
        uVar2 = FUN_00621890();
        *(undefined2 *)(iVar6 + 0x1e) = uVar2;
        uVar1 = FUN_006218e0();
        *(undefined1 *)(iVar6 + 0x22) = uVar1;
        if (iVar3 < 2) {
          *(undefined2 *)(iVar6 + 0x20) = 0;
        }
        else {
          uVar2 = FUN_00621890();
          *(undefined2 *)(iVar6 + 0x20) = uVar2;
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x34;
      } while (iVar5 < *(int *)(*(int *)(param_1 + 0x516c) + 4));
    }
    return 1;
  }
  return 0;
}

