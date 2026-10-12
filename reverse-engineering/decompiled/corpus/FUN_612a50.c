/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612a50; label: FUN_00612a50
 */

undefined4 FUN_00612a50(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if (-1 < iVar1) {
    iVar2 = 0;
    if (*(int *)(in_ECX + 0x2c) < 0) {
      *(int *)(in_ECX + 0x2c) = iVar1 << 10;
      if (iVar1 << 10 == 0) {
        *(undefined4 *)(in_ECX + 0x2c) = 1;
      }
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
    }
    iVar1 = iVar1 * 0x400;
    do {
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
      iVar2 = iVar2 + 1;
      if ((iVar1 + 0x400 <= *(int *)(in_ECX + 0x2c)) &&
         (*(int *)(in_ECX + 0x2c) = iVar1, iVar1 == 0)) {
        *(undefined4 *)(in_ECX + 0x2c) = 1;
      }
      if (*(int *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x2c) * 0x18) == 0) {
        if (0x3ff < iVar2) {
          return 0;
        }
        return *(undefined4 *)(in_ECX + 0x2c);
      }
    } while (iVar2 < 0x400);
  }
  return 0;
}

