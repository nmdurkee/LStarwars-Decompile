/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x637e10; label: FUN_00637e10
 */

int FUN_00637e10(void)

{
  int iVar1;
  char *pcVar2;
  
  if (DAT_0291389c != 0) {
    iVar1 = 0;
    pcVar2 = (char *)(DAT_0291389c + 0x5c);
    do {
      if (*pcVar2 == '\0') {
        return iVar1 * 0x8c + 4 + DAT_0291389c;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x8c;
    } while (iVar1 < 0x80);
  }
  return 0;
}

