/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1f30; label: FUN_005c1f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1f30(float *param_1,float param_2,float *param_3)

{
  *param_1 = param_2 * *param_3;
  param_1[1] = param_3[1] * param_2;
  param_1[2] = param_2 * param_3[2];
  return;
}

