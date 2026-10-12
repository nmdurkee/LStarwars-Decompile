/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b8600; label: FUN_005b8600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b8600(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  
  fVar2 = param_5 * param_5;
  fVar1 = fVar2 * param_5;
  return (float10)(((fVar1 * 2.0 - fVar2 * 3.0) + 1.0) * param_2 +
                   (param_3 - param_1) * 0.5 * ((fVar1 - fVar2 * 2.0) + param_5) +
                   (fVar1 * -2.0 + fVar2 * 3.0) * param_3 +
                  (fVar1 - fVar2) * (param_4 - param_2) * 0.5);
}

