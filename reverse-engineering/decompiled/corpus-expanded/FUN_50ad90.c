/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50ad90; label: FUN_0050ad90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050ad90(void)

{
  if (DAT_00921ddc == 0) {
    if ((DAT_00921de0 == 0) && (_DAT_00921e2c <= 0.0)) {
      if (0.0 < _DAT_00921e40) {
        return;
      }
      if (DAT_00921de4 == 0) {
        if ((DAT_00921e6c != 0) && (DAT_00802014 != -1)) {
          FUN_00509bc0();
          FUN_00509bc0();
          FUN_00509830(0x3f2,1,0xffffffff);
          return;
        }
        FUN_00509bc0();
        FUN_00509ab0();
        return;
      }
      FUN_00509ab0();
      return;
    }
  }
  else {
    _DAT_00921e2c = 1.5;
  }
  _DAT_00921e40 = 1.5;
  if ((DAT_00921ddc != 0) && ((DAT_00921e5c != 0 || (DAT_00802008 == -1)))) {
    DAT_00921ddc = 0;
    DAT_00921de4 = 1;
  }
  return;
}

