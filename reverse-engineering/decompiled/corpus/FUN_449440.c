/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449440; label: FUN_00449440
 */

undefined4
FUN_00449440(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_34;
  int aiStack_28 [10];
  
  iVar8 = 0;
  uVar7 = 0;
  iVar6 = 0;
  bVar1 = true;
  local_34 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar4 = *(int **)(param_3 + 0xd0), piVar4 != (int *)0x0)) &&
       (*piVar4 != 0)) {
      iVar6 = *piVar4;
    }
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_0075772c);
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"character=");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"FALSE");
            if (iVar3 == 0) {
              bVar1 = false;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"still_do_take_hit_anim");
              if (iVar3 == 0) {
                uVar7 = 1;
              }
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar4 = (int *)(*DAT_00923904)(param_1,iVar3 + 10), piVar4 == (int *)0x0)) {
            iVar6 = 0;
          }
          else {
            iVar6 = *piVar4;
          }
        }
        else if (((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) &&
                ((cVar2 = (*DAT_00923884)(iVar3 + 5), cVar2 != -1 &&
                 ((iVar3 = (*DAT_00923894)(cVar2), iVar3 != -1 && (local_34 < 10)))))) {
          aiStack_28[local_34] = iVar3;
          local_34 = local_34 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < param_5);
      if (local_34 != 0) {
        iVar6 = 0;
        if (DAT_0093d500 < 1) {
          return 1;
        }
        puVar5 = (uint *)(DAT_0093d504 + 0xef0);
        do {
          if (((((puVar5[-0x33d] & 1) != 0) && ((puVar5[-0x33d] & 0x1000) != 0)) &&
              ((puVar5[-0x33e] & 0x400) != 0)) && (iVar8 = 0, 0 < local_34)) {
            do {
              if ((int)(short)puVar5[0x5d] == aiStack_28[iVar8]) {
                if (bVar1) {
                  *puVar5 = (uVar7 | 0x400) << 0xc | *puVar5 & 0xffffefff;
                }
                else {
                  *puVar5 = *puVar5 & 0xffbfffff;
                }
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < local_34);
          }
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 0x436;
        } while (iVar6 < DAT_0093d500);
        return 1;
      }
    }
    if ((iVar6 != 0) && ((*(uint *)(iVar6 + 0x1f8) & 0x400) != 0)) {
      if (bVar1) {
        *(uint *)(iVar6 + 0xef0) = (uVar7 | 0x400) << 0xc | *(uint *)(iVar6 + 0xef0) & 0xffffefff;
        return 1;
      }
      *(uint *)(iVar6 + 0xef0) = *(uint *)(iVar6 + 0xef0) & 0xffbfffff;
      return 1;
    }
  }
  return 1;
}

