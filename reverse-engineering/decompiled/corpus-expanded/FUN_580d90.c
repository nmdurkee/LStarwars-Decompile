/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580d90; label: FUN_00580d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580d90(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],2);
    if (*in_ECX != 0) {
      FUN_00621180(param_1);
    }
    in_ECX[2] = in_ECX[2] + 2;
  }
  return;
}

