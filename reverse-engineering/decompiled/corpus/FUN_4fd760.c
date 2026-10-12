/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fd760; label: FUN_004fd760
 */

int FUN_004fd760(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = FUN_004fa3f0(param_2,0,DAT_0091ee88,0);
  iVar2 = FUN_004fa3f0(param_1,1,DAT_0091ee88,0);
  if (iVar1 != 0) {
    if (iVar2 != 0) {
      for (iVar3 = FUN_004f6b40(iVar1); iVar3 != 0; iVar3 = iVar3 - iVar4) {
        iVar4 = iVar3;
        if (param_4 <= iVar3) {
          iVar4 = param_4;
        }
        iVar4 = FUN_004fb550(iVar1,param_3,iVar4);
        if (iVar2 < 0x1000) {
          if (iVar2 < 0x400) {
            FUN_004ff3f0(iVar2 + -1,param_3,iVar4);
          }
          else {
            FUN_004f0380(iVar2);
          }
        }
        else {
          FUN_006dee60(iVar2 + -0x1000,param_3,iVar4,0);
        }
        iVar5 = iVar5 + iVar4;
      }
    }
    FUN_004f99e0(iVar1);
  }
  if (iVar2 != 0) {
    FUN_004f99e0(iVar2);
  }
  return iVar5;
}

