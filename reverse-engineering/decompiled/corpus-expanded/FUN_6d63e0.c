/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d63e0; label: FUN_006d63e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d63e0(float *param_1,float param_2,float param_3)

{
  *param_1 = (param_2 - *param_1) * param_3 + *param_1;
  return;
}

