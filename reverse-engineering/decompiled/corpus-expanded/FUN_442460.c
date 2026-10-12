/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x442460; label: FUN_00442460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442460(void)

{
  int in_stack_00000014;
  
  if ((DAT_00951b7c != 0) && (*(short *)(DAT_00951b7c + 0x62) == in_stack_00000014)) {
    return (float10)1;
  }
  return (float10)0;
}

