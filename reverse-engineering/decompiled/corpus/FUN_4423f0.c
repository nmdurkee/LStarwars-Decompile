/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4423f0; label: FUN_004423f0
 */

int FUN_004423f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_2 != 0) && (param_1 != 0)) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
     (iVar3 = 0, 0 < DAT_00951b84)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(param_2,iVar2 + 0x40 + DAT_00951b78);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x130;
    } while (iVar3 < DAT_00951b84);
  }
  return -1;
}

