/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c32d0; label: FUN_005c32d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c32d0(uint param_1)

{
  char *pcVar1;
  
  if ((DAT_00971598 & param_1) == 0) {
    return;
  }
  switch(param_1) {
  case 4:
    pcVar1 = (char *)(DAT_009737e0 + 0x89);
    break;
  default:
    goto switchD_005c32eb_caseD_5;
  case 8:
    pcVar1 = (char *)(DAT_009737e0 + 0x88);
    break;
  case 0x10:
    *(undefined1 *)(DAT_009737e8 + 4) = 1;
    return;
  case 0x20:
    *(undefined1 *)(DAT_009737e4 + 4) = 1;
    return;
  case 0x40:
    *(undefined1 *)(DAT_009737ec + 4) = 1;
    return;
  case 0x80:
    *(undefined1 *)(DAT_009737f0 + 4) = 1;
    goto switchD_005c32eb_caseD_5;
  }
  if (*pcVar1 == '\0') {
    *(int *)(DAT_009737e0 + 0x8c) = *(int *)(DAT_009737e0 + 0x8c) + 1;
    *pcVar1 = '\x01';
    return;
  }
switchD_005c32eb_caseD_5:
  return;
}

