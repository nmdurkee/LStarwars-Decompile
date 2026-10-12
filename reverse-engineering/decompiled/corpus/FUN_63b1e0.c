/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x63b1e0; label: FUN_0063b1e0
 */

void FUN_0063b1e0(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_02913818 == 0) {
    iVar4 = 0;
    uVar1 = DAT_0291389c + 4;
    while( true ) {
      uVar3 = DAT_02913824 - 0x8c;
      if (uVar3 < uVar1) {
        uVar3 = DAT_0291389c + 0x4578;
      }
      if ((*(char *)(uVar3 + 0x58) != '\0') && (*(char *)(uVar3 + 0x7a) == -1)) break;
      DAT_02913824 = uVar3 - 0x8c;
      if (DAT_02913824 < uVar1) {
        DAT_02913824 = DAT_0291389c + 0x4578;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      DAT_02913824 = DAT_02913824 - 0x8c;
      if (DAT_02913824 < uVar1) {
        DAT_02913824 = DAT_0291389c + 0x4578;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      DAT_02913824 = DAT_02913824 - 0x8c;
      if (DAT_02913824 < uVar1) {
        DAT_02913824 = DAT_0291389c + 0x4578;
      }
      if ((*(char *)(DAT_02913824 + 0x58) != '\0') && (*(char *)(DAT_02913824 + 0x7a) == -1)) {
        return;
      }
      iVar4 = iVar4 + 4;
      if (0x7f < iVar4) {
        return;
      }
    }
  }
  else {
    uVar3 = *(char *)(DAT_02913824 + 0x7a) * 0x8c + 4 + DAT_0291389c;
    if ((*(char *)(uVar3 + 0x7a) == -1) &&
       (cVar2 = *(char *)(DAT_02913824 + 0x79), uVar3 = DAT_02913824, cVar2 != -1)) {
      do {
        DAT_02913824 = cVar2 * 0x8c + 4 + DAT_0291389c;
        cVar2 = *(char *)(DAT_02913824 + 0x79);
      } while (cVar2 != -1);
      return;
    }
  }
  DAT_02913824 = uVar3;
  return;
}

