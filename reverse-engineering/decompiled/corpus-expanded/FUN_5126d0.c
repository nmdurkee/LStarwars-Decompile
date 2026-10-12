/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x5126d0; label: FUN_005126d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005126d0(undefined4 param_1)

{
  int iVar1;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  FUN_0050f740(param_1,DAT_0297ade4,DAT_00921d60);
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  iVar1 = FUN_006e6b90();
  FUN_004f2740(local_104,"%s (%ds)",DAT_0297adec,iVar1 + 1);
  FUN_0050f740(param_1,local_104,DAT_00921d60);
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

