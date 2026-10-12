/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x652b60; label: FUN_00652b60
 */

void FUN_00652b60(undefined4 param_1,int param_2)

{
  DAT_008104b0 = param_1;
  if (((DAT_00810490 == 0xb) || (DAT_00810490 == 0xc)) || (DAT_00810490 == 0xd)) {
    DAT_00810490 = (ushort)(param_2 == 0xd) * 2 + 0xb;
  }
  return;
}

