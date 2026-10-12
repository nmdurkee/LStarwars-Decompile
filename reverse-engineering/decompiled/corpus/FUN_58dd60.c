/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58dd60; label: FUN_0058dd60
 */

void FUN_0058dd60(int param_1)

{
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffeffff;
  *(undefined4 *)(param_1 + 0xd3c) = 0;
  *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) & 0xffffffef;
  *(undefined1 *)(param_1 + 0xe33) = 0;
  return;
}

