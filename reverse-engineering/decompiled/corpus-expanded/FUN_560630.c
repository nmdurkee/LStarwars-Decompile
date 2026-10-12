/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x560630; label: FUN_00560630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

