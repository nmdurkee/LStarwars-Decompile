/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea2c0; label: FUN_005ea2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea2c0(undefined4 *param_1,undefined4 param_2,float param_3,int param_4,
                 undefined4 param_5,int param_6,int param_7,undefined4 *param_8)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    param_1 = DAT_00973880;
  }
  *param_1 = *(undefined4 *)(param_7 + 0x168);
  if (param_6 == 0) {
    iVar1 = *(int *)(param_7 + 0x168);
  }
  else {
    iVar1 = FUN_005ca550(param_7,param_6);
    iVar1 = iVar1 + 1;
  }
  if (param_4 == 0) {
    FUN_005cdd50(param_2,param_3 - 1.0,param_1,param_5,iVar1 - param_6,param_6,param_8);
  }
  else {
    FUN_005cc0d0(param_2,param_3 - 1.0,param_1,iVar1 - param_6,param_6);
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = *(undefined4 *)param_1[2];
      param_8[1] = *(undefined4 *)(param_1[2] + 4);
      param_8[2] = -*(float *)(param_1[2] + 8);
      return;
    }
  }
  return;
}

