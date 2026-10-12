/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4b10; label: FUN_004e4b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e4b10(void)

{
  int iVar1;
  
  if ((((DAT_0093b0e4 & 2) == 0) && (DAT_0087a96c != (int *)0x0)) && (*DAT_0087a96c != 0)) {
    iVar1 = FUN_00467890(*DAT_0087a96c);
    if (iVar1 != 0) {
      DAT_0093b0e4 = DAT_0093b0e4 | 2;
    }
  }
  return;
}

