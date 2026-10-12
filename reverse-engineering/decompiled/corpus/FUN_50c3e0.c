/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50c3e0; label: FUN_0050c3e0
 */

void FUN_0050c3e0(char *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char local_404 [512];
  char local_204;
  char local_203 [511];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  iVar7 = 0;
  iVar6 = 0;
  cVar3 = *param_1;
  while (cVar3 != '\0') {
    cVar3 = param_1[iVar7];
    if ((cVar3 == '[') && (param_1[iVar7 + 1] == '[')) {
      iVar1 = iVar7 + 2;
      iVar7 = iVar7 + 2;
      iVar4 = 0;
      cVar3 = param_1[iVar1];
      while ((cVar3 != '\0' && (cVar3 != ']'))) {
        iVar7 = iVar7 + 1;
        local_404[iVar4] = cVar3;
        iVar4 = iVar4 + 1;
        cVar3 = param_1[iVar7];
      }
      cVar3 = param_1[iVar7];
      while (cVar3 == ']') {
        iVar7 = iVar7 + 1;
        cVar3 = param_1[iVar7];
      }
      local_404[iVar4] = '\0';
      FUN_0050c190(local_404,&local_204);
      if (local_204 != '\0') {
        pcVar5 = &local_204;
        cVar3 = local_204;
        do {
          pcVar5 = pcVar5 + 1;
          *(char *)(param_2 + iVar6) = cVar3;
          cVar3 = *pcVar5;
          iVar6 = iVar6 + 1;
        } while (cVar3 != '\0');
      }
    }
    else if (cVar3 == -0x1d) {
      if ((param_1[iVar7 + 1] == -0x80) && (param_1[iVar7 + 2] == -0x80)) {
        *(undefined1 *)(param_2 + iVar6) = 0x20;
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 3;
      }
      else if ((param_1[iVar7 + 1] == -0x80) && (param_1[iVar7 + 2] == -0x7f)) {
        *(undefined1 *)(param_2 + iVar6) = 0xe3;
        *(char *)(param_2 + iVar6 + 1) = param_1[iVar7 + 1];
        *(char *)(param_2 + iVar6 + 2) = param_1[iVar7 + 2];
        iVar7 = iVar7 + 3;
        *(undefined1 *)(param_2 + iVar6 + 3) = 0x20;
        iVar6 = iVar6 + 4;
      }
      else {
        if ((param_1[iVar7 + 1] == -0x80) && (param_1[iVar7 + 2] == -0x7e)) {
          *(undefined1 *)(param_2 + iVar6) = 0xe3;
          goto LAB_0050c5c0;
        }
        if ((param_1[iVar7 + 1] != -0x80) || (param_1[iVar7 + 2] != -0x7b)) goto LAB_0050c569;
        *(undefined1 *)(param_2 + iVar6) = 0xe3;
        *(char *)(param_2 + iVar6 + 1) = param_1[iVar7 + 1];
        *(char *)(param_2 + iVar6 + 2) = param_1[iVar7 + 2];
        iVar7 = iVar7 + 3;
        *(undefined1 *)(param_2 + iVar6 + 3) = 0x20;
        iVar6 = iVar6 + 4;
      }
    }
    else {
LAB_0050c569:
      if (cVar3 == -0x11) {
        if ((param_1[iVar7 + 1] == -0x44) && (param_1[iVar7 + 2] == -0x7f)) {
          *(undefined1 *)(param_2 + iVar6) = 0xef;
          *(char *)(param_2 + iVar6 + 1) = param_1[iVar7 + 1];
          *(char *)(param_2 + iVar6 + 2) = param_1[iVar7 + 2];
          iVar7 = iVar7 + 3;
          *(undefined1 *)(param_2 + iVar6 + 3) = 0x20;
          iVar6 = iVar6 + 4;
        }
        else {
          if ((param_1[iVar7 + 1] != -0x44) || (param_1[iVar7 + 2] != -0x61)) goto LAB_0050c5e9;
          *(undefined1 *)(param_2 + iVar6) = 0xef;
LAB_0050c5c0:
          *(char *)(param_2 + iVar6 + 1) = param_1[iVar7 + 1];
          *(char *)(param_2 + iVar6 + 2) = param_1[iVar7 + 2];
          iVar7 = iVar7 + 3;
          *(undefined1 *)(param_2 + iVar6 + 3) = 0x20;
          iVar6 = iVar6 + 4;
        }
      }
      else {
LAB_0050c5e9:
        iVar7 = iVar7 + 1;
        *(char *)(param_2 + iVar6) = cVar3;
        bVar2 = param_1[iVar7];
        while ((iVar6 = iVar6 + 1, 0x7f < bVar2 && (bVar2 < 0xc0))) {
          iVar7 = iVar7 + 1;
          *(byte *)(param_2 + iVar6) = bVar2;
          bVar2 = param_1[iVar7];
        }
      }
    }
    if (0x1df < iVar6) break;
    cVar3 = param_1[iVar7];
  }
  *(undefined1 *)(param_2 + iVar6) = 0;
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

