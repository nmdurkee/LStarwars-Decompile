/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49e990; label: FUN_0049e990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0049e990(void)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364))
  {
    return 0;
  }
  piVar2 = &DAT_0093d7f0;
  do {
    iVar1 = *piVar2;
    if (iVar1 != 0) {
      if ((*(uint *)(*(int *)(iVar1 + 0x54) + 4) & 0x2000) != 0) {
        return 0;
      }
      if (((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0) && ((*(byte *)(iVar1 + 0xeec) & 1) != 0)) {
        iVar1 = *(int *)(*(int *)(iVar1 + 0x50) + 0xc);
        if (*(int *)(iVar1 + 0x13c) != 0) {
          return 1;
        }
        if (*(int *)(iVar1 + 0x98) != 0) {
          return 1;
        }
      }
    }
    piVar2 = piVar2 + 1;
    if (0x93d80f < (int)piVar2) {
      return 0;
    }
  } while( true );
}

