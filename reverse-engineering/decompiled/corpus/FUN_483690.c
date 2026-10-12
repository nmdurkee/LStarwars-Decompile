/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483690; label: FUN_00483690
 */

int FUN_00483690(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (*(int *)(DAT_0087a600 + 0xc) != -1) {
    iVar2 = *(int *)(DAT_0087a600 + 0xc);
    do {
      if (iVar2 == param_1) {
        return iVar1 * 0x20 + DAT_0087a600;
      }
      iVar1 = iVar1 + 1;
      iVar2 = *(int *)(iVar1 * 0x20 + 0xc + DAT_0087a600);
    } while (iVar2 != -1);
  }
  return 0;
}

