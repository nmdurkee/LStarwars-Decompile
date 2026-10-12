/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f250; label: FUN_0062f250
 */

int FUN_0062f250(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return *(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x28;
  }
  return 0;
}

