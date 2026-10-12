/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x511e80; label: FUN_00511e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00511e80(void)

{
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4;
  __security_check_cookie(local_4 ^ (uint)&local_4);
  return;
}

