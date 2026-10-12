/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x696830; label: FUN_00696830
 */

void FUN_00696830(undefined4 param_1)

{
  float fVar1;
  int in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f9f60(param_1);
  fVar1 = (float)fVar2;
  *(float *)(in_ECX + 0x1cc) = fVar1;
  if (0.0 <= fVar1) {
    return;
  }
  if (fVar1 < -100.0 != (fVar1 == -100.0)) {
    *(undefined4 *)(in_ECX + 0x1cc) = 0;
    return;
  }
  fVar2 = (float10)FUN_005be970(fVar1 / 20.0);
  *(float *)(in_ECX + 0x1cc) = (float)fVar2;
  return;
}

