/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f260; label: FUN_0061f260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061f260(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  piVar2 = *(int **)(iVar1 + 0x10);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      *(int *)(iVar1 + 0x10) = *piVar2;
    }
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x10);
  }
  return 0;
}

