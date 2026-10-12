/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703a8b; label: FUN_00703a8b
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00703a8b(int param_1,int param_2)

{
  bool bVar1;
  char extraout_CL;
  DName *in_ECX;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  char local_d [5];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  *(uint *)(in_ECX + 4) = *(uint *)(in_ECX + 4) & 0xfffff000;
  pcVar3 = local_d + 2;
  *(undefined4 *)in_ECX = 0;
  local_d[2] = 0;
  bVar1 = false;
  lVar4 = CONCAT44(param_2,param_1);
  if ((param_2 < 1) && (lVar4 = CONCAT44(param_2,param_1), param_2 < 0)) {
    bVar1 = true;
    lVar4 = CONCAT44(-(param_2 + (uint)(param_1 != 0)),-param_1);
  }
  do {
    pcVar2 = pcVar3;
    pcVar3 = pcVar2 + -1;
    lVar4 = __aulldvrm(lVar4,10,0);
    *pcVar3 = extraout_CL + '0';
  } while (lVar4 != 0);
  if (bVar1) {
    pcVar3 = pcVar2 + -2;
    *pcVar3 = '-';
  }
  DName::doPchar(in_ECX,pcVar3,(int)(local_d + (2 - (int)pcVar3)));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

