/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68e900; label: FUN_0068e900
 */

void FUN_0068e900(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_0296209c;
  cVar1 = (char)param_1;
  *(undefined4 *)(&DAT_02948eb0 + (char)param_1 * 4) = 0;
  iVar5 = 0;
  piVar3 = &DAT_02924b60;
  do {
    if ((*piVar3 != -1) && (*piVar3 != 99999)) {
      if (*(char *)((int)piVar3 + 0x41) == cVar1) {
        FUN_00684400(piVar3);
        *piVar3 = 99999;
        iVar2 = DAT_0296209c;
      }
      else {
        iVar4 = piVar3[-1];
        if (((0 < iVar4) && (*(int *)(iVar2 + iVar4 * 4) != 0)) &&
           (*(char *)(*(int *)(iVar2 + iVar4 * 4) + 0x11) == cVar1)) {
          FUN_0068bbe0(iVar5);
          iVar2 = DAT_0296209c;
        }
      }
    }
    piVar3 = piVar3 + 0x16;
    iVar5 = iVar5 + 1;
  } while ((int)piVar3 < 0x292fb60);
  iVar5 = 1;
  if (1 < DAT_02962098) {
    do {
      if ((*(int *)(iVar2 + iVar5 * 4) != 0) &&
         (*(char *)(*(int *)(iVar2 + iVar5 * 4) + 0x11) == cVar1)) {
        iVar4 = 0;
        if (0 < DAT_02962094) {
          iVar6 = 0;
          do {
            if (*(short *)(iVar6 + 0x182 + DAT_029620a4) == iVar5) {
              param_1 = iVar4;
              FUN_00684400(&param_1);
            }
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 0x330;
            iVar2 = DAT_0296209c;
          } while (iVar4 < DAT_02962094);
        }
        FUN_00655730(*(undefined4 *)(iVar2 + iVar5 * 4));
        iVar2 = DAT_0296209c;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_02962098);
  }
  return;
}

