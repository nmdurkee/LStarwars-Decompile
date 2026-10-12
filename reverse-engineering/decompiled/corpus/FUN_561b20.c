/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561b20; label: FUN_00561b20
 */

void FUN_00561b20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 local_4;
  
  if (param_7 == 0) {
    local_4 = 0xbf;
    param_7 = 0;
  }
  else {
    param_7 = 0xff;
    local_4 = 0xff;
  }
  FUN_00561a00(param_1,param_2,param_3,param_4,param_5,param_6,0xff,local_4,param_7);
  return;
}

