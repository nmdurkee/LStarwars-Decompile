/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522c30; label: FUN_00522c30
 */

void FUN_00522c30(void)

{
  int iVar1;
  undefined4 local_4;
  
  iVar1 = FUN_00522b60(&local_4,0,0);
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_009238e4 + 0x4868) = local_4;
    *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = iVar1;
    FUN_00620f10(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x18);
  }
  return;
}

