/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b210; label: FUN_0058b210
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b210(int param_1)

{
  float fVar1;
  
  if ((DAT_008028a4 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a4)) {
    if (*(int *)(param_1 + 0x790) == 0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if ((*(char *)(param_1 + 0x7b7) != -1) &&
         ((*(byte *)(*(char *)(param_1 + 0x7b7) * 0x10 + 10 + DAT_009553dc) & 2) != 0)) {
        FUN_0058b080();
      }
    }
  }
  return;
}

