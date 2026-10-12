/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fa810; label: FUN_004fa810
 */

void FUN_004fa810(int param_1)

{
  int iVar1;
  int extraout_ECX;
  
  if ((*(int *)(param_1 + 4) < 0x400) || (0x7ff < *(int *)(param_1 + 4))) {
    iVar1 = param_1 + 8;
    if (*(char *)(param_1 + 8) == '\0') {
      iVar1 = FUN_004ef790();
    }
    iVar1 = FUN_004fa3f0(iVar1,0,DAT_0091ee88,0);
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) {
      FUN_004ef790();
      iVar1 = extraout_ECX;
    }
    FUN_004f6de0(iVar1,*(int *)(param_1 + 0x524),*(int *)(param_1 + 0x524) >> 0x1f,0);
    *(int *)(param_1 + 0x52c) = *(int *)(param_1 + 0x524) + -1;
  }
  return;
}

