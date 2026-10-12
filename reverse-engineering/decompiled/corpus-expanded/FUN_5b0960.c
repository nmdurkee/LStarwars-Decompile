/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0960; label: FUN_005b0960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b0960(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_3 + 0x50ec) != 0) && (iVar2 = 0, 0 < *(int *)(param_3 + 0x50f4))) {
    iVar1 = 0;
    do {
      FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x50ec) + iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x30;
    } while (iVar2 < *(int *)(param_3 + 0x50f4));
  }
  return;
}

