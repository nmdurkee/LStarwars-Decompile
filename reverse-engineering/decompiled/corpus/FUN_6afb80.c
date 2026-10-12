/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6afb80; label: FUN_006afb80
 */

void FUN_006afb80(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 4);
  if (0 < iVar3 + -6) {
    FUN_006af8b0();
  }
  bVar2 = 1;
  for (iVar3 = iVar3 + -7; 0 < iVar3; iVar3 = iVar3 + -1) {
    iVar1 = 1 << (bVar2 & 0x1f);
    if (0 < iVar1) {
      do {
        FUN_006afa10(4 << (bVar2 & 0x1f));
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    bVar2 = bVar2 + 1;
  }
  if (0 < param_2) {
    iVar3 = (param_2 - 1U >> 5) + 1;
    do {
      FUN_006af680();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

