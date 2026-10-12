/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a5e0; label: FUN_0054a5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054a5e0(void)

{
  _memset(&DAT_009253b0,0,0x1800);
  DAT_009253b0 = *DAT_009253ac;
  if (DAT_009253b0 != 0) {
    *(undefined1 *)(DAT_009253b0 + 0x88) = 0x2a;
    *(undefined1 *)(DAT_009253b0 + 0x89) = 0x60;
    *(undefined1 *)(DAT_009253b0 + 0x8a) = 0x38;
  }
  DAT_00925410 = DAT_009253ac[1];
  if (DAT_00925410 != 0) {
    *(undefined1 *)(DAT_00925410 + 0x88) = 0x2a;
    *(undefined1 *)(DAT_00925410 + 0x89) = 0x60;
    *(undefined1 *)(DAT_00925410 + 0x8a) = 0x38;
  }
  return;
}

