/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441dc0; label: FUN_00441dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441dc0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    return (float10)*(byte *)(**(int **)(param_3 + 0xd0) + 0xe32);
  }
  return (float10)0;
}

