/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x653460; label: FUN_00653460
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00653460(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_008104ac == 0) && (param_1 != 0.0)) {
    switch(DAT_00810490) {
    case 4:
      iVar1 = FUN_006984e0((int)DAT_0081049c);
      if (iVar1 != 2) {
        if (DAT_00810498 < 0x80) {
          DAT_00810498 = DAT_00810498 + 1;
        }
        if ((0x40 < DAT_00810498) && (DAT_008104a0 != '\0')) {
          FUN_00652660((int)DAT_00810492);
        }
        if ((0x18 < DAT_00810498) && (DAT_008104a1 != '\0')) {
          FUN_00652de0();
          DAT_008104a1 = 0;
          return;
        }
      }
      break;
    case 5:
    case 6:
    case 7:
    case 9:
      if ((DAT_00810490 == 9) || (DAT_00810490 == 6)) {
        param_1 = param_1 + param_1;
      }
      else {
        param_1 = param_1 * 0.2;
      }
      param_1 = param_1 + _DAT_008104a8;
      _DAT_008104a8 = 1.0;
      if (1.0 < param_1 != (param_1 == 1.0)) {
        if ((DAT_00810490 == 5) || (DAT_00810490 == 6)) {
          FUN_00698440(1 - DAT_00810494);
        }
        else {
          FUN_00698400(1 - DAT_00810494);
        }
        DAT_00810490 = 4;
        DAT_00810498 = 0;
        param_1 = _DAT_008104a8;
      }
      _DAT_008104a8 = param_1;
      if (DAT_00810496 != -1) {
        uVar2 = FUN_006e6b90();
        FUN_00698460((int)DAT_00810494,uVar2);
      }
      if (DAT_0081049a != -1) {
        uVar2 = FUN_006e6b90();
        FUN_00698460(1 - DAT_00810494,uVar2);
        return;
      }
      break;
    case 8:
    case 10:
      iVar1 = FUN_006984e0((int)DAT_00810494);
      if (iVar1 != 2) {
        DAT_00810490 = 7;
        return;
      }
      break;
    case 0xb:
    case 0xc:
    case 0xd:
      if (((DAT_008104b0 == 0) || ((*(byte *)(DAT_008104b0 + 0x88) & 2) == 0)) &&
         (iVar1 = FUN_006984e0(1 - DAT_00810494), iVar1 != 2)) {
        if (DAT_0081049e < 0x40) {
          DAT_0081049e = DAT_0081049e + 1;
        }
        if (((8 < DAT_0081049e) && (DAT_00810496 != -1)) &&
           ((DAT_00810490 != 0xd &&
            ((iVar1 = FUN_006984e0((int)DAT_00810494), iVar1 != 2 && (DAT_008104a0 == '\0')))))) {
          if (DAT_00810490 == 0xc) {
            DAT_00810490 = 0;
            FUN_00698400(1 - DAT_00810494);
            FUN_00698400((int)DAT_00810494);
          }
          else {
            DAT_00810490 = 4;
            FUN_00698400(1 - DAT_00810494);
            FUN_00698420((int)DAT_00810494);
          }
          _DAT_008104a8 = 1.0;
          uVar2 = FUN_006e6b90();
          FUN_00698460((int)DAT_00810494,uVar2);
          FUN_00698e70();
          DAT_00810498 = 0;
          DAT_00810492 = -1;
        }
      }
      else {
        DAT_0081049e = 0;
      }
      iVar1 = FUN_006984e0((int)DAT_0081049c);
      if (iVar1 != 2) {
        if (DAT_00810498 < 0x80) {
          DAT_00810498 = DAT_00810498 + 1;
        }
        if ((0x40 < DAT_00810498) && (DAT_008104a0 != '\0')) {
          FUN_00652660();
          return;
        }
      }
    }
  }
  return;
}

