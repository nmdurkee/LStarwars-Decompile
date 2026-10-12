/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5557b0; label: FUN_005557b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005557b0(int param_1,undefined4 *param_2)

{
  if ((param_2 != (undefined4 *)0x0) && (param_1 != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x5c);
    param_2[1] = *(undefined4 *)(param_1 + 0x60);
    param_2[2] = *(undefined4 *)(param_1 + 100);
  }
  return;
}

