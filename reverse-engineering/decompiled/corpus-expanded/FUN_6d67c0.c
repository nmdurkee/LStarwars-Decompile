/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d67c0; label: FUN_006d67c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d67c0(int param_1)

{
  if ((param_1 != 10) && (param_1 != 0xc)) {
    return 0;
  }
  return 1;
}

