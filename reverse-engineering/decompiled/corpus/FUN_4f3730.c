/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f3730; label: FUN_004f3730
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

