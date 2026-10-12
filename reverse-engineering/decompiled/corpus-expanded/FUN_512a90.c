/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x512a90; label: FUN_00512a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00512a90(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = *in_ECX - *in_EAX;
  param_1[1] = in_ECX[1] - in_EAX[1];
  param_1[2] = in_ECX[2] - in_EAX[2];
  return;
}

