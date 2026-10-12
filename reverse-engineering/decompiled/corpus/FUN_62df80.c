/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62df80; label: FUN_0062df80
 */

int FUN_0062df80(int param_1)

{
  short sVar1;
  
  if (param_1 != -1) {
    sVar1 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_1 * 2);
    if (sVar1 != -1) {
      return sVar1 * 0x54 + *(int *)(DAT_029130e4 + 0x18);
    }
  }
  return 0;
}

