/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd0e0; label: FUN_006dd0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dd0e0(void)

{
  DWORDLONG dwlConditionMask;
  undefined8 uVar1;
  DWORD aDStack_c0 [4];
  CHAR local_a0 [124];
  uint uStack_24;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_a0;
  aDStack_c0[3] = 0x6dd106;
  _memset(local_a0,0,0x9c);
  aDStack_c0[3] = 0;
  local_a0[0] = -100;
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\x06';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  aDStack_c0[2] = 0x6dd131;
  uVar1 = VerSetConditionMask();
  aDStack_c0[0] = (DWORD)((ulonglong)uVar1 >> 0x20);
  aDStack_c0[2] = 3;
  aDStack_c0[1] = 1;
  dwlConditionMask = (DWORDLONG)VerSetConditionMask((int)uVar1);
  VerifyVersionInfoA((LPOSVERSIONINFOEXA)aDStack_c0,3,dwlConditionMask);
  __security_check_cookie(uStack_24 ^ (uint)aDStack_c0);
  return;
}

