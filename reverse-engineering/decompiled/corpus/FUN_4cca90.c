/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cca90; label: FUN_004cca90
 */

int FUN_004cca90(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(PTR_DAT_00802c54 + 0x507c)) {
      iVar1 = *(int *)(PTR_DAT_00802c54 + 0x5078);
      do {
        if ((*(char *)(iVar1 + 0x37) == '\x01') && (*(int *)(iVar1 + 0x6c) == param_1)) {
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x70;
      } while (iVar2 < *(int *)(PTR_DAT_00802c54 + 0x507c));
    }
  }
  return 0;
}

