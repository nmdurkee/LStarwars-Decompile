/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x636380; label: FUN_00636380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00636380(undefined *param_1,undefined *param_2,int param_3)

{
  PTR_DAT_0080fe0c = param_1;
  PTR_PTR_0080fe10 = param_2;
  DAT_0080fe14 = 0x20;
  if (param_3 < 0x21) {
    DAT_0080fe14 = param_3;
  }
  return;
}

