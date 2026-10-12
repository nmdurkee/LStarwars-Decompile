/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697700; label: FUN_00697700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00697700(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  param_1 = param_1 * 0x34;
  *(undefined4 *)(param_1 + 0x28 + in_ECX) = param_4;
  *(undefined4 *)(param_1 + 0x2c + in_ECX) = param_5;
  param_1 = param_1 + in_ECX;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  uVar2 = DAT_02972c18;
  *(undefined4 *)(param_1 + 0x30) = param_6;
  uVar1 = DAT_00810dc8;
  *(undefined1 *)(param_1 + 0x24) = 1;
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}

