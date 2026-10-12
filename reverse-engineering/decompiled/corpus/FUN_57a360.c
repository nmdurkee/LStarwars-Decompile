/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a360; label: FUN_0057a360
 */

undefined1 * FUN_0057a360(int param_1)

{
  if (((DAT_00951bb8 != 0) && (-1 < param_1)) && (param_1 < DAT_00951bbc)) {
    return *(undefined1 **)(DAT_00951bb8 + 4 + param_1 * 8);
  }
  return &DAT_007516c0;
}

