/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x4543e0; label: FUN_004543e0
 */

undefined4
FUN_004543e0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  bVar1 = false;
  iVar5 = 0;
  local_8 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar4 = *(int **)(param_3 + 0xd0), piVar4 != (int *)0x0)) &&
       (*piVar4 != 0)) {
      local_8 = *piVar4;
      iVar5 = *(int *)(local_8 + 0xea4);
    }
    iVar6 = 0;
    bVar2 = false;
    if (0 < param_5) {
      do {
        bVar1 = bVar2;
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"player=");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"target=");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"Opponent");
              if (iVar3 == 0) {
                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"release");
                if (iVar3 != 0) {
                  bVar1 = true;
                }
              }
              else if (*(int **)(param_3 + 0xe4) != (int *)0x0) {
                iVar5 = **(int **)(param_3 + 0xe4);
              }
            }
            else if ((DAT_00923904 == (code *)0x0) ||
                    (piVar4 = (int *)(*DAT_00923904)(param_1,iVar3 + 7), piVar4 == (int *)0x0)) {
              iVar5 = 0;
            }
            else {
              iVar5 = *piVar4;
            }
          }
          else {
            FUN_005147c0(param_2,iVar3 + 7);
            iVar3 = FUN_006e6b90();
            if (iVar3 - 1U < 2) {
              local_8 = (&DAT_0093d7f0)[iVar3 - 1U];
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar4 = (int *)(*DAT_00923904)(param_1,iVar3 + 10), piVar4 == (int *)0x0)) {
          local_8 = 0;
        }
        else {
          local_8 = *piVar4;
        }
        iVar6 = iVar6 + 1;
        bVar2 = bVar1;
      } while (iVar6 < param_5);
    }
    if (local_8 != 0) {
      if (iVar5 == 0) {
        if (!bVar1) {
          return 1;
        }
      }
      else if (!bVar1) {
        if (((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x40000000) != 0) &&
           ((*(char *)(iVar5 + 0x7b5) == '\x17' || (*(char *)(iVar5 + 0x7b5) == '>')))) {
          return 0;
        }
        if (*(int *)(iVar5 + 0xcd0) != 0) {
          return 1;
        }
        if ((*(byte *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x90) & 0x40) == 0) {
          return 1;
        }
        if ((*(byte *)(*(int *)(local_8 + 0x54) + 4) & 0x10) != 0) {
          return 1;
        }
        FUN_00488730(local_8,iVar5,1,0);
        return 1;
      }
      FUN_004882d0(local_8,0);
    }
  }
  return 1;
}

