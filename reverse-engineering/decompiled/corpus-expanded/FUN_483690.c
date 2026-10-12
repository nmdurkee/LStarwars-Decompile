/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x483690; label: FUN_00483690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

