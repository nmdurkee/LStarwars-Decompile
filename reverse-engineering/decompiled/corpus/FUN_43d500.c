/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d500; label: FUN_0043d500
 */

void FUN_0043d500(int param_1)

{
  if (param_1 < 0) {
    DAT_007f6718 = 0;
    return;
  }
  if (4 < param_1) {
    param_1 = 4;
  }
  DAT_007f6718 = param_1;
  return;
}

