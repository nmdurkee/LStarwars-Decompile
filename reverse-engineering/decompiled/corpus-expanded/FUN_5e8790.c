/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8790; label: FUN_005e8790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8790(float *param_1)

{
  float fVar1;
  float *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_005c0240(in_ECX[2] * in_ECX[2] + *in_ECX * *in_ECX + in_ECX[1] * in_ECX[1]);
  fVar1 = (float)fVar2;
  *param_1 = *in_ECX / fVar1;
  param_1[1] = in_ECX[1] / fVar1;
  param_1[2] = in_ECX[2] / fVar1;
  return;
}

