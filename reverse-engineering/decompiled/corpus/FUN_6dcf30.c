/* Ghidra analysis pseudocode, not original source.
 * ev_6bac4da6f4ce0ce73312601f89fbd0303a514d0896ac0cebe3875471fcd2a12c
 * Entry: 0x6dcf30; label: FUN_006dcf30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dcf30(char *param_1)

{
  char cVar1;
  HMODULE hModule;
  int iVar2;
  char *pcVar3;
  int iVar4;
  bool bVar5;
  LPSTR lpFilename;
  DWORD nSize;
  
  nSize = 0x104;
  lpFilename = &DAT_02975c68;
  DAT_00827664 = 1;
  hModule = GetModuleHandleA((LPCSTR)0x0);
  GetModuleFileNameA(hModule,lpFilename,nSize);
  _DAT_02975a90 = &DAT_02975c68;
  iVar2 = 0;
  do {
    pcVar3 = &DAT_02975c68 + iVar2;
    (&DAT_02989580)[iVar2] = *pcVar3;
    iVar2 = iVar2 + 1;
  } while (*pcVar3 != '\0');
  DAT_02975c3c = 0;
  DAT_02975c24 = 0;
  cVar1 = *param_1;
  iVar2 = DAT_00827664;
  do {
    if (cVar1 == '\0') {
      DAT_00827664 = iVar2;
      return;
    }
    cVar1 = *param_1;
    while (cVar1 == ' ') {
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    }
    DAT_00827664 = iVar2;
    if (*param_1 == '\"') {
      param_1 = param_1 + 1;
      iVar4 = 0;
      *(char **)(&DAT_02975a90 + iVar2 * 4) = param_1;
      if (*param_1 == '\0') goto LAB_006dd00b;
      do {
        if (*param_1 == '\"') {
          *param_1 = '\0';
          param_1 = param_1 + 1;
          bVar5 = iVar4 == 0;
          goto LAB_006dd009;
        }
        param_1 = param_1 + 1;
        iVar4 = iVar4 + 1;
      } while (*param_1 != '\0');
      bVar5 = iVar4 == 0;
LAB_006dd009:
      if (bVar5) goto LAB_006dd00b;
    }
    else {
      iVar4 = 0;
      if (*param_1 == ' ') {
        param_1 = param_1 + 1;
      }
      *(char **)(&DAT_02975a90 + iVar2 * 4) = param_1;
      if (*param_1 != '\0') {
        do {
          pcVar3 = param_1;
          if (*pcVar3 == ' ') {
            *pcVar3 = '\0';
            break;
          }
          iVar4 = iVar4 + 1;
          param_1 = pcVar3 + 1;
        } while (pcVar3[1] != '\0');
        param_1 = pcVar3 + 1;
        bVar5 = iVar4 == 0;
        goto LAB_006dd009;
      }
LAB_006dd00b:
      *(undefined4 *)(&DAT_02975a90 + iVar2 * 4) = 0;
    }
    iVar2 = FUN_004f8b10(*(undefined4 *)(&DAT_02975a90 + iVar2 * 4),"-RelaunchMCE");
    if (iVar2 == 0) {
      DAT_02975c3c = 1;
    }
    else {
      iVar2 = FUN_004f8b10(*(undefined4 *)(&DAT_02975a90 + DAT_00827664 * 4),"-NoFocus_Pause");
      if (iVar2 == 0) {
        DAT_02975c24 = 0;
      }
      else {
        iVar2 = FUN_004f8b10(*(undefined4 *)(&DAT_02975a90 + DAT_00827664 * 4),"-NoFocus_Process");
        if (iVar2 == 0) {
          DAT_02975c24 = 1;
        }
        else {
          iVar2 = FUN_004f8b10(*(undefined4 *)(&DAT_02975a90 + DAT_00827664 * 4),"-AllowCrashDump");
          if ((iVar2 != 0) && (*(int *)(&DAT_02975a90 + DAT_00827664 * 4) != 0)) {
            DAT_00827664 = DAT_00827664 + 1;
          }
        }
      }
    }
    cVar1 = *param_1;
    iVar2 = DAT_00827664;
  } while( true );
}

