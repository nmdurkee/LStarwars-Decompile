/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x603580; label: FUN_00603580
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00603580(uint *param_1)

{
  undefined4 extraout_EDX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005d6190();
  FUN_005d6180();
  local_4 = 0x3f800000;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = _DAT_0080e258;
  local_8 = _DAT_0080e25c;
  FUN_005b45a0(&DAT_02857230,&local_c);
  local_18 = _DAT_0080e260;
  local_14 = _DAT_0080e264;
  FUN_005b4500(&DAT_028571f0,&local_18);
  *param_1 = *param_1 + 3 & 0xfffffffc;
  FUN_005f7610();
  *param_1 = *param_1 + 0x40;
  return extraout_EDX;
}

