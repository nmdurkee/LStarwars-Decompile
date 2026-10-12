/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4fa180; label: FUN_004fa180
 */

void FUN_004fa180(int param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  local_48 = param_2;
  if (*(char *)(param_1 + 0x578) == '\0') {
    pcVar1 = *(char **)(param_1 + 0x510);
    pcVar5 = local_44;
    if ((pcVar1 != (char *)0x0) && (cVar2 = *pcVar1, cVar2 != '\0')) {
      do {
        *pcVar5 = cVar2;
        cVar2 = pcVar5[(int)(pcVar1 + (1 - (int)local_44))];
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
    }
    *pcVar5 = '\0';
  }
  else {
    FUN_004f2dc0(local_44,*(undefined4 *)(param_1 + 0x510));
  }
  if ((local_44[0] == '\0') || (local_44[0] == ';')) {
    __security_check_cookie(local_4 ^ (uint)&local_48);
    return;
  }
  iVar4 = *(int *)(param_1 + 0x570);
  if (-1 < iVar4) {
    piVar7 = *(int **)(param_1 + 0x530 + iVar4 * 4);
    iVar6 = 0;
    for (iVar3 = *piVar7; iVar3 != 0; iVar3 = piVar7[iVar3 + 2]) {
      iVar3 = FUN_004f8b10(iVar3,local_44);
      if (iVar3 == 0) goto LAB_004fa297;
      iVar3 = iVar6 * 2;
      iVar6 = iVar6 + 1;
    }
    if (*(int *)(param_1 + 0x550 + iVar4 * 4) != 0) {
      piVar7 = *(int **)(param_1 + 0x550 + iVar4 * 4);
      iVar6 = 0;
      for (iVar4 = *piVar7; iVar4 != 0; iVar4 = piVar7[iVar4 + 2]) {
        iVar4 = FUN_004f8b10(iVar4,local_44);
        if (iVar4 == 0) {
LAB_004fa297:
          (*(code *)piVar7[iVar6 * 2 + 1])(param_1,local_48);
          __security_check_cookie(local_4 ^ (uint)&local_48);
          return;
        }
        iVar4 = iVar6 * 2;
        iVar6 = iVar6 + 1;
      }
    }
  }
  if (DAT_0091eec4 != (code *)0x0) {
    (*DAT_0091eec4)(param_1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

