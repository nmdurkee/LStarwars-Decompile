/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c1d80; label: FUN_005c1d80
 */

void FUN_005c1d80(float *param_1,int param_2)

{
  float fVar1;
  float *in_ECX;
  
  fVar1 = (float)param_2;
  *param_1 = fVar1 * *in_ECX;
  param_1[1] = in_ECX[1] * fVar1;
  param_1[2] = fVar1 * in_ECX[2];
  return;
}

