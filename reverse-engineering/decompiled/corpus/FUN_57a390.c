/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a390; label: FUN_0057a390
 */

int FUN_0057a390(int param_1)

{
  if (((param_1 != -1) && (DAT_00803b78 <= param_1)) && (param_1 <= DAT_00803b7c)) {
    return (DAT_00803b80 - DAT_00803b78) + param_1;
  }
  return param_1;
}

