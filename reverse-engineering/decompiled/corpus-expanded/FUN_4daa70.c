/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4daa70; label: FUN_004daa70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004daa70(int param_1)

{
  if ((((*(int *)(param_1 + 300) != 0) && (*(int *)(param_1 + 300) == DAT_0087b014)) &&
      (DAT_00882a6c != 0)) && (0.0 < *(float *)(DAT_00882a6c + 0xb000))) {
    return 1;
  }
  return 0;
}

