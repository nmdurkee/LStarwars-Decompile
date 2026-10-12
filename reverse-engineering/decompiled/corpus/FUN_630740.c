/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x630740; label: FUN_00630740
 */

int FUN_00630740(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_029130e4 == 0) {
    return -1;
  }
  if ((DAT_0291311c != 0) && (iVar2 = 0, 0 < *(int *)(DAT_029130e4 + 8))) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_0291311c + iVar2 * 8),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(DAT_029130e4 + 8));
  }
  if (DAT_02913120 != (int *)0x0) {
    iVar2 = *DAT_02913120;
    piVar3 = DAT_02913120;
    while (iVar2 != 0) {
      iVar2 = FUN_004f8b10(*piVar3,param_1);
      if (iVar2 == 0) {
        return piVar3[1];
      }
      piVar3 = piVar3 + 2;
      iVar2 = *piVar3;
    }
  }
  return -1;
}

