/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dbb60; label: FUN_004dbb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004dbb60(int param_1)

{
  if (*(int *)(param_1 + 0x128) == DAT_0087b0a0) {
    return (float10)_DAT_0088249c;
  }
  return (float10)0;
}

