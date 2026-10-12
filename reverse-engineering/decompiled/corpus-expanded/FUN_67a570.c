/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x67a570; label: FUN_0067a570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067a570(void)

{
  if (DAT_02947d88 != 0) {
    return *(byte *)(DAT_02947d88 + 99) - 8;
  }
  if (DAT_0292125e != '\0') {
    return DAT_02924b43 - 8;
  }
  return -1;
}

