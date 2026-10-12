/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x589390; label: FUN_00589390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00589390(float param_1,float param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if ((0.0 - param_1 == 0.0) || (param_2 == 0.0)) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = (0.0 - param_1) / param_2;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar1 + fVar1;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_2 * 0.5 * fVar1 * fVar1 + fVar1 * param_1;
    return;
  }
  return;
}

