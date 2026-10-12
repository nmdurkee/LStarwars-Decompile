/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d06a0; label: FUN_004d06a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d06a0(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x505c) != 0) {
    return 0;
  }
  iVar3 = FUN_006217e0();
  iVar4 = FUN_006217e0();
  iVar5 = 0;
  *(int *)(param_1 + 0x505c) = iVar4;
  if (0 < iVar4) {
    iVar4 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x5058) + iVar4,0x10);
      FUN_00621900(*(int *)(param_1 + 0x5058) + 0x10 + iVar4);
      FUN_00621900(*(int *)(param_1 + 0x5058) + 0x1c + iVar4);
      if (1 < iVar3) {
        uVar2 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5058) + 0x28 + iVar4) = uVar2;
        uVar2 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5058) + 0x2a + iVar4) = uVar2;
        uVar2 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5058) + 0x2c + iVar4) = uVar2;
        uVar2 = FUN_00621890();
        *(undefined2 *)(*(int *)(param_1 + 0x5058) + 0x2e + iVar4) = uVar2;
        uVar1 = FUN_006218e0();
        *(undefined1 *)(*(int *)(param_1 + 0x5058) + 0x30 + iVar4) = uVar1;
        uVar1 = FUN_006218e0();
        *(undefined1 *)(*(int *)(param_1 + 0x5058) + 0x31 + iVar4) = uVar1;
        if (2 < iVar3) {
          uVar1 = FUN_006218c0();
          *(undefined1 *)(*(int *)(param_1 + 0x5058) + 0x32 + iVar4) = uVar1;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x48;
    } while (iVar5 < *(int *)(param_1 + 0x505c));
  }
  return 1;
}

