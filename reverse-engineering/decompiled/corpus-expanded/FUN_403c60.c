/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403c60; label: FUN_00403c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00403c60(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  param_2[1] = *(undefined4 *)(param_1 + 0x84);
  param_2[2] = *(undefined4 *)(param_1 + 0x88);
  return;
}

