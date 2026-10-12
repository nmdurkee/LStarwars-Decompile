/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60af80; label: FUN_0060af80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060af80(int param_1)

{
  FUN_00608590(param_1);
  FUN_006091c0(param_1);
  if (_DAT_02854ccc != 0.0) {
    _DAT_0080e214 = _DAT_02854ccc;
    _DAT_0280d3dc = 0xc04080c0;
  }
  DAT_009718a4 = 1;
  if (param_1 == 0) {
    _DAT_0080e218 = _DAT_0080e214;
    return;
  }
  _DAT_0080e214 = _DAT_0080e218;
  return;
}

