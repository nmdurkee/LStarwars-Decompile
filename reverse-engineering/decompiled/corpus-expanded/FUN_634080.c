/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x634080; label: FUN_00634080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00634080(void)

{
  float *in_EAX;
  
  return (float10)(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
}

