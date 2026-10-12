/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe5a0; label: FUN_005fe5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

