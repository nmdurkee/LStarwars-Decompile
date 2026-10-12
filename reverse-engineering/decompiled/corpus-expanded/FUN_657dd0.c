/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x657dd0; label: FUN_00657dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00657dd0(void)

{
  if (_DAT_0296205c - 1.0 <= _DAT_02962064) {
    if (900.0 < _DAT_0296205c) {
      _DAT_02962064 = _DAT_02962064 - 800.0;
    }
  }
  else {
    FUN_00657a00(0);
  }
  if (_DAT_02962060 - 1.0 <= _DAT_02962068) {
    if (_DAT_02962060 <= 900.0) {
      return;
    }
    _DAT_02962068 = _DAT_02962068 - 800.0;
    return;
  }
  FUN_00657a00(1);
  return;
}

