/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x442180; label: FUN_00442180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442180(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(char *)(*piVar1 + 0x7b5) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

