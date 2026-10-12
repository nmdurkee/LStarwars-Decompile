/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff4f0; label: FUN_004ff4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff4f0(undefined4 param_1,undefined4 param_2)

{
  CHAR local_204 [256];
  CHAR local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  FUN_004f0180(local_104,param_2,0x100);
  FUN_004f0180(local_204,param_1,0x100);
  DeleteFileA(local_204);
  MoveFileA(local_104,local_204);
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

