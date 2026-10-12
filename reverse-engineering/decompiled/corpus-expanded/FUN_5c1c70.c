/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1c70; label: FUN_005c1c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c1c70(float *param_1)

{
  float *in_ECX;
  
  return (float10)(param_1[2] * in_ECX[2] + *param_1 * *in_ECX + param_1[1] * in_ECX[1]);
}

