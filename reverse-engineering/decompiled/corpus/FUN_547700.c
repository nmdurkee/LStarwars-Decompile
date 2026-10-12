/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547700; label: FUN_00547700
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547700(void)

{
  DAT_0092487c = DAT_00924878 + 3U & 0xfffffffc;
  _DAT_0092486c = DAT_0092487c - DAT_00924874;
  DAT_00924890 = DAT_0092487c;
  DAT_0092488c = DAT_0092487c;
  DAT_00924894 = PTR_DAT_007ef020 + DAT_0092487c;
  DAT_0093d960 = DAT_00924894 + ((uint)(DAT_009248ac - (int)DAT_00924894) >> 1);
  DAT_00942b0c = DAT_009248ac;
  _DAT_009248a8 = DAT_00924894;
  _DAT_009248a4 = DAT_00924894;
  _DAT_0093d95c = DAT_00924894;
  _DAT_0093d958 = DAT_00924894;
  _DAT_00942b08 = DAT_0093d960;
  _DAT_00942b04 = DAT_0093d960;
  _DAT_009248b0 = DAT_009248ac - _DAT_009248b4;
  return;
}

