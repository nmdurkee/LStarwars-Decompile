/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dcec0; label: FUN_006dcec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dcec0(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 == ' ') {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return;
}

