/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9770; label: FUN_006b9770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b9770(uint param_1)

{
  int in_ECX;
  
  if ((param_1 < 0x28) && (*(char *)(param_1 + 0x78 + in_ECX) != '\0')) {
    return (float10)*(float *)(in_ECX + 0x118 + param_1 * 4);
  }
  return (float10)0;
}

