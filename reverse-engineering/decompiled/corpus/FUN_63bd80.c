/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x63bd80; label: FUN_0063bd80
 */

int FUN_0063bd80(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((DAT_0080fe18 == -1) || (DAT_0080fe18 == 0x1f)) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_0080fe18 + 1;
  }
  if (DAT_0291389c != 0) {
    for (; iVar1 != DAT_0080fe18; iVar1 = iVar1 + 1) {
      if (*(int *)(iVar1 * 0x4c + 0x4618 + DAT_0291389c) != 0) {
        DAT_0080fe18 = iVar1;
        return iVar1 * 0x4c + 0x4604 + DAT_0291389c;
      }
      if (0x1f < iVar1) {
        iVar1 = -1;
      }
      iVar2 = iVar2 + 1;
      if (0x1f < iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

