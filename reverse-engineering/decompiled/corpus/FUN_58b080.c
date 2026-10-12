/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b080; label: FUN_0058b080
 */

void FUN_0058b080(void)

{
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x7b7) != -1) &&
     ((*(byte *)(*(char *)(unaff_ESI + 0x7b7) * 0x10 + 10 + DAT_009553dc) & 0x10) != 0)) {
    DAT_0095557c = 1;
  }
  if ((*(byte *)(*(int *)(unaff_ESI + 0x790) + 0x1fc) & 0x80) != 0) {
    FUN_0055f1d0(*(int *)(unaff_ESI + 0x790));
  }
  FUN_00438230(*(undefined4 *)(unaff_ESI + 0x790));
  return;
}

