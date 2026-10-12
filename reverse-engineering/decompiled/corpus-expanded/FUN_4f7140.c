/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7140; label: FUN_004f7140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f7140(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  
  pcVar1 = _strrchr(param_2,0x5c);
  if (pcVar1 != (char *)0x0) {
    param_2 = pcVar1 + 1;
  }
  pcVar1 = param_1;
  if ((param_2 != (char *)0x0) && (cVar3 = *param_2, cVar3 != '\0')) {
    do {
      *pcVar1 = cVar3;
      cVar3 = pcVar1[(int)(param_2 + (1 - (int)param_1))];
      pcVar1 = pcVar1 + 1;
    } while (cVar3 != '\0');
  }
  iVar2 = 0;
  *pcVar1 = '\0';
  cVar3 = *param_1;
  while (cVar3 != '\0') {
    iVar2 = iVar2 + 1;
    cVar3 = param_1[iVar2];
  }
  return;
}

