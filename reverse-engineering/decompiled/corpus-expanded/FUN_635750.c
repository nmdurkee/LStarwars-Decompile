/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635750; label: FUN_00635750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00635750(int param_1)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar1 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar1 != 0) {
      FUN_005474d0(iVar1);
      _DAT_02913978 = _DAT_02913978 + -1;
    }
  }
  return;
}

