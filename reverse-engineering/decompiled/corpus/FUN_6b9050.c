/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9050; label: FUN_006b9050
 */

void FUN_006b9050(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = *param_1;
  *(undefined4 *)(in_ECX + 0x14) = param_1[1];
  *(undefined4 *)(in_ECX + 0x18) = param_1[2];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[3];
  FUN_00620f10((undefined4 *)(in_ECX + 0x10));
  return;
}

