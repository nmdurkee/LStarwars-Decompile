/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e41e0; label: FUN_004e41e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e41e0(void)

{
  int iVar1;
  
  if ((DAT_008895d8 != 0) && (DAT_008895d8 < 3)) {
    iVar1 = FUN_006e6b90((int)DAT_008895da,0);
    FUN_004bac60(iVar1 + 1);
    DAT_008895da = 0;
  }
  return;
}

