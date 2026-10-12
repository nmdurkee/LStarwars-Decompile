/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61ee00; label: FUN_0061ee00
 */

void FUN_0061ee00(int param_1,undefined4 *param_2)

{
  undefined4 *extraout_EDX;
  
  param_2[1] = *(undefined4 *)(param_1 + 0x50);
  if (*(undefined4 **)(param_1 + 0x50) != (undefined4 *)0x0) {
    **(undefined4 **)(param_1 + 0x50) = param_2;
  }
  *(undefined4 **)(param_1 + 0x50) = param_2;
  if (*(int *)(param_1 + 0x4c) == 0) {
    *(undefined4 **)(param_1 + 0x4c) = param_2;
  }
  *param_2 = 0;
  if (param_2[2] == 0x13) {
    FUN_0061edb0(param_2,*(int *)(param_1 + 100) + 1);
    param_2 = extraout_EDX;
  }
  if (param_2[2] == 0x11) {
    param_2[0x1b] = *(int *)(param_1 + 100) + 1;
  }
  return;
}

