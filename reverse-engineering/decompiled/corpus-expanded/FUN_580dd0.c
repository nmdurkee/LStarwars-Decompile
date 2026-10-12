/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580dd0; label: FUN_00580dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580dd0(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],4);
    if (*in_ECX != 0) {
      FUN_00621190(param_1);
    }
    in_ECX[2] = in_ECX[2] + 4;
  }
  return;
}

