/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x562150; label: FUN_00562150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00562150(int param_1)

{
  if ((((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 8) != 0) &&
      (DAT_00804c0c != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c0c * 4) != 0)) {
    return 1;
  }
  return 0;
}

