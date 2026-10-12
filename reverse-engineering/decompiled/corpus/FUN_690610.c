/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x690610; label: FUN_00690610
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00690610(int param_1)

{
  if (((DAT_008104b4 != 0) && (DAT_008108e0 != 0)) && (DAT_02962050 == 0)) {
    _DAT_02962060 = _DAT_008108e4 + _DAT_02962060;
    _DAT_02962068 = _DAT_008108e4 + _DAT_02962068;
    FUN_00657110(1);
    if (param_1 == 0) {
      DAT_0296206c = DAT_0296206c + 1;
      _DAT_0296205c = _DAT_008108e4 + _DAT_0296205c;
      _DAT_02962064 = _DAT_008108e4 + _DAT_02962064;
      FUN_00690520();
      FUN_00685c40();
      FUN_00685eb0();
      FUN_00685ef0();
      FUN_00657110();
      return;
    }
  }
  return;
}

