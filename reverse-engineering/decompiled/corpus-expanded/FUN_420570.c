/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420570; label: FUN_00420570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00420570(void)

{
  byte bVar1;
  byte bVar2;
  uint in_EAX;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  uint local_8;
  
  iVar5 = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    do {
      if (((-1 < *(int *)(in_ECX + 0x3c + iVar5 * 4)) && (-1 < *(int *)(in_ECX + 0x4c + iVar5 * 4)))
         && (local_8 = 0, 0 < *(int *)(in_ECX + 0x1c))) {
        piVar7 = (int *)(in_ECX + 0xa4);
        do {
          pcVar6 = (char *)piVar7[2];
          iVar4 = 0;
          if (0 < *piVar7) {
            do {
              if (*pcVar6 == '\0') {
                if (iVar5 == 0) {
                  bVar1 = pcVar6[3];
                  bVar2 = bVar1 & 0x20;
                }
                else {
                  if (iVar5 != 1) goto LAB_004205fc;
                  bVar1 = pcVar6[3];
                  bVar2 = bVar1 & 0x40;
                }
                if (((bVar2 == 0) && ((bVar1 & 8) == 0)) &&
                   (iVar3 = FUN_006d68e0(0,pcVar6[1],1,iVar5), iVar3 == 0)) {
                  return 1;
                }
              }
LAB_004205fc:
              iVar4 = iVar4 + 1;
              pcVar6 = pcVar6 + 8;
            } while (iVar4 < *piVar7);
          }
          in_EAX = local_8 + 1;
          piVar7 = piVar7 + 3;
          local_8 = in_EAX;
        } while ((int)in_EAX < *(int *)(in_ECX + 0x1c));
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 4));
  }
  return in_EAX & 0xffffff00;
}

