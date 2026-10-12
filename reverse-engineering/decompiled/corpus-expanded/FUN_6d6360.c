/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6360; label: FUN_006d6360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006d6360(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005be630(0x40000000,param_2 / param_1);
  return (float10)(float)((float10)1 - (float10)1 / fVar1);
}

