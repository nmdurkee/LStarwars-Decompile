/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7230; label: FUN_005d7230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7230(char *param_1)

{
  int iVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    param_1 = s_unknown_0080b9ec;
  }
  _vsprintf(DAT_0096e574,param_1,&stack0x00000008);
  iVar1 = FUN_004f1ff0(DAT_0096e574);
  DAT_0096e574 = DAT_0096e574 + iVar1;
  if (DAT_00971890 < DAT_0096e574) {
    FUN_004f0750(DAT_00973968,&DAT_009720b8);
    DAT_0096e574 = &DAT_009720b8;
    DAT_00971890 = &DAT_00972cb8;
  }
  return;
}

