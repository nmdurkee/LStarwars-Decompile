/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x632f50; label: FUN_00632f50
 */

void FUN_00632f50(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_EBX;
  undefined4 unaff_retaddr;
  
  FUN_006326b0(param_6);
  (**(code **)(*(int *)*param_1 + 0x104))((int *)*param_1,0,param_1[0x13]);
  FUN_006323a0(unaff_EBX,unaff_retaddr,param_1,param_2,param_1[5],param_1[6],param_3);
  return;
}

