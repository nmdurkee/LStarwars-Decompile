/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652510; label: FUN_00652510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652510(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
    FUN_00698400(param_1);
    FUN_00698e70();
    FUN_006953b0(2,param_1,3,param_2,6,param_3,-(param_4 != 0) & 0xc,1);
    FUN_00698e70();
    DAT_0081049c = (undefined2)param_1;
    DAT_00810498 = 0;
  }
  return;
}

