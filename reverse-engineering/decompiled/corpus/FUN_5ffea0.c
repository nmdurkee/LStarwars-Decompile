/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffea0; label: FUN_005ffea0
 */

void FUN_005ffea0(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + -4 + param_2 * 4);
  *puVar1 = 0x52;
  *(undefined4 *)(puVar1 + 4) = 0;
  param_2 = param_2 + -2;
  while (-1 < param_2) {
    param_2 = param_2 + -1;
    puVar1 = *(undefined1 **)(param_1 + 4 + param_2 * 4);
    *puVar1 = 0x4e;
    *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_1 + 8 + param_2 * 4);
  }
  return;
}

