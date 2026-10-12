/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x6219d0; label: FUN_006219d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006219d0(void)

{
  DAT_02912f3c = 2;
  if (DAT_0080f884 == -1) {
    _memset(&DAT_029110b8,0,0x1000);
    DAT_02900a5c = 0;
    _DAT_02910ca0 = 0;
    _DAT_02910c9c = 0;
    DAT_02912f44 = 0;
    DAT_0080f884 = -1;
  }
  return 0;
}

