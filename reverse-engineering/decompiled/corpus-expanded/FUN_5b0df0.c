/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0df0; label: FUN_005b0df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b0df0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  undefined1 local_c [12];
  
  iVar1 = param_1;
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x50f4)) {
    param_1 = 0;
    do {
      iVar3 = 0;
      iVar5 = *(int *)(iVar1 + 0x50ec) + param_1;
      local_14 = 0;
      if (0 < *(int *)(iVar5 + 0x14)) {
        do {
          iVar4 = *(int *)(iVar5 + 0x10) + iVar3;
          iVar2 = FUN_00440120(*(undefined4 *)(iVar1 + 0x2ae8),iVar4);
          if (iVar2 == 0) {
            FUN_005cf5b0(*(undefined4 *)(iVar1 + 0x13c),local_c,iVar4,0);
            iVar2 = FUN_005cfac0(local_c);
            if (iVar2 != 0) {
              iVar2 = FUN_005cf9e0(local_c);
              goto LAB_005b0e9a;
            }
            iVar2 = FUN_0051ac10(*(undefined4 *)(iVar1 + 0x2ae8),iVar4);
            if (iVar2 != 0) {
              iVar2 = iVar2 + 0x10;
              goto LAB_005b0e9a;
            }
          }
          else {
            iVar2 = iVar2 + 0x80;
LAB_005b0e9a:
            *(int *)(iVar4 + 0x20) = iVar2;
          }
          if (*(int *)(iVar4 + 0x20) == 0) {
            *(int *)(iVar4 + 0x20) = iVar4 + 0x24;
          }
          local_14 = local_14 + 1;
          iVar3 = iVar3 + 0x44;
        } while (local_14 < *(int *)(iVar5 + 0x14));
      }
      param_1 = param_1 + 0x30;
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(iVar1 + 0x50f4));
  }
  return;
}

