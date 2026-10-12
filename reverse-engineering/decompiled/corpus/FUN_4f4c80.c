/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f4c80; label: FUN_004f4c80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f4c80(void)

{
  if (DAT_0297dc2c != 0) {
    DAT_0297dc2c = 0;
  }
  if (DAT_0297dc08 == 1) {
    *DAT_0297dc14 = _DAT_0297dbfc;
    DAT_0297dc14 = DAT_0297dc14 + 1;
    if (DAT_0297dc14 <= DAT_0297dc10 + -0x610) {
      return;
    }
  }
  else {
    if (DAT_0297dc08 != 2) {
      return;
    }
    if (DAT_0297dc14 != DAT_0297dc10) {
      _DAT_0297dbfc = *DAT_0297dc14;
      DAT_0297dc14 = DAT_0297dc14 + 1;
      return;
    }
  }
  DAT_0297dc08 = 0;
  return;
}

