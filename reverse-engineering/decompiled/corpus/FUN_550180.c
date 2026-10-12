/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x550180; label: FUN_00550180
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

