/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x445740; label: FUN_00445740
 */

undefined4
FUN_00445740(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  int local_4;
  
  iVar4 = 0;
  local_8 = 0;
  local_4 = 0;
  if (param_6 != 0) {
    iVar3 = 0;
    if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
      iVar3 = *(int *)(param_3 + 0xd0);
    }
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757700);
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"state=");
            if (iVar2 != 0) {
              local_4 = iVar2 + 6;
            }
          }
          else {
            FUN_005147c0(param_2,iVar2 + 4);
            local_8 = FUN_006e6b90();
            if (((int)local_8 < 0) || (0x10 < (int)local_8)) {
              local_8 = 0;
            }
          }
        }
        else if (DAT_00923904 != (code *)0x0) {
          iVar3 = (*DAT_00923904)(param_1,iVar2 + 10);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
      if (local_4 != 0) {
        if (local_8 == 0) {
          if ((((iVar3 != 0) && (piVar5 = *(int **)(iVar3 + 4), piVar5 != (int *)0x0)) &&
              (*piVar5 != 0)) && (iVar4 = FUN_00512fc0(local_4,*piVar5), iVar4 != 0)) {
            *(undefined4 *)(*(int *)(iVar3 + 4) + 100) = 0;
            puVar1 = *(undefined4 **)(iVar3 + 4);
            FUN_00514640(param_1,puVar1,puVar1,0,0,0,0,*puVar1,iVar4);
          }
        }
        else {
          iVar4 = 0;
          if (0 < DAT_0093d500) {
            piVar5 = (int *)(DAT_0093d504 + 4);
            do {
              if ((((piVar5[0x7e] & 1U) != 0) && ((piVar5[0x7e] & 0x1000U) != 0)) &&
                 ((*(byte *)(piVar5 + 0xdd) == local_8 &&
                  (iVar3 = FUN_00512fc0(local_4,*(undefined4 *)*piVar5), iVar3 != 0)))) {
                *(undefined4 *)(*piVar5 + 100) = 0;
                puVar1 = (undefined4 *)*piVar5;
                FUN_00514640(param_1,puVar1,puVar1,0,0,0,0,*puVar1,iVar3);
              }
              iVar4 = iVar4 + 1;
              piVar5 = piVar5 + 0x436;
            } while (iVar4 < DAT_0093d500);
            return 1;
          }
        }
      }
    }
  }
  return 1;
}

