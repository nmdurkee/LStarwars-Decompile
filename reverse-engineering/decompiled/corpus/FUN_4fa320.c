/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4fa320; label: FUN_004fa320
 */

void FUN_004fa320(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = 0;
  while (DAT_0088ab3c = DAT_0088ab3c + -1, -1 < DAT_0088ab3c) {
    *(undefined1 *)(iVar3 + unaff_EDI) = *(undefined1 *)(DAT_0091ef34 + unaff_EDI);
    iVar3 = iVar3 + 1;
    DAT_0091ef34 = DAT_0091ef34 + 1 & 0x1fff;
    if (iVar3 == param_1) {
      return;
    }
  }
  do {
    while (uVar1 = FUN_004f9820(), 0xff < uVar1) {
      iVar2 = FUN_004f5f30();
      DAT_0091ef34 = (iVar3 - iVar2) - 1U & 0x1fff;
      for (iVar2 = uVar1 - 0xfe; DAT_0088ab3c = iVar2, -1 < iVar2; iVar2 = iVar2 + -1) {
        *(undefined1 *)(iVar3 + unaff_EDI) = *(undefined1 *)(DAT_0091ef34 + unaff_EDI);
        DAT_0091ef34 = DAT_0091ef34 + 1 & 0x1fff;
        iVar3 = iVar3 + 1;
        if (iVar3 == param_1) {
          return;
        }
      }
    }
    *(char *)(iVar3 + unaff_EDI) = (char)uVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 != param_1);
  return;
}

