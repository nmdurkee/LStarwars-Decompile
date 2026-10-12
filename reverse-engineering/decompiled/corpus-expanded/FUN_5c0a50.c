/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0a50; label: FUN_005c0a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0a50(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_2 - param_3[0xc];
  fVar2 = param_2[1] - param_3[0xd];
  fVar3 = param_2[2] - param_3[0xe];
  *param_1 = fVar2 * param_3[1] + fVar1 * *param_3 + fVar3 * param_3[2];
  param_1[1] = param_3[6] * fVar3 + param_3[4] * fVar1 + param_3[5] * fVar2;
  param_1[2] = fVar3 * param_3[10] + param_3[9] * fVar2 + param_3[8] * fVar1;
  return;
}

