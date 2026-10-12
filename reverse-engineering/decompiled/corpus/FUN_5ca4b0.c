/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5ca4b0; label: FUN_005ca4b0
 */

float10 FUN_005ca4b0(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    if (*(ushort *)((int)param_1 + 0x16) != 0) {
      return (float10)*(ushort *)((int)param_1 + 0x16);
    }
    return (float10)((uint)*(ushort *)((int)param_1 + 0xe) + (uint)*(ushort *)((int)param_1 + 10));
  }
  return (float10)*param_1;
}

