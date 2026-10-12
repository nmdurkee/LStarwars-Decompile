/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc860; label: FUN_004fc860
 */

int FUN_004fc860(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = thunk_FUN_004fa610(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004fa3f0(param_1,0,DAT_0091ee88,0);
    if (iVar1 != 0) {
      iVar2 = FUN_004fc750(iVar1);
      if (iVar2 != 0) {
        FUN_004f1f10(iVar2 + 8,param_1);
        return iVar2;
      }
      FUN_004f99e0(iVar1);
    }
  }
  return 0;
}

