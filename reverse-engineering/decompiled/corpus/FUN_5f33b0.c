/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f33b0; label: FUN_005f33b0
 */

undefined4 FUN_005f33b0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (param_1[2] != 0)) {
    uVar1 = FUN_005f0f00(param_1,param_2,0,0,0);
    return uVar1;
  }
  return 0;
}

