/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58d8e0; label: FUN_0058d8e0
 */

void FUN_0058d8e0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if ((cVar1 != -1) && ((cVar1 == DAT_00802864 || (cVar1 == DAT_00802868)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffeffff;
  *(undefined4 *)(param_1 + 0xd3c) = 0;
  *(undefined1 *)(param_1 + 0xe33) = 0;
  return;
}

