/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63bd80; label: FUN_0063bd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

