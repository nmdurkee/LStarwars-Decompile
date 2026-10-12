/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd3f0; label: FUN_005fd3f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd3f0(void)

{
  if (DAT_02854c38 == 0) {
    DAT_02854b88 = DAT_02854c34 + DAT_00992290;
    DAT_0097c1ac = DAT_00992290;
  }
  else if (DAT_02854c38 == 1) {
    DAT_02854b88 = DAT_028490ec + DAT_02854c34;
    DAT_0097c1ac = DAT_028490ec;
  }
  if ((DAT_0097c1ac & 0xf) != 0) {
    DAT_0097c1ac = DAT_0097c1ac + 0xf & 0xfffffff0;
  }
  return;
}

