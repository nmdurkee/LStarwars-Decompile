/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x560630; label: FUN_00560630
 */

void FUN_00560630(void)

{
  int iVar1;
  bool bVar2;
  
  FUN_006df940();
  if ((PTR_DAT_00802c58 == PTR_DAT_00802c54) &&
     (((DAT_00803784 == -1 || ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 8) == 0)) &&
      (bVar2 = PTR_DAT_00802c58 != &DAT_0093d858, PTR_DAT_00802c58 = &DAT_00942a04, bVar2)))) {
    PTR_DAT_00802c58 = &DAT_0093d858;
  }
  iVar1 = FUN_0055ffb0(PTR_DAT_00802c58,DAT_0093d848);
  if (iVar1 != 0) {
    DAT_0093d84c = DAT_0093d848;
    FUN_0048ce00(PTR_DAT_00802c58);
  }
  DAT_0093d84c = 0xffffffff;
  if (*(int *)(PTR_DAT_00802c58 + 0x110) != 0) {
    DAT_00802c68 = DAT_0093d848;
  }
  return;
}

