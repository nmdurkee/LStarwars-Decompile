/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48f670; label: FUN_0048f670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

