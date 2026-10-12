/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x4436a0; label: FUN_004436a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004436a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    return (float10)(*(byte *)(*piVar1 + 0xef2) & 1);
  }
  return (float10)0;
}

