/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f1a0; label: FUN_0062f1a0
 */

int FUN_0062f1a0(int param_1)

{
  if (*(char *)(param_1 + 0x31) != '\0') {
    return (int)*(short *)(param_1 + 0x34);
  }
  return (int)*(short *)(param_1 + 0x36);
}

