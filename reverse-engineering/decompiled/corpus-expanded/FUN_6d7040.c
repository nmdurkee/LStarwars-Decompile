/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d7040; label: FUN_006d7040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d7040(int param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_4;
  
  local_4 = 0;
  if (3 < *(int *)(in_ECX + 0x6558 + param_1 * 4) - 10U) {
    return 0;
  }
  pcVar1 = (char *)(param_1 * 0x80 + 0x6358 + in_ECX);
  local_c = 0;
  cVar5 = DAT_02975148;
  if (0 < param_2) {
    local_1c = in_ECX + 0x6358;
    local_18 = (int *)(in_ECX + 0x6558);
    local_14 = -0x6358 - in_ECX;
    do {
      if ((local_c != param_1) && (*local_18 - 10U < 4)) {
        if (cVar5 < '\0') {
          local_10 = 0x20;
          pcVar6 = pcVar1;
          do {
            if (*pcVar6 != '\0') {
              pcVar7 = pcVar1 + 0xc;
              pcVar4 = (char *)(local_1c + 4);
              iVar8 = 8;
              do {
                if (((pcVar7[-0xc] != '\0') && (*(short *)(pcVar6 + 2) == *(short *)(pcVar4 + -2)))
                   && (*pcVar6 == pcVar4[-4])) {
                  pcVar6[2] = '\0';
                  pcVar6[3] = '\0';
                  *pcVar6 = '\0';
                }
                if (((pcVar4[(int)(pcVar1 + local_14)] != '\0') &&
                    (*(short *)(pcVar6 + 2) == *(short *)(pcVar4 + 2))) && (*pcVar6 == *pcVar4)) {
                  pcVar6[2] = '\0';
                  pcVar6[3] = '\0';
                  *pcVar6 = '\0';
                }
                if (((pcVar7[-4] != '\0') && (*(short *)(pcVar6 + 2) == *(short *)(pcVar4 + 6))) &&
                   (*pcVar6 == pcVar4[4])) {
                  pcVar6[2] = '\0';
                  pcVar6[3] = '\0';
                  *pcVar6 = '\0';
                }
                if (((*pcVar7 != '\0') && (*(short *)(pcVar6 + 2) == *(short *)(pcVar4 + 10))) &&
                   (*pcVar6 == pcVar4[8])) {
                  pcVar6[2] = '\0';
                  pcVar6[3] = '\0';
                  *pcVar6 = '\0';
                }
                pcVar4 = pcVar4 + 0x10;
                pcVar7 = pcVar7 + 0x10;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            pcVar6 = pcVar6 + 4;
            local_10 = local_10 + -1;
            cVar5 = DAT_02975148;
          } while (local_10 != 0);
        }
        else {
          pcVar6 = &DAT_02975148;
          cVar2 = cVar5;
          while (iVar8 = (int)cVar2, -1 < iVar8) {
            pcVar6 = pcVar6 + 1;
            if (pcVar1[iVar8 * 4] != '\0') {
              pcVar7 = &DAT_02975148;
              cVar2 = cVar5;
              while (iVar3 = (int)cVar2, -1 < iVar3) {
                pcVar7 = pcVar7 + 1;
                if (((pcVar1[iVar3 * 4] != '\0') && (*(short *)(pcVar1 + iVar3 * 4 + 2) != 0xff)) &&
                   ((*(short *)(pcVar1 + iVar8 * 4 + 2) == *(short *)(local_1c + 2 + iVar3 * 4) &&
                    (pcVar1[iVar8 * 4] == *(char *)(local_1c + iVar3 * 4))))) {
                  (pcVar1 + iVar8 * 4 + 2)[0] = '\0';
                  (pcVar1 + iVar8 * 4 + 2)[1] = '\0';
                  pcVar1[iVar8 * 4] = '\0';
                }
                cVar5 = DAT_02975148;
                cVar2 = *pcVar7;
              }
            }
            cVar2 = *pcVar6;
          }
        }
      }
      local_18 = local_18 + 1;
      local_14 = local_14 + -0x80;
      local_1c = local_1c + 0x80;
      local_c = local_c + 1;
    } while (local_c < param_2);
  }
  iVar8 = (int)cVar5;
  pcVar6 = &DAT_02975148;
  if (-1 < iVar8) {
    while (((pcVar6 = pcVar6 + 1, DAT_029755b4 != (code *)0x0 &&
            (iVar3 = (*DAT_029755b4)(*(undefined4 *)(in_ECX + 0x6558 + param_1 * 4),iVar8),
            iVar3 == 0)) || (pcVar1[iVar8 * 4] != '\0'))) {
      iVar8 = (int)*pcVar6;
      if (iVar8 < 0) {
        return 0;
      }
    }
    local_4 = 1;
  }
  return local_4;
}

