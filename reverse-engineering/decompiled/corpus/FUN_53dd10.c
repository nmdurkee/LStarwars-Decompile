/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53dd10; label: FUN_0053dd10
 */

undefined4 FUN_0053dd10(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  if (0.0 <= (param_1[2] - in_ECX[2]) * in_EAX[2] +
             (*param_1 - *in_ECX) * *in_EAX + (param_1[1] - in_ECX[1]) * in_EAX[1]) {
    return 1;
  }
  return 0;
}

