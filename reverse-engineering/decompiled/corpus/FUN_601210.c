/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x601210; label: FUN_00601210
 */

void FUN_00601210(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x1d0 + param_2 * 8) = param_3;
  *(undefined4 *)(param_1 + 0x1d4 + param_2 * 8) = param_4;
  return;
}

