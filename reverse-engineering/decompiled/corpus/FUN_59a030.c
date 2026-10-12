/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59a030; label: FUN_0059a030
 */

void FUN_0059a030(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x2968) != 0) {
    FUN_005ef880(*(int *)(param_1 + 0x2968));
    *(undefined4 *)(param_1 + 0x2968) = 0;
    *(undefined4 *)(param_1 + 0x296c) = 0;
    *(undefined1 *)(param_1 + 0x2970) = 0;
  }
  if (*(int *)(param_1 + 0x2984) != 0) {
    if ((*(int *)(param_1 + 300) == 0) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 5) != 5)) {
      iVar2 = 0;
      if (0 < DAT_00951360) {
        do {
          if ((*(int *)(*(int *)(param_1 + 0x2984) + iVar2 * 4) != 0) &&
             (piVar1 = *(int **)(*(int *)(param_1 + 0x2984) + iVar2 * 4), *piVar1 != 0)) {
            FUN_005ef880(*piVar1);
            **(undefined4 **)(*(int *)(param_1 + 0x2984) + iVar2 * 4) = 0;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < DAT_00951360);
      }
    }
    else if (DAT_00956048 != 0) {
      iVar2 = 0;
      if (0 < DAT_0093b278) {
        do {
          if ((*(int *)(*(int *)(param_1 + 0x2984) + iVar2 * 4) != 0) &&
             (piVar1 = *(int **)(*(int *)(param_1 + 0x2984) + iVar2 * 4), *piVar1 != 0)) {
            FUN_005ef880(*piVar1);
            **(undefined4 **)(*(int *)(param_1 + 0x2984) + iVar2 * 4) = 0;
          }
          *(undefined4 *)(DAT_00956048 + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < DAT_0093b278);
      }
      DAT_00924890 = DAT_00955fc4;
      return;
    }
  }
  return;
}

