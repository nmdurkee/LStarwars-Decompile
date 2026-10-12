/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfed0; label: FUN_005cfed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cfed0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if ((iVar1 == 0) &&
     ((*(int *)(param_1 + 0x110) == 0 ||
      (iVar1 = *(int *)(*(int *)(param_1 + 0x110) + 0x6c), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}

