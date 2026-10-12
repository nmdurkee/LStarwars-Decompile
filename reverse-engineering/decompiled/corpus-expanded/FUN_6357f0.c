/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6357f0; label: FUN_006357f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006357f0(int param_1,int param_2)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    if (param_2 - 1U < 8) {
      iVar1 = FUN_00547560(_DAT_02913970,param_1);
      if (iVar1 != 0) {
        *(char *)(iVar1 + 0x58) = (char)param_2;
        return 1;
      }
    }
    return 0;
  }
  return 0;
}

