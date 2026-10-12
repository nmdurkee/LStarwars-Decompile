/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1e20; label: FUN_005c1e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1e20(float *param_1,float *param_2)

{
  float *in_ECX;
  
  *param_1 = *param_2 + *in_ECX;
  param_1[1] = param_2[1] + in_ECX[1];
  param_1[2] = param_2[2] + in_ECX[2];
  return;
}

