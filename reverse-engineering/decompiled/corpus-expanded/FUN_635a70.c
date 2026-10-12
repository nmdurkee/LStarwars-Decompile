/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635a70; label: FUN_00635a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635a70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _DAT_02913970 = FUN_005470f0(param_3,0x8c,param_1,param_2,0x10);
  DAT_02913974 = param_3;
  _DAT_02913978 = 0;
  return param_3;
}

