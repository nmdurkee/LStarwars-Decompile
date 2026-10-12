/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3180; label: FUN_004f3180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3180(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  cVar1 = *param_2;
  pcVar3 = param_2;
  if (cVar1 == '\0') goto LAB_004f31a0;
  do {
    pcVar3 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  for (; param_2 <= pcVar3; pcVar3 = pcVar3 + -1) {
LAB_004f31a0:
    if (*pcVar3 == '.') goto LAB_004f31bf;
  }
  iVar4 = 0;
  cVar2 = cVar1;
  while (cVar2 != '\0') {
    iVar4 = iVar4 + 1;
    cVar2 = param_2[iVar4];
  }
  pcVar3 = param_2 + iVar4 + -1;
LAB_004f31bf:
  pcVar5 = param_2;
  if (cVar1 == '\0') goto LAB_004f31d1;
  do {
    pcVar5 = pcVar5 + 1;
  } while (*pcVar5 != '\0');
  for (; param_2 <= pcVar5; pcVar5 = pcVar5 + -1) {
LAB_004f31d1:
    if (*pcVar5 == '/') goto LAB_004f31df;
  }
  pcVar5 = (char *)0x0;
LAB_004f31df:
  pcVar6 = param_2;
  if (cVar1 != '\0') {
    do {
      pcVar6 = pcVar6 + 1;
    } while (*pcVar6 != '\0');
    if (pcVar6 < param_2) goto LAB_004f320d;
  }
  do {
    if (*pcVar6 == '\\') {
      if (pcVar5 < pcVar6) {
        pcVar5 = pcVar6;
      }
      break;
    }
    pcVar6 = pcVar6 + -1;
  } while (param_2 <= pcVar6);
LAB_004f320d:
  if (pcVar5 == (char *)0x0) {
    pcVar5 = param_2;
  }
  FUN_004f1f40(param_1,pcVar5 + 1,pcVar3 + (1 - (int)(pcVar5 + 1)));
  return;
}

