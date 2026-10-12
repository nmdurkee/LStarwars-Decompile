/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x546f90; label: FUN_00546f90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546f90(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  DAT_0092484c = param_4;
  _DAT_00924848 = param_3;
  DAT_00924850 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_00924850;
  *param_1 = *param_1 + param_4 * 0x4c;
  return;
}

