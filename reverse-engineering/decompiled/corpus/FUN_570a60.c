/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570a60; label: FUN_00570a60
 */

void FUN_00570a60(int param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 10) = 1;
    *(undefined4 *)(param_1 + 4) = 0x3f800000;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

