/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522970; label: FUN_00522970
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00522970(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  if (((unaff_EDI != 0) && (*(short *)(unaff_EDI + 0x36) < 0xfe)) &&
     (iVar2 = FUN_004f1440(DAT_009238e4 + 0x3187c), iVar2 != 0)) {
    FUN_004f1410(DAT_009238e4 + 0x3187c,iVar2);
    FUN_004f1310(unaff_EDI + 0x18,iVar2);
    *(short *)(unaff_EDI + 0x36) = *(short *)(unaff_EDI + 0x36) + 1;
    iVar1 = DAT_009238e4;
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(DAT_009238e4 + 0x28);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x30);
    *(undefined4 *)(iVar2 + 0x24) = _DAT_00801c54;
    *(float *)(iVar2 + 0x28) = -_DAT_00801c58;
    *(float *)(iVar2 + 0x2c) = _DAT_00801c58;
  }
  return iVar2;
}

