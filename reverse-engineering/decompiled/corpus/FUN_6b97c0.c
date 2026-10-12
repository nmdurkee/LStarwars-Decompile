/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b97c0; label: FUN_006b97c0
 */

float10 FUN_006b97c0(uint param_1)

{
  int in_ECX;
  
  if ((param_1 < 0x28) && (*(char *)(param_1 + 0x50 + in_ECX) != '\0')) {
    return (float10)*(float *)(in_ECX + 0x118 + param_1 * 4);
  }
  return (float10)0;
}

