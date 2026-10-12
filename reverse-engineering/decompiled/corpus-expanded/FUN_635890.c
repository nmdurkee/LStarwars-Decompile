/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635890; label: FUN_00635890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635890(int param_1,float param_2,float param_3)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar1 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar1 != 0) {
      *(float *)(iVar1 + 0x3c) = param_2;
      if (param_3 < param_2) {
        *(float *)(iVar1 + 0x40) = param_2;
        return 1;
      }
      *(float *)(iVar1 + 0x40) = param_3;
      return 1;
    }
  }
  return 0;
}

