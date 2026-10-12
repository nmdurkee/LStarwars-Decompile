/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54be70; label: FUN_0054be70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0054be70(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = FUN_004f1ff0(param_1);
  pcVar2 = param_1 + iVar1;
  if (pcVar2 < param_1) {
    *param_2 = '\0';
    return 0;
  }
  do {
    cVar3 = *param_1;
    if (((cVar3 == ';') || (cVar3 == '#')) ||
       ((cVar3 == '/' && (param_1 = param_1 + 1, *param_1 == '/')))) {
      cVar3 = param_1[1];
      pcVar4 = param_1;
      while (((param_1 = pcVar4 + 1, cVar3 != '\r' && (cVar3 != '\n')) && (cVar3 != '\0'))) {
        cVar3 = pcVar4[2];
        pcVar4 = param_1;
      }
    }
    cVar3 = *param_1;
    param_1 = param_1 + 1;
    if ((param_3 != 0) && ((cVar3 == '=' || (cVar3 == ',')))) {
      cVar3 = ' ';
    }
    *param_2 = cVar3;
    param_2 = param_2 + 1;
    iVar5 = iVar5 + 1;
  } while (param_1 <= pcVar2);
  *param_2 = '\0';
  return iVar5;
}

