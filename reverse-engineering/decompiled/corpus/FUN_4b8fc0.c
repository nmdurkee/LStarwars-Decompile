/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b8fc0; label: FUN_004b8fc0
 */

undefined4 FUN_004b8fc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x800) != 0) {
    return 1;
  }
  iVar2 = 0x4c;
  do {
    if (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + iVar2) != 0) {
      iVar1 = FUN_00552020(param_1 + 0x80,*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + iVar2),0,0,
                           0);
      if (iVar1 == 0) {
        return 1;
      }
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x5d);
  return 0;
}

