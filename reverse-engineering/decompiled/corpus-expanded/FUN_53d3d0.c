/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d3d0; label: FUN_0053d3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d3d0(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(in_ECX[3] + in_ECX[1],param_1,2);
    if (*in_ECX != 0) {
      FUN_00621180(in_ECX[3] + in_ECX[1]);
    }
    in_ECX[3] = in_ECX[3] + 2;
  }
  return;
}

