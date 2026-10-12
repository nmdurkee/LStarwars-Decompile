/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca920; label: FUN_006ca920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ca920(int param_1)

{
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_94;
  if ((*(char *)(param_1 + 0x66) != '\0') &&
     (local_94 = *(float *)(param_1 + 0x170), local_94 != 0.0)) {
    local_90 = DAT_0081faa0;
    _DAT_0081faac = 0xff008000;
    local_8c = DAT_0081faa4;
    local_88 = DAT_0081faa8;
    if ((*(char *)(param_1 + 0x91) != '\0') &&
       (local_94 = *(float *)(param_1 + 0x17c), local_94 != 0.0)) {
      FUN_006ca250(local_84,0x80);
      FUN_006ba280(local_84);
      __security_check_cookie(local_4 ^ (uint)&local_94);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_94);
  return;
}

