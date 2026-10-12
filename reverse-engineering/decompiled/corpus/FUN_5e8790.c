/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e8790; label: FUN_005e8790
 */

void FUN_005e8790(float *param_1)

{
  float fVar1;
  float *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_005c0240(in_ECX[2] * in_ECX[2] + *in_ECX * *in_ECX + in_ECX[1] * in_ECX[1]);
  fVar1 = (float)fVar2;
  *param_1 = *in_ECX / fVar1;
  param_1[1] = in_ECX[1] / fVar1;
  param_1[2] = in_ECX[2] / fVar1;
  return;
}

