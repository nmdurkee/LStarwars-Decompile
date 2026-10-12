/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x7121ec; label: FUN_007121ec
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

