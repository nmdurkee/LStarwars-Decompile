/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3230; label: FUN_004f3230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3230(undefined1 *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_2;
  if (*param_2 == '\0') goto LAB_004f3250;
  do {
    pcVar1 = pcVar1 + 1;
  } while (*pcVar1 != '\0');
  for (; param_2 <= pcVar1; pcVar1 = pcVar1 + -1) {
LAB_004f3250:
    if (*pcVar1 == '/') goto LAB_004f325e;
  }
  pcVar1 = (char *)0x0;
LAB_004f325e:
  pcVar2 = param_2;
  if (*param_2 != '\0') {
    do {
      pcVar2 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    if (pcVar2 < param_2) goto LAB_004f3288;
  }
  do {
    if (*pcVar2 == '\\') {
      if (pcVar1 < pcVar2) {
        pcVar1 = pcVar2;
      }
      break;
    }
    pcVar2 = pcVar2 + -1;
  } while (param_2 <= pcVar2);
LAB_004f3288:
  if (pcVar1 != (char *)0x0) {
    FUN_004f1f40(param_1,param_2,pcVar1 + (1 - (int)param_2));
    return;
  }
  *param_1 = 0;
  return;
}

