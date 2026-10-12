/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4a80; label: FUN_004e4a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004e4a80(int param_1)

{
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b198) && (5.85 < *(float *)(param_1 + 100))) {
    return 1;
  }
  return 0;
}

