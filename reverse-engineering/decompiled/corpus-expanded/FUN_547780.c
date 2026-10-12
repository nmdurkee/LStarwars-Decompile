/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547780; label: FUN_00547780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

