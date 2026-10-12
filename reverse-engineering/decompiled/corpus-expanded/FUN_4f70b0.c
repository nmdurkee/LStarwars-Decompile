/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f70b0; label: FUN_004f70b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f70b0(char *param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar1 = param_1;
  if ((param_2 != (char *)0x0) && (cVar3 = *param_2, cVar3 != '\0')) {
    do {
      *pcVar1 = cVar3;
      cVar3 = pcVar1[(int)(param_2 + (1 - (int)param_1))];
      pcVar1 = pcVar1 + 1;
    } while (cVar3 != '\0');
  }
  *pcVar1 = '\0';
  pcVar1 = param_1;
  do {
    pcVar4 = pcVar1;
    pcVar1 = pcVar4 + 1;
  } while (*pcVar4 != '\0');
  if (*pcVar4 != '\\') {
    *pcVar1 = '\\';
    pcVar1 = pcVar4 + 2;
  }
  pcVar4 = pcVar1;
  if ((param_3 != (char *)0x0) && (cVar3 = *param_3, cVar3 != '\0')) {
    do {
      *pcVar4 = cVar3;
      cVar3 = pcVar4[(int)(param_3 + (1 - (int)pcVar1))];
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
  }
  iVar2 = 0;
  *pcVar4 = '\0';
  cVar3 = *param_1;
  while (cVar3 != '\0') {
    iVar2 = iVar2 + 1;
    cVar3 = param_1[iVar2];
  }
  return;
}

