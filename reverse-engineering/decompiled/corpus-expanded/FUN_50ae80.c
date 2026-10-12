/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50ae80; label: FUN_0050ae80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050ae80(int param_1)

{
  if (DAT_00921d40 != 0) {
    DAT_00921d40 = 0;
    FUN_00509ab0();
    return;
  }
  if (DAT_00921de4 != 0) {
    if (DAT_008016a0 != '\0') {
      DAT_008016a0 = 0;
      _DAT_0080159c = 5.0;
      DAT_00800960 = 0;
      return;
    }
    if (0.0 < _DAT_0080159c) {
      return;
    }
    DAT_00800960 = 1;
    FUN_00509830(1000,0xffffffff,0xffffffff);
    _DAT_0080159c = 5.0;
    DAT_00921d40 = 1;
    DAT_008016a0 = '\x01';
  }
  if ((*(int *)(param_1 + 100) != 0) || (*(int *)(param_1 + 0x68) != 0)) {
    DAT_00800940 = DAT_00800954;
    DAT_00921d40 = 1;
  }
  return;
}

