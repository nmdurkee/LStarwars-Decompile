/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652ba0; label: FUN_00652ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00652ba0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((DAT_02962034 != 0) || (DAT_02962038 != 0)) {
    return 0;
  }
  if (param_1 < 0) {
    return 0;
  }
  if (param_1 <= DAT_0296202c + -1) {
    DAT_00810498 = 0;
    DAT_0081049a = (undefined2)param_1;
    (&DAT_008104a3)[-(int)DAT_00810494] = 6;
    FUN_006989a0();
    FUN_00698440((int)DAT_00810494);
    uVar1 = FUN_006e6b90();
    FUN_00698460((int)DAT_00810494,uVar1);
    if (((DAT_00810492 == param_1) && (DAT_008104a0 == '\0')) &&
       (iVar2 = FUN_006984e0(1 - DAT_00810494), iVar2 != 2)) {
      FUN_00698420(1 - DAT_00810494);
      uVar1 = FUN_006e6b90();
      FUN_00698460(1 - DAT_00810494,uVar1);
      FUN_00698e70();
    }
    else {
      uVar3 = 1;
      uVar1 = FUN_006e6b90(0);
      FUN_00652510(1 - DAT_00810494,param_1,uVar1);
    }
    _DAT_008104a8 = 0x3f800000;
    DAT_00810492 = 0xffff;
    DAT_008104a0 = 0;
    if (param_2 != 0xd) {
      if (param_2 != 0xc) {
        DAT_008104b0 = param_3;
        _DAT_008104a8 = 0x3f800000;
        DAT_008104a0 = 0;
        DAT_00810492 = 0xffff;
        DAT_00810490 = 0xc - (ushort)(DAT_00810490 != 0);
        return uVar3;
      }
      DAT_00810490 = (short)param_2;
      DAT_008104b0 = param_3;
      return uVar3;
    }
    DAT_00810490 = (short)param_2;
    DAT_008104b0 = param_3;
    return uVar3;
  }
  return 0;
}

