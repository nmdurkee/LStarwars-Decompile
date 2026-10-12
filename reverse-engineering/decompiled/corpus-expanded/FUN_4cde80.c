/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cde80; label: FUN_004cde80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cde80(void)

{
  *(ushort *)(DAT_00880608 + 0x4c) = *(ushort *)(DAT_00880608 + 0x4c) | 1;
  return;
}

