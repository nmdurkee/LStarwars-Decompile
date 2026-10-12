/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4fa020; label: FUN_004fa020
 */

void FUN_004fa020(int param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  pcVar6 = local_44;
  if (*(char *)(param_1 + 0x578) == '\0') {
    pcVar1 = *(char **)(param_1 + 0x510);
    if ((pcVar1 != (char *)0x0) && (cVar3 = *pcVar1, cVar3 != '\0')) {
      do {
        *pcVar6 = cVar3;
        cVar3 = pcVar6[(int)(pcVar1 + (1 - (int)local_44))];
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
    }
    *pcVar6 = '\0';
  }
  else {
    FUN_004f2dc0(pcVar6,*(undefined4 *)(param_1 + 0x510));
  }
  if ((local_44[0] != '\0') && (local_44[0] != ';')) {
    iVar5 = *(int *)(param_1 + 0x570);
    if (-1 < iVar5) {
      piVar2 = *(int **)(param_1 + 0x530 + iVar5 * 4);
      iVar7 = 0;
      for (iVar4 = *piVar2; iVar4 != 0; iVar4 = piVar2[iVar4 + 2]) {
        iVar4 = FUN_004f8b10(iVar4,local_44);
        if (iVar4 == 0) {
          (*(code *)piVar2[iVar7 * 2 + 1])(param_1);
          __security_check_cookie(local_4 ^ (uint)local_44);
          return;
        }
        iVar4 = iVar7 * 2;
        iVar7 = iVar7 + 1;
      }
      if (*(int *)(param_1 + 0x550 + iVar5 * 4) != 0) {
        piVar2 = *(int **)(param_1 + 0x550 + iVar5 * 4);
        iVar4 = 0;
        for (iVar5 = *piVar2; iVar5 != 0; iVar5 = piVar2[iVar5 + 2]) {
          iVar5 = FUN_004f8b10(iVar5,local_44);
          if (iVar5 == 0) {
            (*(code *)piVar2[iVar4 * 2 + 1])(param_1);
            __security_check_cookie(local_4 ^ (uint)local_44);
            return;
          }
          iVar5 = iVar4 * 2;
          iVar4 = iVar4 + 1;
        }
      }
    }
    if (DAT_0091eec4 != (code *)0x0) {
      (*DAT_0091eec4)(param_1);
    }
    __security_check_cookie(local_4 ^ (uint)local_44);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

