/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x449680; label: FUN_00449680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00449680(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  uint local_4;
  
  iVar6 = 0;
  bVar1 = 1;
  local_8 = 0;
  local_4 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      local_8 = *piVar3;
    }
    uVar5 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"dont_avoid=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"FALSE");
            if (iVar2 == 0) {
              bVar1 = 0;
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (puVar4 = (uint *)(*DAT_00923904)(param_1,iVar2 + 0xb), puVar4 == (uint *)0x0)) {
            local_4 = 0;
          }
          else {
            local_4 = *puVar4;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
          local_8 = 0;
        }
        else {
          local_8 = *piVar3;
        }
        iVar6 = iVar6 + 1;
        uVar5 = local_4;
      } while (iVar6 < param_5);
    }
    if ((local_8 != 0) && (uVar5 != 0)) {
      *(uint *)(local_8 + 0x3bc) = -(uint)bVar1 & uVar5;
    }
    return 1;
  }
  return 1;
}

