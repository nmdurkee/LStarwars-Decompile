/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6900; label: FUN_005c6900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6900(float *param_1,float *param_2)

{
  float *in_ECX;
  
  *param_1 = *in_ECX / *param_2;
  param_1[1] = in_ECX[1] / param_2[1];
  param_1[2] = in_ECX[2] / param_2[2];
  return;
}

