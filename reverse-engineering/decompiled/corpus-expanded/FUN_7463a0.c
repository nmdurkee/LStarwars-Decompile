/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7463a0; label: FUN_007463a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007463a0(undefined1 param_1)

{
  int *in_ECX;
  
  if (in_ECX[2] < in_ECX[1] + 1) {
    FUN_007484e0((in_ECX[1] * 3 + 3) / 2);
  }
  *(undefined1 *)(*in_ECX + in_ECX[1]) = param_1;
  in_ECX[1] = in_ECX[1] + 1;
  return;
}

