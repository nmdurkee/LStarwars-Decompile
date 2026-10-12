/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f76f0; label: FUN_004f76f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f76f0(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  char *pcVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  
  uVar8 = 0x811c9dc5;
  cVar1 = *param_2;
  pcVar6 = param_2;
  while (cVar1 != '\0') {
    uVar8 = ((int)cVar1 ^ uVar8) * 0x199933;
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar6;
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    puVar7 = *(uint **)(param_1 + 0x1c);
    do {
      if (*puVar7 == uVar8) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  iVar3 = *(int *)(param_1 + 0x20);
  if (iVar3 != 0) {
    pcVar6 = *(char **)(param_1 + 0x28);
    iVar9 = 0;
    if (0 < iVar3) {
      do {
        if (pcVar6 != (char *)0x0) {
          pcVar10 = param_2;
          while( true ) {
            cVar1 = pcVar10[(int)pcVar6 - (int)param_2];
            cVar2 = *pcVar10;
            if ((cVar2 < cVar1) || (cVar1 < cVar2)) break;
            pcVar10 = pcVar10 + 1;
            if ((cVar1 == '\0') || (cVar2 == '\0')) {
              iVar3 = 0;
              cVar1 = *pcVar6;
              while (cVar1 != '\0') {
                iVar3 = iVar3 + 1;
                cVar1 = pcVar6[iVar3];
              }
              psVar4 = (short *)(pcVar6 + iVar3 + 1);
              if (((uint)psVar4 & 1) != 0) {
                psVar4 = (short *)((int)psVar4 + 1);
              }
              return (int)*psVar4;
            }
          }
        }
        iVar5 = 0;
        cVar1 = *pcVar6;
        while (cVar1 != '\0') {
          iVar5 = iVar5 + 1;
          cVar1 = pcVar6[iVar5];
        }
        pcVar6 = pcVar6 + iVar5 + 3;
        if (((uint)pcVar6 & 1) != 0) {
          pcVar6 = pcVar6 + 1;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar3);
    }
  }
  return -1;
}

