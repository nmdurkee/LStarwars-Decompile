/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e8c0; label: FUN_0044e8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044e8c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    FUN_0062e6c0(*(undefined4 *)(*piVar1 + 0x50),*piVar1 + 8);
  }
  return 1;
}

