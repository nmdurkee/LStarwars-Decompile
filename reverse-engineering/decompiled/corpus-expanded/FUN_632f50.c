/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x632f50; label: FUN_00632f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

