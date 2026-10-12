/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50abd0; label: FUN_0050abd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050abd0(void)

{
  if (DAT_00921e0c == 0) {
    if ((DAT_00921e10 == 0) && (_DAT_00921e30 <= 0.0)) {
      if (0.0 < _DAT_00921e44) {
        return;
      }
      FUN_00509ab0();
      return;
    }
  }
  else {
    _DAT_00921e30 = 1.5;
  }
  _DAT_00921e44 = 1.5;
  if ((DAT_00921e0c != 0) && (DAT_00921e5c != 0)) {
    DAT_00921e0c = 0;
    DAT_00921e14 = 1;
  }
  return;
}

