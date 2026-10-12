/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6bebd0; label: FUN_006bebd0
 */

float10 FUN_006bebd0(void)

{
  int iVar1;
  int in_ECX;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 1.0;
  iVar1 = FUN_005cfac0(in_ECX + 0x18);
  if (iVar1 != 0) {
    FUN_005d0260(in_ECX + 0x18,local_c,&local_10);
  }
  return (float10)local_10;
}

