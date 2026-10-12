/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622e20; label: FUN_00622e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622e20(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  puVar5 = &DAT_02900c88;
  if ((DAT_02913060 != '\0') && (iVar6 = 0, 0 < DAT_02913058)) {
    while (iVar2 = FUN_004f8b10(puVar5 + 7,&DAT_02913060), iVar2 != 0) {
      iVar2 = FUN_004f1ff0(puVar5);
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + iVar2 + 1;
      if (DAT_02913058 <= iVar6) {
        return;
      }
    }
    DAT_02913050 = 0;
    PTR_DAT_0080facc = puVar5;
    PTR_DAT_0080fad0 = puVar5;
    DAT_02913054 = iVar6;
    if (0 < iVar6) {
      iVar2 = iVar6 + 0xe;
      do {
        if (iVar2 <= DAT_02913058) {
          return;
        }
        iVar4 = 0;
        if (PTR_DAT_0080facc == &DAT_02900c88) {
          return;
        }
        pcVar3 = PTR_DAT_0080facc + -2;
        cVar1 = PTR_DAT_0080facc[-2];
        while (cVar1 != '\0') {
          if (pcVar3 == &DAT_02900c88) {
            iVar4 = iVar4 + 2;
            goto LAB_00622ec9;
          }
          pcVar3 = pcVar3 + -1;
          iVar4 = iVar4 + 1;
          cVar1 = *pcVar3;
        }
        iVar4 = iVar4 + 1;
LAB_00622ec9:
        if (iVar4 == 0) {
          return;
        }
        DAT_02913054 = DAT_02913054 + -1;
        DAT_02913050 = DAT_02913050 + 1;
        PTR_DAT_0080facc = PTR_DAT_0080facc + -iVar4;
        iVar6 = iVar6 + -1;
        iVar2 = iVar2 + -1;
      } while (0 < iVar6);
    }
  }
  return;
}

