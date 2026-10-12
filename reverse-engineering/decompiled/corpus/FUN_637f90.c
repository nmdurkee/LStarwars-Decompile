/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x637f90; label: FUN_00637f90
 */

int FUN_00637f90(void)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0291389c != 0) {
    iVar1 = 0;
    piVar2 = (int *)(DAT_0291389c + 0x4618);
    do {
      if (*piVar2 == 0) {
        return iVar1 * 0x4c + 0x4604 + DAT_0291389c;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x13;
    } while (iVar1 < 0x20);
  }
  return 0;
}

