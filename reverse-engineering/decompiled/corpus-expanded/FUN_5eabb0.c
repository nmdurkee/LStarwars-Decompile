/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eabb0; label: FUN_005eabb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eabb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    if (((byte)DAT_009738c4 & 2) == 0) {
      iVar1 = *(int *)(param_1 + 0x40) + 4;
    }
    else {
      iVar1 = 0;
    }
    FUN_005d10e0(iVar1,param_1,param_2,param_3,param_4);
  }
  return;
}

