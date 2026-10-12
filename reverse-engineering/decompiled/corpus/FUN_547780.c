/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547780; label: FUN_00547780
 */

void FUN_00547780(int param_1)

{
  if (((param_1 != 0) || (DAT_00803784 == -1)) || (DAT_00803784 != DAT_0095121c)) {
    DAT_00924890 = DAT_0092488c;
    _memset(DAT_0092488c,0,(size_t)PTR_DAT_007ef020);
    *(undefined4 *)(DAT_029130e4 + 0x10) = *(undefined4 *)(DAT_029130e4 + 0xc);
    *(undefined4 *)(DAT_029130e4 + 0x30) = *(undefined4 *)(DAT_029130e4 + 0x28);
    *(undefined4 *)(DAT_029130e4 + 0x2c) = *(undefined4 *)(DAT_029130e4 + 0x30);
  }
  return;
}

