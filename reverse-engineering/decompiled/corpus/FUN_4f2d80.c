/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2d80; label: FUN_004f2d80
 */

byte FUN_004f2d80(byte param_1)

{
  if (((byte)(param_1 + 0x9f) < 0x1a) || (0xdf < param_1)) {
    param_1 = param_1 - 0x20;
  }
  return param_1;
}

