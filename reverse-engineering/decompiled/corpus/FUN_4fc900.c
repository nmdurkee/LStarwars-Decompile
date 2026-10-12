/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc900; label: FUN_004fc900
 */

int FUN_004fc900(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (((param_3 != 0) && (param_2 != 0)) && (0 < param_3)) {
    iVar4 = 0;
    piVar3 = &DAT_02983750;
    while (*piVar3 != 0) {
      piVar3 = piVar3 + 5;
      iVar4 = iVar4 + 1;
      if (0x29838df < (int)piVar3) {
        return 0;
      }
    }
    iVar2 = iVar4 * 0x14;
    *(int *)(&DAT_02983744 + iVar2) = param_2 + -1 + param_3;
    iVar1 = iVar4 + 0x400;
    *(int *)(&DAT_02983740 + iVar2) = param_2;
    *(int *)(&DAT_02983748 + iVar2) = param_2;
    *(undefined4 *)(iVar2 + 0x298374c) = 0;
    (&DAT_02983750)[iVar4 * 5] = 1;
    if (iVar1 != 0) {
      iVar4 = FUN_004fc750(iVar1);
      if (iVar4 != 0) {
        FUN_004f1f10(iVar4 + 8,param_1);
        return iVar4;
      }
      FUN_004f99e0(iVar1);
    }
  }
  return 0;
}

