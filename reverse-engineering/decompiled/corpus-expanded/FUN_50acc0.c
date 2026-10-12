/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50acc0; label: FUN_0050acc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050acc0(void)

{
  if ((DAT_00921e00 != 0) || (0.0 < _DAT_00921e38)) {
    _DAT_00921e4c = 1.5;
    if ((DAT_00921e00 != 0) && (DAT_00921e5c != 0)) {
      DAT_00921e00 = 0;
      DAT_00921e08 = 1;
    }
  }
  else if (_DAT_00921e4c <= 0.0) {
    FUN_00509ab0();
    return;
  }
  return;
}

