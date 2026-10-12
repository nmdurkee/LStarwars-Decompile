/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fe5a0; label: FUN_005fe5a0
 */

undefined * FUN_005fe5a0(int param_1)

{
  size_t _Size;
  int iVar1;
  
  _Size = param_1 * 4 + 0x204;
  DAT_0080e1a8 = DAT_0080e1a8 - _Size;
  if (DAT_0080e1a8 < 0) {
    FUN_005f7490();
    return (undefined *)0x0;
  }
  iVar1 = DAT_0080e1a8 * 0x208;
  _memset(&DAT_00992298 + iVar1,0,_Size);
  return &DAT_00992298 + iVar1;
}

