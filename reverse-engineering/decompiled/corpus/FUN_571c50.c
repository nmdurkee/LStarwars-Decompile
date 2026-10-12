/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571c50; label: FUN_00571c50
 */

void FUN_00571c50(int param_1)

{
  *(undefined4 *)(param_1 + 0x100) = 0x40a00000;
  if ((*(byte *)(param_1 + 0x20a) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x100) = 0x40200000;
  }
  return;
}

