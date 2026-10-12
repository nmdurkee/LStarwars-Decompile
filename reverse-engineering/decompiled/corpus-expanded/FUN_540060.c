/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x540060; label: FUN_00540060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00540060(void)

{
  *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 0x100;
  return;
}

