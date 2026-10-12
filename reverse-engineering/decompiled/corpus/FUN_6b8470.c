/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b8470; label: FUN_006b8470
 */

void FUN_006b8470(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  uVar1 = param_1[1];
  in_ECX[4] = 0;
  in_ECX[5] = uVar1;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  uVar1 = param_1[2];
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = uVar1;
  in_ECX[0xb] = 0;
  uVar1 = param_1[3];
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = uVar1;
  return;
}

