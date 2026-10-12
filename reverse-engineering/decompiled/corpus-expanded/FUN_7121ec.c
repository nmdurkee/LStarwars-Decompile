/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x7121ec; label: FUN_007121ec
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007121ec(_LDOUBLE *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  _LDBL12 local_14;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  FUN_00711b2c(&local_14,param_2,param_3,param_4,0,0,0,param_5);
  __ld12told(&local_14,param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

