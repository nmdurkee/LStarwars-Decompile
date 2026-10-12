/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6b70; label: FUN_006d6b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006d6b70(int param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = _DAT_029755e8;
  if ((DAT_029755ac != 0) && (param_1 == DAT_029755ac)) {
    if (DAT_029755e4 == 0) {
      _DAT_029755e8 = 0.5;
      DAT_029755e4 = 1;
      return 1;
    }
    fVar2 = (float10)FUN_004f3bb0();
    _DAT_029755e8 = (float)((float10)fVar1 - fVar2);
    if (_DAT_029755e8 < 0.0 != (_DAT_029755e8 == 0.0)) {
      _DAT_029755e8 = _DAT_029755e8 + 0.125;
      if (0.0 < _DAT_029755e8) {
        return 1;
      }
      _DAT_029755e8 = 0.0;
      return 1;
    }
  }
  return 0;
}

