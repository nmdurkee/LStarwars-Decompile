/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6b40; label: FUN_004f6b40
 */

longlong FUN_004f6b40(int param_1)

{
  int iVar1;
  
  if (0xfff < param_1) {
    iVar1 = FUN_006dee40(param_1 + -0x1000);
    return (longlong)iVar1;
  }
  if (0x7ff < param_1) {
    iVar1 = (param_1 * 3 + -0x1800) * 0x10;
    if (*(int *)(&DAT_0297dc88 + iVar1) != 0) {
      return (longlong)*(int *)(&DAT_0297dc7c + iVar1);
    }
    return (longlong)*(int *)(&DAT_0297dc78 + iVar1);
  }
  if (0x3ff < param_1) {
    iVar1 = param_1 * 5 + -0x1400;
    return (longlong)(*(int *)(&DAT_02983744 + iVar1 * 4) - *(int *)(&DAT_02983740 + iVar1 * 4));
  }
  return *(longlong *)(&DAT_008ceb28 + param_1 * 0x40);
}

