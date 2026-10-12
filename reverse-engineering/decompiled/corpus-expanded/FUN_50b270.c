/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50b270; label: FUN_0050b270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050b270(int param_1)

{
  *(int *)(param_1 + 0x3c) = DAT_00921d3c;
  if (DAT_00921d3c == 0) {
    if (DAT_00924800 == 1) {
      _DAT_00921d50 = 1;
      _DAT_00921d58 = 1;
      DAT_00921d3c = 3;
      FUN_00509ab0();
      return;
    }
  }
  else if ((DAT_00921d3c == 7) && (*(int *)(param_1 + 100) != 0)) {
    DAT_00921d3c = 3;
    DAT_00800940 = DAT_00800954;
    FUN_00509ab0();
    return;
  }
  if (DAT_00921d3c == 3) {
    FUN_00509ab0();
    return;
  }
  if (DAT_00921d3c != *(int *)(param_1 + 0x3c)) {
    if (DAT_00921d3c != 0) {
      _DAT_00921d5c = 0;
      _DAT_00921d60 = 0;
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

