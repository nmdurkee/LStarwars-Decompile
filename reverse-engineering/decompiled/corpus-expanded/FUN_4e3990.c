/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3990; label: FUN_004e3990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3990(void)

{
  if (DAT_00951b50 == 0) {
    if (_DAT_008895ac < 0.0 == (_DAT_008895ac == 0.0)) {
      _DAT_008895ac = _DAT_008895ac - _DAT_00925018;
    }
    else if ((&DAT_008895c0)[DAT_00889608] == 0) {
      FUN_004e3890(DAT_00889608);
      DAT_00889608 = DAT_00889608 + 1;
      if (DAT_00889608 == 2) {
        DAT_00889608 = 0;
      }
      _DAT_008895ac = 8.0;
      return;
    }
  }
  return;
}

