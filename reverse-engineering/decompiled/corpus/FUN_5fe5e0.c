/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fe5e0; label: FUN_005fe5e0
 */

undefined * FUN_005fe5e0(int param_1)

{
  DAT_0080e1ac = DAT_0080e1ac - param_1;
  if (DAT_0080e1a8 < 0) {
    FUN_005f7490();
    return (undefined *)0x0;
  }
  return &DAT_0097c230 + DAT_0080e1ac * 4;
}

