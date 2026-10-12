/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1e20; label: FUN_004f1e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f1e20(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 == (char *)0x0) {
    *param_1 = '\0';
    return iVar3;
  }
  do {
    pcVar2 = param_3;
    if (*param_2 == '*') {
      for (; (pcVar2 != (char *)0x0 && (*pcVar2 != '\0')); pcVar2 = pcVar2 + 1) {
        *param_1 = *pcVar2;
        param_1 = param_1 + 1;
        iVar3 = iVar3 + 1;
      }
    }
    else {
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
    }
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return iVar3;
}

