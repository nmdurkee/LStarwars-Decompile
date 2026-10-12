/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6740; label: FUN_006d6740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6740(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(DAT_02975144 + 0x4e13);
  *puVar1 = 0;
  if (param_1 != 0) {
    FUN_004f1f10(puVar1,param_1);
  }
  return;
}

