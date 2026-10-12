/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652e60; label: FUN_00652e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652e60(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_008104ac = 1;
  if ((DAT_00810492 == param_1) && (DAT_008104a0 == '\0')) {
    FUN_00698420(1 - DAT_00810494);
    uVar1 = FUN_006e6b90();
    FUN_00698460(1 - DAT_00810494,uVar1);
    FUN_00698e70();
    DAT_008104ae = 0xffff;
    return;
  }
  uVar1 = FUN_006e6b90();
  iVar2 = 1 - DAT_00810494;
  if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
    FUN_00698400(iVar2);
    FUN_00698e70();
    FUN_006953b0(2,iVar2,3,param_1,6,uVar1,0,1);
    FUN_00698e70();
    DAT_0081049c = (undefined2)iVar2;
    DAT_00810498 = 0;
  }
  return;
}

