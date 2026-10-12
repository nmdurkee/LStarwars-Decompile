/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x481ac0; label: FUN_00481ac0
 */

undefined4 FUN_00481ac0(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x50ac) != 0) {
    return 0;
  }
  iVar3 = FUN_006217e0();
  iVar4 = FUN_006217e0();
  iVar5 = 0;
  *(int *)(param_1 + 0x50ac) = iVar4;
  if (0 < iVar4) {
    iVar4 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x50a8) + iVar4,8);
      FUN_00621900(*(int *)(param_1 + 0x50a8) + 8 + iVar4);
      uVar2 = FUN_00621860();
      *(undefined2 *)(*(int *)(param_1 + 0x50a8) + 0x14 + iVar4) = uVar2;
      uVar1 = FUN_006218c0();
      *(undefined1 *)(*(int *)(param_1 + 0x50a8) + 0x16 + iVar4) = uVar1;
      if (iVar3 < 2) {
        uVar2 = 0xffff;
        *(undefined2 *)(*(int *)(param_1 + 0x50a8) + 0x1c + iVar4) = 0xffff;
      }
      else {
        uVar2 = FUN_00621860();
        *(undefined2 *)(*(int *)(param_1 + 0x50a8) + 0x1c + iVar4) = uVar2;
        uVar2 = FUN_00621860();
      }
      *(undefined2 *)(*(int *)(param_1 + 0x50a8) + 0x1e + iVar4) = uVar2;
      if (iVar3 < 3) {
        *(undefined1 *)(*(int *)(param_1 + 0x50a8) + 0x19 + iVar4) = 0;
      }
      else {
        uVar1 = FUN_006218e0();
        *(undefined1 *)(*(int *)(param_1 + 0x50a8) + 0x19 + iVar4) = uVar1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar5 < *(int *)(param_1 + 0x50ac));
  }
  return 1;
}

