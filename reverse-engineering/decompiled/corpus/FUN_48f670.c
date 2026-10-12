/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48f670; label: FUN_0048f670
 */

void FUN_0048f670(void)

{
  if (DAT_007f39e4 == 0) {
    if (DAT_00876580 != 0) {
      FUN_005734a0(&PTR_s_losttemple_007fa9e0);
      return;
    }
    FUN_005734a0(&PTR_s_batcave_007fa9f0);
  }
  else {
    FUN_005734a0(&PTR_DAT_007fa7d8);
    if (DAT_0087b02c != 0) {
      *(ushort *)(DAT_0087b02c + 0x7a) = *(ushort *)(DAT_0087b02c + 0x7a) | 0x2000;
      return;
    }
  }
  return;
}

