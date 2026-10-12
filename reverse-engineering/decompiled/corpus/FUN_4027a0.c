/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x4027a0; label: FUN_004027a0
 */

void FUN_004027a0(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int local_88;
  int local_84 [2];
  undefined1 local_7c [124];
  
  local_84[1] = 0;
  _memset(local_7c,0,0x7c);
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x2acc), iVar2 != 0)) {
    local_88 = 0;
    if (0 < *(int *)(iVar2 + 4)) {
      pbVar5 = (byte *)(*(int *)(iVar2 + 8) + 4);
      do {
        if (((pbVar5[-1] == 0) && (bVar1 = *pbVar5, bVar1 != 0)) && (bVar1 < 0x21)) {
          piVar3 = *(int **)(pbVar5 + 8);
          if (*(int *)(local_7c + (bVar1 - 1) * 4 + -4) == 0) {
            iVar4 = FUN_00401900(param_2,0);
            *(int *)(local_7c + (bVar1 - 1) * 4 + -4) = iVar4;
          }
          iVar4 = *(int *)(local_7c + (bVar1 - 1) * 4 + -4);
          if ((iVar4 != 0) && (iVar6 = 0, 0 < *piVar3)) {
            do {
              FUN_00401940(*(undefined4 *)(param_1 + 0x2ae8),iVar4,
                           **(undefined4 **)(piVar3[2] + iVar6 * 4));
              iVar6 = iVar6 + 1;
            } while (iVar6 < *piVar3);
          }
        }
        local_88 = local_88 + 1;
        pbVar5 = pbVar5 + 0x20;
      } while (local_88 < *(int *)(iVar2 + 4));
    }
  }
  return;
}

