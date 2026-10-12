/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3730; label: FUN_004f3730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3730(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  FUN_004f2f20(local_204,param_2);
  FUN_004f2f20(local_104,param_3);
  FUN_004f3650(local_204,local_204,local_104);
  FUN_004f2e60(param_1,local_204);
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

