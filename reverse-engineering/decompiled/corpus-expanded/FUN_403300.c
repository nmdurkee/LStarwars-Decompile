/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403300; label: FUN_00403300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00403300(int param_1,undefined4 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    param_2[1] = *(undefined4 *)(param_1 + 0x14);
    param_2[2] = *(undefined4 *)(param_1 + 0x18);
    param_2[1] = (float)param_2[1] + 1.0;
  }
  return;
}

