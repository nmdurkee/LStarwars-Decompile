/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b05e0; label: FUN_005b05e0
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

