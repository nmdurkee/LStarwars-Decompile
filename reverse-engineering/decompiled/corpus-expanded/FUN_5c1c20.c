/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1c20; label: FUN_005c1c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c1c20(void)

{
  float *in_ECX;
  
  return (float10)(in_ECX[2] * in_ECX[2] + *in_ECX * *in_ECX + in_ECX[1] * in_ECX[1]);
}

