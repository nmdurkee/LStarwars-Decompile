/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5f9980; label: FUN_005f9980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f9980(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_02854bf4 = *param_1;
  DAT_02854bf8 = param_1[1];
  _DAT_00973fe0 = param_3;
  DAT_02854bfc = param_1[2];
  _DAT_00973fe4 = param_4;
  DAT_02854c00 = (param_2 >> 1 & 0x7f7f7f) + (param_2 & 0xff000000) * 2;
  return;
}

