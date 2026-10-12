/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a240; label: FUN_0057a240
 */

int FUN_0057a240(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00951bb8 == 0) {
    return -1;
  }
  iVar2 = 0;
  if (0 < DAT_00951bbc) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_00951bb8 + 4 + iVar2 * 8),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00951bbc);
  }
  return -1;
}

