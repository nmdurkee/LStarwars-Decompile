/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55dd70; label: FUN_0055dd70
 */

void FUN_0055dd70(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  
  *(undefined4 *)(param_1 + 0xefc) = param_2;
  *(undefined1 *)(param_1 + 0xf00) = param_3;
  uVar1 = DAT_00802b64;
  *(undefined4 *)(param_1 + 0xf04) = param_5;
  *(undefined1 *)(param_1 + 0xf01) = uVar1;
  return;
}

