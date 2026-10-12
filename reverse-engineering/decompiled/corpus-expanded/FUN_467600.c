/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467600; label: FUN_00467600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00467600(void)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364))
  {
    for (piVar2 = &DAT_0093d7f0; (int)piVar2 < 0x93d7f8; piVar2 = piVar2 + 1) {
      iVar1 = *piVar2;
      if ((((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
          (0.0 < *(float *)(iVar1 + 0xd80))) &&
         ((*(int *)(iVar1 + 0xd14) != 0 && (*(char *)(iVar1 + 0xe2c) == '\0')))) {
        return 1;
      }
    }
  }
  return 0;
}

