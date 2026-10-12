/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x6213e0; label: FUN_006213e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006213e0(void)

{
  DAT_02912f40 = 0;
  if (DAT_0080f884 != -1) {
    if (DAT_02912f44 != 0) {
      FUN_006213a0();
    }
    if ((DAT_02912f3c != 0) && (DAT_02912f3c == 1)) {
      FUN_004f99e0(DAT_0080f884);
      DAT_0080f884 = 0xffffffff;
      DAT_02912f3c = 0;
      return 1;
    }
  }
  return 0;
}

