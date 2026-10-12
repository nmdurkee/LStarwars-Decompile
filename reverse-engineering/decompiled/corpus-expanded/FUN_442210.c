/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x442210; label: FUN_00442210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442210(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) ||
      (((param_3 != 0 && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (param_5 = **(int **)(param_3 + 0xd0), param_5 != 0)))) &&
     (((*(char *)(param_5 + 0x7b5) == 'F' && (*(int *)(param_5 + 0x798) != 0)) &&
      (*(char *)(*(int *)(param_5 + 0x798) + 0x1c) != '\0')))) {
    return (float10)1;
  }
  return (float10)0;
}

