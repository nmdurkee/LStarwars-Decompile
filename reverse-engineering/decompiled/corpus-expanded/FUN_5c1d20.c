/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1d20; label: FUN_005c1d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1d20(float param_1)

{
  float *in_ECX;
  
  param_1 = 1.0 / param_1;
  *in_ECX = param_1 * *in_ECX;
  in_ECX[1] = in_ECX[1] * param_1;
  in_ECX[2] = param_1 * in_ECX[2];
  return;
}

