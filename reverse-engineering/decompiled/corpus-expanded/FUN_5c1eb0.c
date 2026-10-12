/* Ghidra pseudocode, not original source.
 * ev_d8823ef952be36302cd5edf235953b54dcac69dadf5f46e66206c8601523987b
 * Entry: 0x5c1eb0; label: FUN_005c1eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1eb0(undefined4 *param_1,int param_2)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + param_2 * 4);
  param_1[1] = *(undefined4 *)(in_ECX + 0x10 + param_2 * 4);
  param_1[2] = *(undefined4 *)(in_ECX + 0x20 + param_2 * 4);
  param_1[3] = 0;
  return;
}

