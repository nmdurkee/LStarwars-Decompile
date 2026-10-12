/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a5e0; label: FUN_0054a5e0
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

