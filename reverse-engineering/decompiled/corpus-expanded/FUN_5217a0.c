/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x5217a0; label: FUN_005217a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005217a0(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  
  if (param_2[2] <= *param_2) {
    fVar1 = param_2[2];
  }
  else {
    fVar1 = *param_2;
  }
  FUN_0051f720(param_1,fVar1,*(undefined4 *)(param_1 + 4),param_2[1] + *(float *)(param_1 + 4),
               param_3,0,0x10);
  return;
}

