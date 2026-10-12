/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c0c00; label: FUN_005c0c00
 */

void FUN_005c0c00(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_c;
  float local_8;
  
  fVar3 = (float10)FUN_006e9530();
  fVar1 = (float)fVar3;
  fVar2 = 0.0;
  if (fVar1 == 0.0) {
    local_c = 0.0;
    local_8 = 0.0;
  }
  else {
    local_c = *param_2 / fVar1;
    local_8 = param_2[1] / fVar1;
    fVar2 = param_2[2] / fVar1;
  }
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = fVar2;
  return;
}

