/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6367f0; label: FUN_006367f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006367f0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x140) = param_2;
  }
  return;
}

