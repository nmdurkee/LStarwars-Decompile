/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621220; label: FUN_00621220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621220(void)

{
  int iVar1;
  
  iVar1 = DAT_0080f884;
  if (DAT_0080f884 != -1) {
    _memset(&DAT_029110b8,0,0x1000);
    if ((DAT_02912f3c != 0) && (DAT_02912f3c == 1)) {
      FUN_004fb550(iVar1,&DAT_029110b8,0x1000);
      DAT_02900a5c = 0;
    }
  }
  return;
}

