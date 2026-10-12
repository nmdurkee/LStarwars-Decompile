/* Ghidra pseudocode, not original source.
 * ev_d6e6804647628cd3e7ce0eee802958277deb78ba643873a9983999f38b8fc9a0
 * Entry: 0x6dec10; label: FUN_006dec10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006dec10(int param_1,int param_2)

{
  param_1 = param_1 + -0x80;
  if (param_2 < param_1) {
    return ((param_1 - param_2) * 0x7f) / (0x7f - param_2);
  }
  if (param_1 < -param_2) {
    return ((param_1 + param_2) * 0x7f) / (0x7f - param_2);
  }
  return 0;
}

