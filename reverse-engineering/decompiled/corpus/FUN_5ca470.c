/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5ca470; label: FUN_005ca470
 */

float10 FUN_005ca470(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    return (float10)((float)*(ushort *)((int)param_1 + 10) + (float)*(ushort *)((int)param_1 + 0xe))
    ;
  }
  return (float10)*param_1;
}

