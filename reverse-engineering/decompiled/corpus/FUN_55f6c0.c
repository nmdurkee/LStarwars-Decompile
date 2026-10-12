/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f6c0; label: FUN_0055f6c0
 */

void FUN_0055f6c0(int param_1)

{
  int iVar1;
  
  FUN_005934d0(DAT_00955870,param_1);
  if ((*(int *)(param_1 + 0x2ab0) != 0) && (iVar1 = 0, 0 < *(int *)(*(int *)(param_1 + 0x2ab0) + 4))
     ) {
    do {
      FUN_00652b40(*(undefined4 *)(*(int *)(**(int **)(param_1 + 0x2ab0) + iVar1 * 4) + 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(*(int *)(param_1 + 0x2ab0) + 4));
  }
  FUN_0059a030(param_1);
  FUN_0055b5b0(param_1);
  FUN_0057cf00(*(undefined4 *)(param_1 + 0x2ab0));
  if (*(int *)(param_1 + 0x2964) != 0) {
    FUN_005ef880(*(int *)(param_1 + 0x2964));
    *(undefined4 *)(param_1 + 0x2964) = 0;
  }
  if (*(int *)(param_1 + 0x2a98) != -1) {
    FUN_0068e900(*(undefined1 *)(param_1 + 0x2a98));
    FUN_0068ea00(*(undefined1 *)(param_1 + 0x2a98));
  }
  if (*(int *)(param_1 + 0x2a9c) != -1) {
    FUN_00648a30(*(undefined1 *)(param_1 + 0x2a9c));
    FUN_0064c6e0(*(undefined1 *)(param_1 + 0x2a9c));
  }
  if (*(int *)(param_1 + 0x2aa4) != -1) {
    FUN_00689e70(*(undefined1 *)(param_1 + 0x2aa4));
    FUN_00689ed0(*(undefined1 *)(param_1 + 0x2aa4));
  }
  if (*(int *)(param_1 + 0x2aa8) != -1) {
    FUN_0065ceb0(*(undefined1 *)(param_1 + 0x2aa8));
  }
  if (*(int *)(param_1 + 0x2aa0) != -1) {
    FUN_0065a5c0(*(int *)(param_1 + 0x2aa0));
    FUN_0065a5d0(*(undefined4 *)(param_1 + 0x2aa0));
  }
  if (DAT_007fac04 == 0) {
    iVar1 = 2;
    do {
      if (*(int *)(&DAT_02948eb0 + iVar1 * 4) != 0) {
        FUN_0068e900(iVar1);
        FUN_0068ea00(iVar1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    iVar1 = 1;
    do {
      if (*(int *)(&DAT_02913a2c + iVar1 * 4) != 0) {
        FUN_00648a30(iVar1);
        FUN_0064c6e0(iVar1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  FUN_005a29d0(param_1);
  if (*(int *)(param_1 + 0x13c) != 0) {
    FUN_005ef880(*(int *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x13c) = 0;
  }
  if (*(int *)(param_1 + 0x140) != 0) {
    FUN_005ef880(*(int *)(param_1 + 0x140));
    *(undefined4 *)(param_1 + 0x140) = 0;
  }
  return;
}

