/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ec7b0; label: FUN_004ec7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004ec7b0(int param_1)

{
  if ((*(int *)(param_1 + 0x128) == DAT_0087b270) && (*(char *)(DAT_0088a628 + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

