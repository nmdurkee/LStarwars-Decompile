/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe860; label: FUN_005fe860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fe860(int param_1)

{
  if (_DAT_02854ccc != 0.0) {
    _DAT_0080e214 = _DAT_02854ccc;
    _DAT_0280d3dc = 0xc04080c0;
  }
  if (param_1 == 0) {
    _DAT_0080e218 = _DAT_0080e214;
    return;
  }
  _DAT_0080e214 = _DAT_0080e218;
  return;
}

