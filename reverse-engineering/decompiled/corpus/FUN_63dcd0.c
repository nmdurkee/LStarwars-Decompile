/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x63dcd0; label: FUN_0063dcd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063dcd0(float param_1)

{
  undefined2 local_4;
  
  local_4 = (short)(int)ROUND(_DAT_0080fea0 * param_1);
  DAT_02913990._0_2_ = (short)DAT_02913990 + local_4;
  FUN_005d8370(0,6);
  return;
}

