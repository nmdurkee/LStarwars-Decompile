/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5db980; label: FUN_005db980
 */

void FUN_005db980(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  
  FUN_00607d70(0x10,7,param_11);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_6;
  *(undefined4 *)(iVar1 + 0x14) = param_7;
  FUN_005c1f70();
  FUN_006009e0(param_1,param_2,0);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_8;
  *(undefined4 *)(iVar1 + 0x14) = param_9;
  FUN_005c1f70();
  FUN_006009e0(param_1 + param_4,param_2 + param_5,0);
  FUN_006009a0();
  return;
}

