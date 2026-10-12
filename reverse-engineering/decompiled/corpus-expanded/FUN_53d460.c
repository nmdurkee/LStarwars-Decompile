/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d460; label: FUN_0053d460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d460(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  *in_ECX = *param_1;
  if (in_ECX[1] != 0) {
    piVar1 = (int *)(in_ECX[1] + 0x4b0);
    *piVar1 = *piVar1 + 1;
    return;
  }
  FUN_0060f2d0();
  return;
}

