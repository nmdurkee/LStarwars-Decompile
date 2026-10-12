/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4b60; label: FUN_004e4b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e4b60(void)

{
  int iVar1;
  
  if (DAT_0087aa48 != 0) {
    iVar1 = FUN_0055c690();
    if (iVar1 != 0) {
      *(uint *)(DAT_0087aa48 + 0x94) = *(uint *)(DAT_0087aa48 + 0x94) & 0xff7fffff;
    }
  }
  return;
}

