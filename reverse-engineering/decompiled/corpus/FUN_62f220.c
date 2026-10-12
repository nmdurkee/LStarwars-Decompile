/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f220; label: FUN_0062f220
 */

float10 FUN_0062f220(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return (float10)*(float *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x38);
  }
  return (float10)0;
}

