/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635900; label: FUN_00635900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635900(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar1 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_2 == (undefined4 *)0x0) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0x24) = *param_2;
      *(undefined4 *)(iVar1 + 0x28) = param_2[1];
      *(undefined4 *)(iVar1 + 0x2c) = param_2[2];
      if (param_3 == (undefined4 *)0x0) {
        return 1;
      }
    }
    *(undefined4 *)(iVar1 + 0x30) = *param_3;
    *(undefined4 *)(iVar1 + 0x34) = param_3[1];
    *(undefined4 *)(iVar1 + 0x38) = param_3[2];
    return 1;
  }
  return 0;
}

