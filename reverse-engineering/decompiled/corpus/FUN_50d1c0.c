/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50d1c0; label: FUN_0050d1c0
 */

void FUN_0050d1c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00921ea0;
  if (DAT_00921e90 != 0) {
    DAT_00921ea0 = DAT_00921e90;
    FUN_0050c780(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                 param_11,param_12);
  }
  DAT_00921ea0 = uVar1;
  return;
}

