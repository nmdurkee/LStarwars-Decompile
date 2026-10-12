/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x596870; label: FUN_00596870
 */

void FUN_00596870(void)

{
  undefined4 uVar1;
  
  if ((((DAT_008264c4 != '\0') && (DAT_008264bc == 2)) && (DAT_00955b38 != 0)) &&
     (*(int *)(DAT_00955b38 + 0x808) != 0)) {
    uVar1 = FUN_005d0530(1,1);
    FUN_005d05b0();
    FUN_005d0560(DAT_00955b38);
    FUN_005d0650();
    FUN_005d4290(1);
    DAT_009718d8 = 1;
    DAT_009718dc = DAT_00955b38;
    DAT_009718e0 = 0;
    if (*(int *)(PTR_DAT_00802c54 + 0x13c) != 0) {
      FUN_005f5ee0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c));
    }
    FUN_005d0530(0,uVar1);
    FUN_005f3950();
    FUN_005d05b0();
    return;
  }
  return;
}

