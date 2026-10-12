/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7500; label: FUN_005f7500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7500(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = *in_ECX - *in_EAX;
  param_1[1] = in_ECX[1] - in_EAX[1];
  param_1[2] = in_ECX[2] - in_EAX[2];
  return;
}

