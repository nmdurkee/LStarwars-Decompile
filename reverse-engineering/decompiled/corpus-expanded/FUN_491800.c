/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x491800; label: FUN_00491800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

