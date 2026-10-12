/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5ca450; label: FUN_005ca450
 */

uint FUN_005ca450(int *param_1)

{
  if ((0x414e4933 < *param_1) && (*param_1 < 0x414e4936)) {
    return (uint)*(ushort *)(param_1 + 1);
  }
  return (int)(short)param_1[1];
}

