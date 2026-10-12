/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fd5d0; label: FUN_004fd5d0
 */

int FUN_004fd5d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  int extraout_EDX_00;
  
  DAT_0091eea4 = 0;
  if (DAT_0091ee88 != 0) {
    iVar1 = FUN_004fb960(DAT_0091ee88,param_1,param_2,param_3);
    if (DAT_0091eea4 == -1) {
      return 0;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = thunk_FUN_004fa610(param_1);
  if (iVar1 == 0) {
    DAT_0091eea4 = 0xfffffffe;
    return 0;
  }
  iVar1 = FUN_004fa3f0(param_1,0,DAT_0091ee88,0);
  if (iVar1 != 0) {
    if (DAT_0091ee94 != 0) {
      iVar2 = FUN_004fcc60(iVar1,param_2,param_3);
      FUN_004f99e0(iVar1);
      return iVar2;
    }
    iVar2 = FUN_004f6b40(iVar1);
    if ((param_3 < iVar2) || (iVar2 == 0)) {
      DAT_0091eea4 = -1;
      iVar2 = 0;
    }
    else {
      iVar3 = FUN_004fb550(iVar1,param_2,iVar2);
      if (iVar3 < 0) {
        do {
          FUN_004ef7b0();
          FUN_004f6de0(iVar1,0,0,0);
          iVar3 = extraout_EDX;
          if (extraout_EDX < 1) {
            while (iVar3 < 0) {
              FUN_004ef7b0();
              FUN_004f6de0(iVar1,0,0,0);
              iVar3 = extraout_EDX_00;
            }
          }
          iVar3 = FUN_004fb550(iVar1,param_2,iVar2);
        } while (iVar3 < 0);
        FUN_004f99e0(iVar1);
        return iVar2;
      }
    }
    FUN_004f99e0(iVar1);
    return iVar2;
  }
  DAT_0091eea4 = 0xfffffffd;
  return 0;
}

