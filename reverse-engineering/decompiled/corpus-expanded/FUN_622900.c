/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622900; label: FUN_00622900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00622900(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; (*param_1 == '*' || (*param_1 == ' ')); param_1 = param_1 + 1) {
  }
  cVar1 = *param_1;
  pcVar3 = param_1;
  while (((cVar1 != '\0' && (cVar1 != '|')) && (cVar1 != '*'))) {
    pcVar2 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar2;
  }
  pcVar2 = pcVar3;
  if (pcVar3 != param_1) {
    do {
      if (pcVar2[-1] != ' ') {
        if (param_1 != pcVar2) {
          do {
            *param_2 = *param_1;
            param_1 = param_1 + 1;
            param_2 = param_2 + 1;
          } while (param_1 != pcVar2);
          *param_2 = '\0';
          return pcVar3;
        }
        *param_2 = '\0';
        return pcVar3;
      }
      pcVar2 = pcVar2 + -1;
    } while (pcVar2 != param_1);
    *param_2 = '\0';
    return pcVar3;
  }
  *param_2 = '\0';
  return pcVar3;
}

