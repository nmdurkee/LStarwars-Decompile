/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6170; label: FUN_006d6170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6170(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_02975144 + 0x67e0);
  *(char *)(DAT_02975144 + 0x67e0) = (char)param_1;
  if (param_1 != cVar1) {
    DAT_029755b0 = 6;
  }
  return;
}

