/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd450; label: FUN_005fd450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd450(void)

{
  if (DAT_02854c38 == 0) {
    DAT_0280a2ec = DAT_0097c1ac - DAT_00992290;
  }
  else if (DAT_02854c38 == 1) {
    DAT_0280a2ec = DAT_0097c1ac - DAT_028490ec;
  }
  if (DAT_028490dc < DAT_0280a2ec) {
    DAT_028490dc = DAT_0280a2ec;
  }
  if (DAT_02854c34 < DAT_0280a2ec) {
    FUN_005f7490();
    DebugBreak();
  }
  DAT_02854c38 = DAT_02854c38 + 1 & 0x80000001;
  if ((int)DAT_02854c38 < 0) {
    DAT_02854c38 = (DAT_02854c38 - 1 | 0xfffffffe) + 1;
  }
  FUN_005fd3f0();
  return;
}

