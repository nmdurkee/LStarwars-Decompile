/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c1f30; label: FUN_005c1f30
 */

void FUN_005c1f30(float *param_1,float param_2,float *param_3)

{
  *param_1 = param_2 * *param_3;
  param_1[1] = param_3[1] * param_2;
  param_1[2] = param_2 * param_3[2];
  return;
}

