/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3440; label: FUN_005f3440
 */

undefined4 FUN_005f3440(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_40 [64];
  
  if (*param_1 == 0) {
    return 0;
  }
  if (param_1[2] != 0) {
    FUN_005b5430(local_40,param_1[2],param_2);
    uVar1 = FUN_005f0f00(param_1,local_40,0,0,0);
    return uVar1;
  }
  FUN_005b5430(local_40,param_1[1],param_2);
  uVar1 = FUN_005fe970(*(undefined4 *)
                        (*(int *)(*param_1 + 0x18) +
                        *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4),local_40);
  return uVar1;
}

