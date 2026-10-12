/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b8400; label: FUN_006b8400
 */

void FUN_006b8400(float *param_1,float param_2)

{
  float *in_ECX;
  
  param_2 = 1.0 / param_2;
  *param_1 = param_2 * *in_ECX;
  param_1[1] = in_ECX[1] * param_2;
  param_1[2] = param_2 * in_ECX[2];
  return;
}

