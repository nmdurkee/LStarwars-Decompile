/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x594600; label: FUN_00594600
 */

void FUN_00594600(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined2 param_4,
                 undefined4 param_5)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_0095587c;
  param_3[4] = param_5;
  *param_3 = uVar2;
  uVar1 = (undefined2)DAT_00955878;
  *(undefined2 *)(param_3 + 1) = param_4;
  *(undefined2 *)((int)param_3 + 6) = uVar1;
  param_3[3] = param_1;
  param_3[2] = param_2;
  return;
}

