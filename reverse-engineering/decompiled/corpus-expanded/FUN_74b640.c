/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b640; label: FUN_0074b640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0074b640(char *param_1,int *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint3 uVar5;
  
  pcVar4 = param_1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  iVar3 = *param_2;
  uVar5 = (uint3)((uint)((int)pcVar4 - (int)(param_1 + 1)) >> 8);
  if (iVar3 < (int)pcVar4 - (int)(param_1 + 1)) {
    pcVar4 = param_1 + iVar3;
    cVar2 = param_1[iVar3];
    while ((cVar2 != '\0' && (cVar2 != ';'))) {
      *param_3 = cVar2;
      *param_2 = *param_2 + 1;
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
      param_3 = param_3 + 1;
      cVar2 = *pcVar1;
    }
    *param_3 = '\0';
    if (*pcVar4 == ';') {
      *param_2 = *param_2 + 1;
    }
    return CONCAT31(uVar5,1);
  }
  return (uint)uVar5 << 8;
}

