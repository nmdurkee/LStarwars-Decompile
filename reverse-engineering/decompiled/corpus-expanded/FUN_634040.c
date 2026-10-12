/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x634040; label: FUN_00634040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634040(float param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *in_ECX = param_1 * *in_EAX;
  in_ECX[1] = in_EAX[1] * param_1;
  in_ECX[2] = param_1 * in_EAX[2];
  return;
}

