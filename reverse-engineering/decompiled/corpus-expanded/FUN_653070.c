/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x653070; label: FUN_00653070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00653070(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
    uVar4 = (undefined2)param_1;
    if ((-1 < param_1) && (param_1 <= DAT_0296202c + -1)) {
      DAT_0081049a = DAT_00810496;
      DAT_00810498 = 0;
      if (((DAT_00810490 != 0) && (param_2 != 1)) && (DAT_00810db0 != -1)) {
        sVar1 = 1 - DAT_00810494;
        _DAT_00810494 = CONCAT22(uVar4,sVar1);
        (&DAT_008104a2)[sVar1] = 0;
        if ((DAT_00810492 == param_1) && (DAT_008104a0 == '\0')) {
          DAT_00810490 = (ushort)(param_2 == 3) * 2 + 7;
          FUN_00698420((int)DAT_00810494);
          FUN_00698460((int)DAT_00810494,0);
          FUN_00698e70();
          DAT_008104a0 = 0;
          _DAT_008104a8 = 0;
          DAT_008104a1 = 0;
          DAT_00810492 = 0xffff;
          return;
        }
        DAT_00810490 = (ushort)(param_2 == 3) * 2 + 8;
        FUN_00652510((int)DAT_00810494,param_1,0,0);
        _DAT_008104a8 = 0;
        DAT_008104a0 = 0;
        DAT_008104a1 = 0;
        DAT_00810492 = 0xffff;
        return;
      }
      DAT_00810496 = uVar4;
      (&DAT_008104a2)[DAT_00810494] = 0;
      if ((DAT_00810492 == param_1) && (DAT_00810490 != 0xb)) {
        DAT_00810494 = 1 - DAT_00810494;
      }
      FUN_00698400(1 - DAT_00810494);
      if (((DAT_00810492 == param_1) && (DAT_008104a0 == '\0')) &&
         (iVar2 = FUN_006984e0((int)DAT_00810494), iVar2 != 2)) {
        FUN_00698420((int)DAT_00810494);
        uVar3 = FUN_006e6b90();
        FUN_00698460((int)DAT_00810494,uVar3);
        FUN_00698e70();
      }
      else {
        uVar3 = FUN_006e6b90(0);
        FUN_00652510((int)DAT_00810494,param_1,uVar3);
      }
      DAT_008104a0 = 0;
      _DAT_008104a8 = 0x3f800000;
      DAT_008104a1 = 0;
      DAT_00810490 = 4;
      DAT_00810492 = 0xffff;
      return;
    }
    _DAT_008104a8 = 0;
    DAT_0081049a = DAT_00810496;
    DAT_008104a1 = 0;
    DAT_00810490 = (ushort)(param_2 == 3) * 2 + 7;
    _DAT_00810494 = CONCAT22(uVar4,1 - DAT_00810494);
  }
  return;
}

