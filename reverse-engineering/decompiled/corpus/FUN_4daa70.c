/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4daa70; label: FUN_004daa70
 */

undefined4 FUN_004daa70(int param_1)

{
  if ((((*(int *)(param_1 + 300) != 0) && (*(int *)(param_1 + 300) == DAT_0087b014)) &&
      (DAT_00882a6c != 0)) && (0.0 < *(float *)(DAT_00882a6c + 0xb000))) {
    return 1;
  }
  return 0;
}

