/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1f10; label: FUN_004f1f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f1f10(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (param_2 != (char *)0x0) {
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      param_2 = param_2 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *param_2;
    }
  }
  *pcVar2 = '\0';
  return (int)pcVar2 - (int)param_1;
}

