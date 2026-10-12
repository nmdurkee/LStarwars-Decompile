/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f3070; label: FUN_004f3070
 */

byte * FUN_004f3070(byte *param_1,uint param_2)

{
  if (0x7f < (ushort)param_2) {
    if ((ushort)param_2 < 0x800) {
      *param_1 = (byte)(param_2 >> 6) | 0xc0;
      param_1[1] = (byte)param_2 & 0x3f | 0x80;
      return param_1 + 2;
    }
    *param_1 = (byte)(param_2 >> 8) >> 4 | 0xe0;
    param_1[1] = (byte)(param_2 >> 6) & 0x3f | 0x80;
    param_1 = param_1 + 2;
    param_2 = (uint)((byte)param_2 & 0x3f | 0x80);
  }
  *param_1 = (byte)param_2;
  return param_1 + 1;
}

