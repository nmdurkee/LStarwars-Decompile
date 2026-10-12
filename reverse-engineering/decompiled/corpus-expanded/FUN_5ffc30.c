/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ffc30; label: FUN_005ffc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ffc30(void)

{
  if ((DAT_02854cec == 0) && (DAT_02854d00 != 0)) {
    FUN_006e5bc0((&DAT_0280d3cc)[DAT_02854cf0]);
  }
  DAT_02854d00 = 0;
  DAT_02854cf0 = 0;
  DAT_02854cec = 0;
  DAT_02854cf4 = 0;
  DAT_02854d08 = 0;
  _DAT_02854d0c = 0;
  return;
}

