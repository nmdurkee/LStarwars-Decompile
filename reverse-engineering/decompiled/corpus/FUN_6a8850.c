/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a8850; label: FUN_006a8850
 */

undefined4 FUN_006a8850(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  _memset(param_1,0,0x2c);
  param_1[3] = param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[1];
  *param_1 = *param_2;
  uVar1 = FUN_006a7fd0(param_2[2],param_2[1],0);
  param_1[5] = uVar1;
  uVar1 = FUN_006a81d0(param_2,param_2[1],0);
  param_1[4] = uVar1;
  return 0;
}

