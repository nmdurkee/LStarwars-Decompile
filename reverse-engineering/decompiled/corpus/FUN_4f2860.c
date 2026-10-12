/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2860; label: FUN_004f2860
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

