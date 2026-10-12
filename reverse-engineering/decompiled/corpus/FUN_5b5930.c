/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b5930; label: FUN_005b5930
 */

void FUN_005b5930(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  param_1[1] = param_2[4];
  param_1[4] = uVar1;
  uVar1 = param_2[2];
  param_1[2] = param_2[8];
  param_1[8] = uVar1;
  uVar1 = param_2[6];
  param_1[6] = param_2[9];
  param_1[9] = uVar1;
  *param_1 = *param_2;
  param_1[5] = param_2[5];
  param_1[10] = param_2[10];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  param_1[0xf] = param_2[0xf];
  return;
}

