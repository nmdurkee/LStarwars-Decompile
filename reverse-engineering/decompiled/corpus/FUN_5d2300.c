/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2300; label: FUN_005d2300
 */

void FUN_005d2300(int param_1)

{
  int iVar1;
  
  FUN_004f7fb0(param_1);
  iVar1 = FUN_005d1e10(*(undefined4 *)(param_1 + 0x510));
  *(int *)(&DAT_00963e50 + iVar1 * 4) = (int)*(short *)(DAT_00971580 + 0x1b4);
  return;
}

