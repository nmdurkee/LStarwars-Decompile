/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x4423b0; label: FUN_004423b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004423db) */

float10 FUN_004423b0(void)

{
  float10 fVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 == -1) {
    fVar1 = (float10)0;
  }
  else {
    fVar1 = (float10)(*(uint *)(in_stack_00000014 * 0x2e28 + 0x2800 + DAT_0087b2cc) & 1);
  }
  return fVar1;
}

