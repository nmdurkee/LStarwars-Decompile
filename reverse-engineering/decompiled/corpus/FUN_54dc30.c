/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54dc30; label: FUN_0054dc30
 */

undefined4 FUN_0054dc30(void)

{
  int in_ECX;
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = (int)*(char *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x10a);
  if ((iVar1 == -1) || (*(int *)(*(int *)(in_ECX + 0x50) + 0x14 + iVar1 * 4) == 0)) {
    if ((*(byte *)(*(int *)(in_ECX + 0x798) + 0x1e) & 4) != 0) {
      *unaff_ESI = in_ECX + 0x80;
      return 1;
    }
    *unaff_ESI = in_ECX + 400;
  }
  else {
    *unaff_ESI = iVar1 * 0x40 + 0x834 + in_ECX;
    iVar1 = (int)*(char *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x10b);
    if ((iVar1 != -1) && (*(int *)(*(int *)(in_ECX + 0x50) + 0x14 + iVar1 * 4) != 0)) {
      unaff_ESI[1] = iVar1 * 0x40 + 0x834 + in_ECX;
      return 2;
    }
  }
  return 1;
}

