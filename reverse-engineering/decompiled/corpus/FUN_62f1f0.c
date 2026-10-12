/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f1f0; label: FUN_0062f1f0
 */

float10 FUN_0062f1f0(int param_1,int param_2,uint param_3)

{
  if (((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) && (param_3 < 4))
  {
    return (float10)*(float *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x28 + param_3 * 4);
  }
  return (float10)0;
}

