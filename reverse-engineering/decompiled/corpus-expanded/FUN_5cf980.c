/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cf980; label: FUN_005cf980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005cf980(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    if ((*(int *)(param_1 + 4) != 0) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + 0x48) != 0)) {
      return 1;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc4);
    if ((iVar1 != -1) && (iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

