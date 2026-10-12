/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x618000; label: FUN_00618000
 */

void FUN_00618000(float param_1,float param_2,float param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  float *in_EDX;
  
  fVar2 = param_3;
  fVar1 = param_2;
  if (param_2 <= param_3) {
    param_2 = param_3;
  }
  if (param_1 <= param_2) {
    param_2 = fVar1;
    if (fVar1 <= param_3) {
      param_2 = param_3;
    }
  }
  else {
    param_2 = param_1;
  }
  if (fVar1 < param_3) {
    param_3 = fVar1;
  }
  if (param_3 <= param_1) {
    param_3 = fVar2;
    if (fVar1 < fVar2) {
      param_3 = fVar1;
    }
  }
  else {
    param_3 = param_1;
  }
  *param_4 = param_2;
  if (param_2 == 0.0) {
    *in_EDX = 0.0;
    *in_ECX = 0.0;
    return;
  }
  param_3 = param_2 - param_3;
  *in_EDX = param_3 / param_2;
  if (param_3 / param_2 == 0.0) {
    *in_ECX = 0.0;
    return;
  }
  if (param_2 == param_1) {
    *in_ECX = (fVar1 - fVar2) / param_3;
  }
  else if (param_2 == fVar1) {
    *in_ECX = (fVar2 - param_1) / param_3 + 2.0;
  }
  else if (fVar2 == param_2) {
    *in_ECX = (param_1 - fVar1) / param_3 + 4.0;
  }
  fVar1 = *in_ECX * 60.0;
  *in_ECX = fVar1;
  if (0.0 <= fVar1) {
    return;
  }
  *in_ECX = fVar1 + 360.0;
  return;
}

