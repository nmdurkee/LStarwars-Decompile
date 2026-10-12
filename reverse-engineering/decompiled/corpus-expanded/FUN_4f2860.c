/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2860; label: FUN_004f2860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2860(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char local_28 [36];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_28;
  pcVar2 = local_28;
  if (param_1 < 0) {
    param_1 = -param_1;
    *param_2 = '-';
    param_2 = param_2 + 1;
  }
  do {
    iVar1 = param_1 / param_3;
    pcVar3 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 % param_3) + '0';
    param_1 = iVar1;
    pcVar2 = pcVar3;
  } while (iVar1 != 0);
  if (pcVar3 != local_28) {
    do {
      pcVar2 = pcVar3 + -1;
      pcVar3 = pcVar3 + -1;
      *param_2 = *pcVar2;
      param_2 = param_2 + 1;
    } while (pcVar3 != local_28);
  }
  *param_2 = '\0';
  __security_check_cookie(local_4 ^ (uint)local_28);
  return;
}

