/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561a00; label: FUN_00561a00
 */

void FUN_00561a00(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,
                 undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_6 != 0) {
    FUN_00547930(0x2c,0,0,0);
    FUN_00547930(0x26,0,0,0);
    FUN_0054a910(0x3f333333,0,0,0);
    FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
  }
  param_4 = param_4 + param_4;
  local_c = param_2;
  local_8 = param_3;
  local_4 = 0x3f800000;
  FUN_00560fa0(param_1,&local_c,param_4,&local_c,param_4 * 0.5 + param_4,param_7,param_8,param_9,
               0x4020,param_5);
  FUN_00560fa0(param_1,&local_c,param_4,&local_c,param_4 - param_4 * 0.5,param_7,param_8,param_9,
               0x4020,param_5);
  return;
}

