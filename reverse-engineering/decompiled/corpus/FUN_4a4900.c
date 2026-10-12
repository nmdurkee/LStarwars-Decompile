/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a4900; label: FUN_004a4900
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4900(int param_1,int param_2,float param_3,undefined4 param_4)

{
  DAT_0087b8c8 = param_1;
  if (param_1 != 0) {
    param_2 = param_1 + 0x80;
  }
  _DAT_0087b890 = param_3;
  DAT_0087b8cc = param_2;
  DAT_0087b8d0 = param_4;
  _DAT_0087b894 = param_3 * param_3;
  return;
}

