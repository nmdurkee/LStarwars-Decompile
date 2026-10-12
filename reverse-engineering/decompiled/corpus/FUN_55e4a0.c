/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e4a0; label: FUN_0055e4a0
 */

void FUN_0055e4a0(int param_1,undefined4 param_2)

{
  if (DAT_0093d828 != (code *)0x0) {
    (*DAT_0093d828)(param_1,param_2);
  }
  FUN_005b2cf0(param_1);
  FUN_005999a0(param_1);
  FUN_0058b0f0(param_1);
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffff3ff;
  return;
}

