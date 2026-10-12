/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x5209e0; label: FUN_005209e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005209e0(float *param_1,float param_2)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = (*in_EAX - *in_ECX) / param_2;
  param_1[2] = (in_EAX[2] - in_ECX[2]) / param_2;
  return;
}

