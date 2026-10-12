/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610010; label: FUN_00610010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610010(char *param_1)

{
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  FUN_006de740();
  __vsnprintf(local_84,0x7e,param_1,&stack0x00000008);
  FUN_006de730();
  FUN_004f1e80(local_84,&DAT_0076aa4c);
  FID_conflict__wprintf(local_84);
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

