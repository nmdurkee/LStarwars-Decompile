/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46d780; label: FUN_0046d780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046d780(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 != 0) {
    FUN_0046d270(param_3,0,param_4);
    return;
  }
  uVar1 = FUN_0046c4f0(0,0,param_1,&DAT_00802500,0x40a00000,param_2,0x3f800000,0x49f42400,0,1,0);
  FUN_0046d270(param_3,uVar1);
  return;
}

