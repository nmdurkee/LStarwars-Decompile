/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x653320; label: FUN_00653320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00653320(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
    uVar3 = DAT_00810496;
    sVar1 = 1 - (short)_DAT_00810494;
    _DAT_00810494 = CONCAT22(DAT_0081049a,sVar1);
    DAT_0081049a = uVar3;
    FUN_00698420((int)sVar1);
    if (param_1 == 1) {
      uVar2 = FUN_006e6b90();
      FUN_00698460((int)DAT_00810494,uVar2);
      FUN_00698440(1 - DAT_00810494);
      FUN_00698460(1 - DAT_00810494,0);
      _DAT_008104a8 = 1.0;
      DAT_00810490 = 4;
      FUN_00698e70();
      return;
    }
    if ((DAT_00810490 == 5) || (DAT_00810490 == 6)) {
      _DAT_008104a8 = 1.0 - _DAT_008104a8;
    }
    else {
      _DAT_008104a8 = 0.0;
    }
    uVar2 = FUN_006e6b90();
    FUN_00698460((int)DAT_00810494,uVar2);
    DAT_00810490 = (param_1 == 3) + 5;
    FUN_00698e70();
    return;
  }
  return;
}

