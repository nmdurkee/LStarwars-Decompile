/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x512ab0; label: FUN_00512ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00512ab0(void)

{
  float *in_EAX;
  
  return (float10)(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
}

