/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x4541e0; label: FUN_004541e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004541e0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  local_4 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      local_4 = *piVar2;
    }
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"victim=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"attacker=opponent");
          if (iVar1 == 0) {
            if ((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xe4), piVar2 != (int *)0x0))
            goto LAB_004542dc;
          }
          else {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"attacker=");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"attacker=player");
              if (iVar1 == 0) {
                piVar2 = *(int **)(param_1 + 0x138c);
                goto LAB_004542dc;
              }
            }
            else if ((DAT_00923904 == (code *)0x0) ||
                    (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 9), piVar2 == (int *)0x0)) {
              iVar3 = 0;
            }
            else {
LAB_004542dc:
              iVar3 = *piVar2;
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 7), piVar2 == (int *)0x0)) {
          local_4 = 0;
        }
        else {
          local_4 = *piVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if ((local_4 != 0) && (iVar3 != 0)) {
      *(int *)(local_4 + 0x10a8) = iVar3;
    }
  }
  return 1;
}

