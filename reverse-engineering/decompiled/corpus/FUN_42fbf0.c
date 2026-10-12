/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42fbf0; label: FUN_0042fbf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042fbf0(undefined4 param_1)

{
  int iVar1;
  undefined1 local_60 [12];
  undefined4 local_54;
  undefined1 local_50 [16];
  float local_40;
  
  local_54 = 0;
  _memset(local_50,0,0x50);
  if (((DAT_00951be8 == 0) || ((*(byte *)(DAT_00951be8 + 0x50) & 0x80) == 0)) &&
     (*(int *)(PTR_DAT_00802c54 + 0x2aac) != 0)) {
    FUN_0063c710(*(undefined4 *)(PTR_DAT_00802c54 + 0x2aac),&local_54,&DAT_00973718,_DAT_00925018);
  }
  if (0.0 < local_40) {
    FUN_005d4e70(param_1,&local_54);
  }
  iVar1 = FUN_0055e340(local_60,0);
  if (((iVar1 != 0) || (DAT_00951b50 != 0)) && (*(int *)(DAT_00955b38 + 0x808) != 0)) {
    FUN_005d5170(0,*(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0x24));
    FUN_005d5170(1,*(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0x28));
    FUN_005d5170(2,*(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0x2c));
    FUN_005d5160();
  }
  return;
}

