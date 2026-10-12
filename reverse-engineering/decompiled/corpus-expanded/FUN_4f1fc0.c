/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1fc0; label: FUN_004f1fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_004f1fc0(char *param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
    if (pcVar1 < param_1) {
      return (char *)0x0;
    }
  }
  do {
    if (*pcVar1 == param_2) {
      return pcVar1;
    }
    pcVar1 = pcVar1 + -1;
  } while (param_1 <= pcVar1);
  return (char *)0x0;
}

