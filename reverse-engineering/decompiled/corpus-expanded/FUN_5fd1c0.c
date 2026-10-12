/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd1c0; label: FUN_005fd1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd1c0(void)

{
  _memset(&DAT_009868a0,0,0x1a4);
  FUN_005b44e0(&DAT_0280d340);
  FUN_005b44e0(&DAT_0097baf0);
  _DAT_0080e190 = 0x3f800000;
  DAT_009868c0 = DAT_009868c0 + 1;
  DAT_009868ce = DAT_009868ce + 1;
  DAT_00986a0c = 0;
  _DAT_00986a08 = 0;
  FUN_005fcc80();
  return;
}

