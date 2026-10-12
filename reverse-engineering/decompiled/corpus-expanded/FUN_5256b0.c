/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x5256b0; label: FUN_005256b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005256b0(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
    pcVar5 = (char *)(param_2 + 0x4c);
    pcVar2 = pcVar5;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != (char *)(param_2 + 0x4d)) {
      for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar3 != 0;
          iVar3 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar3)) {
        iVar4 = FUN_004f8b10(iVar3 + 8,pcVar5);
        if (iVar4 == 0) {
          return;
        }
      }
      pcVar2 = (char *)(*(int *)(DAT_009238e4 + 0x4868) + 8);
      do {
        cVar1 = *pcVar5;
        *pcVar2 = cVar1;
        pcVar5 = pcVar5 + 1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
  return;
}

