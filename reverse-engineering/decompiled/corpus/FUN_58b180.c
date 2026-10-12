/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b180; label: FUN_0058b180
 */

void FUN_0058b180(int param_1)

{
  int iVar1;
  
  if ((((DAT_008028a0 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a0)) &&
      (*(char *)(param_1 + 0x7b7) != -1)) ||
     ((DAT_008028a4 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_008028a4)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    iVar1 = *(int *)(param_1 + 0x790);
    if ((iVar1 != 0) &&
       ((((DAT_008028a0 != -1 && (*(char *)(iVar1 + 0x7b5) == DAT_008028a0)) &&
         (*(char *)(iVar1 + 0x7b7) != -1)) ||
        ((DAT_008028a4 != -1 && (*(char *)(iVar1 + 0x7b5) == DAT_008028a4)))))) {
      *(undefined1 *)(iVar1 + 0x7b5) = 0xff;
    }
  }
  return;
}

