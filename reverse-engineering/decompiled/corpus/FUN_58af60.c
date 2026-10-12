/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58af60; label: FUN_0058af60
 */

int FUN_0058af60(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (DAT_009553dc == 0) {
    return -1;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (0.0 < *(float *)(param_1 + 0xda8))) {
    return -1;
  }
  if ((DAT_008028a0 == -1) || (DAT_008028a4 == -1)) {
    return -1;
  }
  iVar2 = 0;
  if (0 < DAT_009553e0) {
    pcVar1 = (char *)(DAT_009553dc + 4);
    do {
      if (((((*(short *)(param_1 + 0x1064) == *(short *)(pcVar1 + -2)) ||
            ((*pcVar1 != -1 &&
             (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == *pcVar1)))) &&
           (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(pcVar1 + -4) * 4) != 0))
          && ((*(short *)(param_2 + 0x1064) == *(short *)(pcVar1 + 2) ||
              ((pcVar1[1] != -1 &&
               (*(char *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x116) == pcVar1[1])))))) &&
         ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(pcVar1 + 4) * 4) != 0 &&
          (((*(byte *)(param_2 + 0x1fc) & 0x80) == 0 ||
           ((*(float *)(param_2 + 0x1000) <= 0.0 && ((*(uint *)(param_2 + 0xef0) & 0x400000) == 0)))
           ))))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0x10;
    } while (iVar2 < DAT_009553e0);
  }
  return -1;
}

