/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x491800; label: FUN_00491800
 */

void FUN_00491800(void)

{
  undefined1 local_2ac [680];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_2ac;
  FUN_00491620();
  FUN_00491760();
  __security_check_cookie(local_4 ^ (uint)local_2ac);
  return;
}

