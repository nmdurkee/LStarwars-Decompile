/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54f7d0; label: FUN_0054f7d0
 */

void FUN_0054f7d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0;
  param_2[1] = -*(float *)(param_1 + 0x778);
  param_2[2] = 0;
  uVar1 = FUN_006e6b90();
  FUN_005b35a0(param_2,param_2,uVar1);
  FUN_005b3620(param_2,param_2,*(undefined2 *)(param_1 + 0x7a6));
  FUN_005b37d0(param_2,param_2,*(int *)(param_1 + 0x798) + 0x3c);
  return;
}

