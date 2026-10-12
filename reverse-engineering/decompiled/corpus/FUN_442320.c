/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x442320; label: FUN_00442320
 */

int FUN_00442320(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_2 != 0) && (param_1 != 0)) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) {
    iVar1 = *(int *)(PTR_DAT_00802c54 + 300);
    iVar2 = 0;
    if (*(char *)(iVar1 + 0x7d) != '\0') {
      iVar3 = 0x60;
      do {
        iVar1 = FUN_004f8b10(param_2,*(short *)(iVar3 + iVar1) * 0x130 + 0x40 + DAT_00951b78);
        if (iVar1 == 0) {
          return iVar2;
        }
        iVar1 = *(int *)(PTR_DAT_00802c54 + 300);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 2;
      } while (iVar2 < (int)(uint)*(byte *)(iVar1 + 0x7d));
    }
  }
  return -1;
}

