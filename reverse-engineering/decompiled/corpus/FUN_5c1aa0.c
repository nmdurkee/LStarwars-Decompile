/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c1aa0; label: FUN_005c1aa0
 */

void FUN_005c1aa0(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = in_EAX[8] * in_ECX[2] + *in_ECX * *in_EAX + in_EAX[4] * in_ECX[1] + in_EAX[0xc];
  param_1[1] = in_EAX[9] * in_ECX[2] + in_EAX[5] * in_ECX[1] + in_EAX[1] * *in_ECX + in_EAX[0xd];
  param_1[2] = in_EAX[10] * in_ECX[2] + in_EAX[6] * in_ECX[1] + in_EAX[2] * *in_ECX + in_EAX[0xe];
  param_1[3] = in_EAX[0xb] * in_ECX[2] + in_EAX[7] * in_ECX[1] + in_EAX[3] * *in_ECX + in_EAX[0xf];
  return;
}

