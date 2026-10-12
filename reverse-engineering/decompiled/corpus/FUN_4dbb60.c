/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dbb60; label: FUN_004dbb60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004dbb60(int param_1)

{
  if (*(int *)(param_1 + 0x128) == DAT_0087b0a0) {
    return (float10)_DAT_0088249c;
  }
  return (float10)0;
}

