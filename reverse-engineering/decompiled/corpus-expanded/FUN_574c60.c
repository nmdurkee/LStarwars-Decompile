/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574c60; label: FUN_00574c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00574c60(undefined4 param_1)

{
  if (DAT_009248a0 != 0) {
    FUN_005ef880(DAT_009248a0);
  }
  DAT_009248a0 = 0;
  if (DAT_0092489c != 0) {
    FUN_005ef880(DAT_0092489c);
  }
  DAT_0092489c = 0;
  if (DAT_00924898 != 0) {
    FUN_005ef880(DAT_00924898);
  }
  DAT_00924898 = 0;
  if (DAT_00955874 == 2) {
    FUN_005936b0(DAT_00955870);
  }
  else if (DAT_00955874 == 1) {
    FUN_005930c0(DAT_00955870);
  }
  DAT_00955874 = 0;
  FUN_0055b7f0();
  FUN_0055b610();
  FUN_0062dfb0(param_1);
  FUN_005a8180();
  return;
}

