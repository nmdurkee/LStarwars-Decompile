/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635fc0; label: FUN_00635fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00635fc0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004fa5f0(param_1,1);
  if (iVar1 != 0) {
    FUN_004f03d0(iVar1,param_2,0x4f84);
    FUN_004f99e0(iVar1);
  }
  return;
}

