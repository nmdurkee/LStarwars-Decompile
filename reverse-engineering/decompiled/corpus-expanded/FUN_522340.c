/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x522340; label: FUN_00522340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00522340(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
    pcVar5 = (char *)(param_2 + 0x4c);
    pcVar2 = pcVar5;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((pcVar2 != (char *)(param_2 + 0x4d)) &&
       (iVar3 = FUN_004f8b10(&DAT_007600a0,pcVar5), iVar3 != 0)) {
      for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar3 != 0;
          iVar3 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar3)) {
        iVar4 = FUN_004f8b10(iVar3 + 8,pcVar5);
        if (iVar4 == 0) {
          return;
        }
      }
      pcVar2 = (char *)(*(int *)(DAT_009238e4 + 0x41208) + 8);
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

