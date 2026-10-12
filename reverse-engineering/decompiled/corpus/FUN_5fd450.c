/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fd450; label: FUN_005fd450
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

