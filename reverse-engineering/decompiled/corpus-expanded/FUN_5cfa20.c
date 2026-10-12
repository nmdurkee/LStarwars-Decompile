/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfa20; label: FUN_005cfa20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cfa20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 4);
  }
  return iVar1;
}

