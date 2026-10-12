/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b0f0; label: FUN_0058b0f0
 */

undefined4 FUN_0058b0f0(int param_1)

{
  char cVar1;
  
  if (((((DAT_008028a0 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a0)) &&
       (cVar1 = *(char *)(param_1 + 0x7b7), cVar1 != -1)) &&
      ((*(int *)(param_1 + 0x790) != 0 && (DAT_008028a4 != -1)))) &&
     (*(char *)(*(int *)(param_1 + 0x790) + 0x7b5) == DAT_008028a4)) {
    if ((cVar1 != -1) && ((*(byte *)(cVar1 * 0x10 + 10 + DAT_009553dc) & 4) != 0)) {
      FUN_0058b080();
    }
    if (*(int *)(param_1 + 0x790) != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x790) + 0x7b5) = 0xff;
    }
    return 1;
  }
  return 0;
}

