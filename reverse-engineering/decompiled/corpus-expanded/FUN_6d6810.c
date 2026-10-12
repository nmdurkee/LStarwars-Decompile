/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6810; label: FUN_006d6810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d6810(int param_1,uint param_2)

{
  if (param_1 < 0) {
    return param_1 * 2 + 1U ^ param_2 ^ 0x12345678;
  }
  return param_1 * 2 ^ param_2 ^ 0x12345678;
}

