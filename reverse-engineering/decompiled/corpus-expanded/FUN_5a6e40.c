/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a6e40; label: FUN_005a6e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a6e40(void)

{
  int iVar1;
  int *piVar2;
  
  if (((*(int *)(PTR_DAT_00802c54 + 300) == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)
      ) && (DAT_00804c64 != -1)) {
    piVar2 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar2;
      if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
         (*(int *)(*(int *)(*(int *)(iVar1 + 0x50) + 0xc) + DAT_00804c64 * 4) != 0)) {
        iVar1 = FUN_005a6ce0(PTR_DAT_00802c54,iVar1 + 0x80,0x40000000);
        if (iVar1 != 0) {
          return 1;
        }
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x93d810);
    return 0;
  }
  return 0;
}

