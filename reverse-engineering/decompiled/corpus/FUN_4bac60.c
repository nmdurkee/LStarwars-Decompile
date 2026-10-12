/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bac60; label: FUN_004bac60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bac60(undefined4 param_1,int param_2,int param_3)

{
  undefined2 in_FPUControlWord;
  float10 fVar1;
  float local_20;
  uint local_1c;
  float local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20;
  if (param_3 == 0) {
    if (param_2 != 0) {
      _DAT_007fc3bc = 2.0;
    }
    local_20 = _DAT_00925018 + _DAT_00925018;
    fVar1 = (float10)FUN_0054fad0(_DAT_007fc3bc,0x3f800000,local_20);
    _DAT_007fc3bc = (float)fVar1;
    if (_DAT_00950780 == 0.0) {
      if ((_DAT_007fc3c0 < 1.0) &&
         (_DAT_007fc3c0 = _DAT_00925018 + _DAT_00925018 + _DAT_007fc3c0, 1.0 < _DAT_007fc3c0)) {
        _DAT_007fc3c0 = 1.0;
      }
      _sprintf(local_14,"%d",param_1);
      local_18 = _DAT_007fc3b8 * _DAT_007fc3bc;
      local_20 = (float)CONCAT22(local_20._2_2_,in_FPUControlWord);
      local_1c = (uint)ROUND(_DAT_007fc3c0 * 128.0);
      FUN_0050c780(local_14,0,_DAT_007fc3a0,0x3f800000,local_18,local_18,local_18,0,0xff,0,0xff,
                   local_1c & 0xff);
    }
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
  _DAT_007fc3bc = 1.0;
  _DAT_007fc3c0 = 0.0;
  __security_check_cookie(local_4 ^ (uint)&local_20);
  return;
}

