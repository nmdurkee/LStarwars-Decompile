/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d560; label: FUN_0043d560
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043d560(float param_1)

{
  if (param_1 < 0.0) {
    _DAT_007f6724 = 0.0;
    return;
  }
  _DAT_007f6724 = param_1;
  return;
}

