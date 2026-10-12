/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2f90; label: FUN_005b2f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b2f90(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_ECX;
  
  fVar1 = in_ECX[1];
  fVar2 = in_ECX[2];
  fVar3 = in_ECX[3];
  *param_1 = 0.0 - *in_ECX;
  param_1[1] = 0.0 - fVar1;
  param_1[2] = 0.0 - fVar2;
  param_1[3] = 0.0 - fVar3;
  return;
}

