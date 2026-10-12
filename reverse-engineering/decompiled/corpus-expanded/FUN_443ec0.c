/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443ec0; label: FUN_00443ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443ec0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(char *)(*piVar1 + 0x283) == '\t')) {
    return (float10)1;
  }
  return (float10)0;
}

