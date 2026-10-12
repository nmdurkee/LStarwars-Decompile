/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635840; label: FUN_00635840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635840(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    puVar1 = (undefined4 *)FUN_00547560(_DAT_02913970,param_1);
    if ((puVar1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
      return 1;
    }
  }
  return 0;
}

