/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c05d0; label: FUN_006c05d0
 */

void FUN_006c05d0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  if (0 < *(int *)(in_ECX + 0x10)) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      FUN_006ba8a0(*(int *)(in_ECX + 0x14) + iVar1,0x3f000000,0xffffffff);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar2 < *(int *)(in_ECX + 0x10));
  }
  return;
}

