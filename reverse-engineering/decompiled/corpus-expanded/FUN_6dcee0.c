/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dcee0; label: FUN_006dcee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_006dcee0(char *param_1,char param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*param_1 == param_2) {
    param_1 = param_1 + 1;
  }
  *param_3 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar1 = param_1;
      if (*pcVar1 == param_2) {
        *pcVar1 = '\0';
        break;
      }
      iVar2 = iVar2 + 1;
      param_1 = pcVar1 + 1;
    } while (pcVar1[1] != '\0');
    param_1 = pcVar1 + 1;
    if (iVar2 != 0) {
      return param_1;
    }
  }
  *param_3 = 0;
  return param_1;
}

