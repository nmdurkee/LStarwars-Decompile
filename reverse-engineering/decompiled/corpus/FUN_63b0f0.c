/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x63b0f0; label: FUN_0063b0f0
 */

void FUN_0063b0f0(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_02913818 == 0) {
    iVar2 = 0;
    uVar1 = DAT_0291389c + 0x4604;
    while( true ) {
      DAT_02913824 = DAT_02913824 + 0x8c;
      if (uVar1 <= DAT_02913824) {
        DAT_02913824 = DAT_0291389c + 4;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) break;
      DAT_02913824 = DAT_02913824 + 0x8c;
      if (uVar1 <= DAT_02913824) {
        DAT_02913824 = DAT_0291389c + 4;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      DAT_02913824 = DAT_02913824 + 0x8c;
      if (uVar1 <= DAT_02913824) {
        DAT_02913824 = DAT_0291389c + 4;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      DAT_02913824 = DAT_02913824 + 0x8c;
      if (uVar1 <= DAT_02913824) {
        DAT_02913824 = DAT_0291389c + 4;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      iVar2 = iVar2 + 4;
      if (0x7f < iVar2) {
        return;
      }
    }
  }
  else {
    if (*(char *)(DAT_02913824 + 0x79) != -1) {
      DAT_02913824 = *(char *)(DAT_02913824 + 0x79) * 0x8c + 4 + DAT_0291389c;
      return;
    }
    uVar1 = DAT_02913824;
    if (*(char *)(DAT_02913824 + 0x7a) != -1) {
      do {
        DAT_02913824 = uVar1;
        iVar2 = *(char *)(uVar1 + 0x7a) * 0x8c;
        uVar1 = iVar2 + 4 + DAT_0291389c;
      } while (*(char *)(iVar2 + 0x7e + DAT_0291389c) != -1);
      return;
    }
  }
  return;
}

