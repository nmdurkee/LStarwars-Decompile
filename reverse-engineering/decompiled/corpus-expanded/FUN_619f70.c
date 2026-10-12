/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619f70; label: FUN_00619f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00619f70(void)

{
  if (DAT_0291211c == PTR_s_QWERTYUIOP_0080f56c) {
    DAT_02912118 = PTR_s_1234567890_0080f578;
    DAT_0291211c = PTR_s_qwertyuiop_0080f57c;
    _DAT_02912124 = PTR_s_zxcvbnm<>__0080f584;
    _DAT_02912120 = PTR_s_asdfghjkl__0080f580;
    return;
  }
  DAT_0291211c = PTR_s_QWERTYUIOP_0080f56c;
  DAT_02912118 = PTR_s_1234567890_0080f568;
  _DAT_02912124 = PTR_s_ZXCVBNM<>__0080f574;
  _DAT_02912120 = PTR_s_ASDFGHJKL__0080f570;
  return;
}

