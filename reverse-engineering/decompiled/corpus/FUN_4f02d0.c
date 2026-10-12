/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f02d0; label: FUN_004f02d0
 */

int FUN_004f02d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((0 < param_2) && ((param_3 == 0 || (param_3 == 1)))) {
    iVar3 = 0;
    piVar2 = &DAT_02983750;
    do {
      if (*piVar2 == 0) {
        iVar1 = iVar3 * 0x14;
        *(int *)(&DAT_02983744 + iVar1) = param_1 + -1 + param_2;
        *(int *)(iVar1 + 0x298374c) = param_3;
        *(int *)(&DAT_02983740 + iVar1) = param_1;
        *(int *)(&DAT_02983748 + iVar1) = param_1;
        (&DAT_02983750)[iVar3 * 5] = 1;
        return iVar3 + 0x400;
      }
      piVar2 = piVar2 + 5;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x29838e0);
  }
  return 0;
}

