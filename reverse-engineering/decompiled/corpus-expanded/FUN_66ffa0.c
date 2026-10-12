/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66ffa0; label: FUN_0066ffa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2
FUN_0066ffa0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if ((param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4) < 0.0) {
    return 0;
  }
  return 1;
}

