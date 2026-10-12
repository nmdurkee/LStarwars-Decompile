/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f32b0; label: FUN_004f32b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f32b0(undefined1 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  cVar1 = *param_2;
  pcVar2 = param_2;
  if (cVar1 == '\0') goto LAB_004f32d0;
  do {
    pcVar2 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  for (; param_2 <= pcVar2; pcVar2 = pcVar2 + -1) {
LAB_004f32d0:
    if (*pcVar2 == '.') goto LAB_004f32de;
  }
  pcVar2 = (char *)0x0;
LAB_004f32de:
  pcVar3 = param_2;
  if (cVar1 == '\0') goto LAB_004f32f0;
  do {
    pcVar3 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  for (; param_2 <= pcVar3; pcVar3 = pcVar3 + -1) {
LAB_004f32f0:
    if (*pcVar3 == '/') goto LAB_004f32fe;
  }
  pcVar3 = (char *)0x0;
LAB_004f32fe:
  pcVar4 = param_2;
  if (cVar1 != '\0') {
    do {
      pcVar4 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    if (pcVar4 < param_2) goto LAB_004f332c;
  }
  do {
    if (*pcVar4 == '\\') {
      if (pcVar3 < pcVar4) {
        pcVar3 = pcVar4;
      }
      break;
    }
    pcVar4 = pcVar4 + -1;
  } while (param_2 <= pcVar4);
LAB_004f332c:
  if ((pcVar2 == (char *)0x0) || (pcVar2 < pcVar3)) {
    *param_1 = 0;
    return;
  }
  iVar5 = 0;
  while (cVar1 != '\0') {
    iVar5 = iVar5 + 1;
    cVar1 = param_2[iVar5];
  }
  if (param_2 + (iVar5 - (int)pcVar2) == (char *)0x0) {
    *param_1 = 0;
    return;
  }
  FUN_004f1f40(param_1,pcVar2 + 1,param_2 + (iVar5 - (int)pcVar2));
  return;
}

