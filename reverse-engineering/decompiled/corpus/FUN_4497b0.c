/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x4497b0; label: FUN_004497b0
 */

undefined4
FUN_004497b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int local_30;
  int local_2c;
  int aiStack_28 [10];
  
  iVar6 = 0;
  iVar5 = 0;
  local_2c = 1;
  local_30 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      iVar5 = *piVar3;
    }
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_0075772c);
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"FALSE");
            if (iVar2 == 0) {
              local_2c = 0;
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *piVar3;
          }
        }
        else if (((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) &&
                ((cVar1 = (*DAT_00923884)(iVar2 + 5), cVar1 != -1 &&
                 ((iVar2 = (*DAT_00923894)(cVar1), iVar2 != -1 && (local_30 < 10)))))) {
          aiStack_28[local_30] = iVar2;
          local_30 = local_30 + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
      if (local_30 != 0) {
        iVar5 = 0;
        if (DAT_0093d500 < 1) {
          return 1;
        }
        puVar4 = (uint *)(DAT_0093d504 + 0x1fc);
        do {
          if (((((*puVar4 & 1) != 0) && ((*puVar4 & 0x1000) != 0)) && ((puVar4[-1] & 0x400) != 0))
             && (iVar6 = 0, 0 < local_30)) {
            do {
              if ((int)(short)puVar4[0x39a] == aiStack_28[iVar6]) {
                *puVar4 = *puVar4 ^ (local_2c * 2 ^ *puVar4) & 2;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < local_30);
          }
          iVar5 = iVar5 + 1;
          puVar4 = puVar4 + 0x436;
        } while (iVar5 < DAT_0093d500);
        return 1;
      }
    }
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0x1fc) =
           *(uint *)(iVar5 + 0x1fc) ^ (local_2c * 2 ^ *(uint *)(iVar5 + 0x1fc)) & 2;
    }
  }
  return 1;
}

