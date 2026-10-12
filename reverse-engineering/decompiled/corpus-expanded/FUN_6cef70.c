/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cef70; label: FUN_006cef70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cef70(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00626290(0,&DAT_0081f9a0);
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006ceec0,"Smooth Knot");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006cee50,"Smooth Spline");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006cedf0,"Reverse Spline");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006ceda0,"Re-Gen Points");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627b80(0,&DAT_0081f9a0,*(undefined4 *)(in_ECX + 0x14),0,FUN_006c0670,
                       "Auto-Gen Points");
  FUN_00618e10(param_1,uVar1);
  return;
}

