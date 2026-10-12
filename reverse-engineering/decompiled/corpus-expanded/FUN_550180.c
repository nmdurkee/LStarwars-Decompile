/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550180; label: FUN_00550180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00550180(undefined2 param_1,undefined2 param_2)

{
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  FUN_005b3620(local_c,&DAT_0080250c,param_1);
  FUN_005b3620(local_18,&DAT_0080250c,param_2);
  return (float10)(local_18[0] * local_c[0] + local_10 * local_4);
}

