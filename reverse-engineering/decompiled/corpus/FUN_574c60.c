/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574c60; label: FUN_00574c60
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

