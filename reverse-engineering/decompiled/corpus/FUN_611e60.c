/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611e60; label: FUN_00611e60
 */

void FUN_00611e60(void)

{
  int iVar1;
  undefined2 *in_ECX;
  
  iVar1 = FUN_006be780(*(undefined4 *)(in_ECX + 8));
  if (0 < *(int *)(&DAT_02867f1c + iVar1 * 4)) {
    FUN_006334d0(*(undefined4 *)(in_ECX + 10),*(int *)(&DAT_02867f1c + iVar1 * 4));
    *(undefined4 *)(in_ECX + 10) = 0;
  }
  in_ECX[1] = 0;
  *(undefined4 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *in_ECX = 0;
  return;
}

