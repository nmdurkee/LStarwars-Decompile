/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545db0; label: FUN_00545db0
 */

void FUN_00545db0(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  DAT_00924840 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_00924840;
  DAT_00924838 = param_4;
  DAT_0092483c = param_4 * 0x40 + 0xf + *param_1 & 0xfffffff0;
  *param_1 = DAT_0092483c;
  DAT_00924834 = param_3;
  *param_1 = *param_1 + param_3 * 2;
  return;
}

