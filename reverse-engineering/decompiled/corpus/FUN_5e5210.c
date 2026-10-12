/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5210; label: FUN_005e5210
 */

int FUN_005e5210(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_009716e4;
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < DAT_0096e570) {
    do {
      if (*(int *)(DAT_0097157c + iVar2 * 4) == 0) {
        *(int *)(DAT_0097157c + iVar2 * 4) = param_1;
        *(int *)(iVar1 + iVar2 * 4) = DAT_00966380;
        DAT_00966380 = DAT_00966380 + 1;
        FUN_005f8e50(param_1);
        return iVar2 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0096e570);
  }
  FUN_005c12e0();
  return 0;
}

