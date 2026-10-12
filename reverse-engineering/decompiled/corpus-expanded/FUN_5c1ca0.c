/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1ca0; label: FUN_005c1ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1ca0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  return;
}

