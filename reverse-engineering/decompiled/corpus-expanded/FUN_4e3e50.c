/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3e50; label: FUN_004e3e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3e50(void)

{
  FUN_004bac60(0,0,1);
  if ((DAT_00951b50 == 0) && (DAT_008895d8 != 0)) {
    FUN_004e3c90();
  }
  if (DAT_008895d0 != 0) {
    *(undefined4 *)(DAT_008895d0 + 0x28) = 0;
  }
  DAT_008895f4 = 0;
  DAT_008895f0 = 1;
  return;
}

