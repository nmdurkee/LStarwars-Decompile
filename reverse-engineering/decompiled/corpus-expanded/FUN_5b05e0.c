/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b05e0; label: FUN_005b05e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b05e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20 [12];
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_20;
  if (*(int *)(param_1 + 0x50fc) != 0) {
    __security_check_cookie(local_4 ^ (uint)local_20);
    return;
  }
  FUN_006217e0();
  iVar1 = FUN_006217e0();
  if (0 < iVar1) {
    do {
      uVar2 = FUN_006217e0();
      FUN_006216f0(local_14,uVar2);
      FUN_006217a0();
      FUN_00621890();
      FUN_00621900(local_20);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  __security_check_cookie(local_4 ^ (uint)local_20);
  return;
}

