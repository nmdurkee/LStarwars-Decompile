/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x603350; label: FUN_00603350
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00603350(undefined4 param_1,undefined4 param_2)

{
  FUN_005fd1c0();
  DAT_009739b8 = 0;
  DAT_00973e60 = 0;
  DAT_00973ecc = 0;
  DAT_00973fa8 = 0;
  DAT_00973e80 = &DAT_00973eb4;
  FUN_005efbf0(param_1,param_2);
  DAT_00973e30 = DAT_00973e30 | 0x10;
  _DAT_00973e38 = 0;
  FUN_005deb20(param_1,param_2,0x40);
  DAT_009736e0 = &DAT_0097c1ac;
  _DAT_00971578 = DAT_02854b88;
  DAT_00973fa4 = FUN_004ffa60();
  FUN_005f0d70();
  FUN_005dfab0();
  return;
}

