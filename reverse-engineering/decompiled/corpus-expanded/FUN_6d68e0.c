/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d68e0; label: FUN_006d68e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d68e0(int param_1,int param_2,int param_3,int param_4)

{
  if (param_3 != 0) {
    return *(char *)(DAT_02975144 + 0x6358 + (param_4 * 0x20 + param_2) * 4) != '\0';
  }
  return *(char *)(DAT_02975144 + 0x4ea2 + (param_1 * 0x5f + param_2) * 4) != '\0';
}

