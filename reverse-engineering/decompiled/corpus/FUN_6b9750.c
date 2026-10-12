/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9750; label: FUN_006b9750
 */

float10 FUN_006b9750(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 0x28) {
    return (float10)*(float *)(in_ECX + 0x118 + param_1 * 4);
  }
  return (float10)0;
}

