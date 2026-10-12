/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff7a0; label: FUN_004ff7a0
 */

int FUN_004ff7a0(int param_1,int *param_2)

{
  LPWIN32_FIND_DATAA lpFindFileData;
  char cVar1;
  int iVar2;
  char *pcVar3;
  BOOL BVar4;
  int *piVar5;
  int iVar6;
  _SYSTEMTIME local_10;
  
  iVar6 = param_1 * 0x140;
  lpFindFileData = (LPWIN32_FIND_DATAA)(&DAT_0091f1b8 + iVar6);
  iVar2 = 0x100;
  if ((*(uint *)(&DAT_0091f1b8 + iVar6) & 1) != 0) {
    iVar2 = 0x180;
  }
  if ((*(uint *)(&DAT_0091f1b8 + iVar6) & 0x10) != 0) {
    iVar2 = iVar2 + 0x2000;
  }
  *param_2 = iVar2;
  piVar5 = param_2 + 0x10;
  param_2[2] = *(int *)(&DAT_0091f1d8 + iVar6);
  pcVar3 = &DAT_0091f1e4 + iVar6;
  param_2[9] = 0;
  iVar2 = (int)piVar5 - (int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[iVar2] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FileTimeToSystemTime((FILETIME *)(&DAT_0091f1bc + iVar6),&local_10);
  *(undefined1 *)((int)param_2 + 0xd) = (undefined1)local_10.wSecond;
  *(undefined1 *)((int)param_2 + 0xe) = (undefined1)local_10.wMinute;
  *(undefined1 *)(param_2 + 4) = (undefined1)local_10.wDay;
  *(undefined1 *)((int)param_2 + 0xf) = (undefined1)local_10.wHour;
  *(undefined1 *)((int)param_2 + 0x11) = (undefined1)local_10.wMonth;
  *(undefined1 *)((int)param_2 + 0x12) = (undefined1)local_10.wYear;
  *(undefined1 *)((int)param_2 + 0x13) = 0;
  FileTimeToSystemTime((FILETIME *)(&DAT_0091f1cc + iVar6),&local_10);
  *(undefined1 *)((int)param_2 + 0x1d) = (undefined1)local_10.wSecond;
  *(undefined1 *)((int)param_2 + 0x1e) = (undefined1)local_10.wMinute;
  *(undefined1 *)(param_2 + 8) = (undefined1)local_10.wDay;
  *(undefined1 *)((int)param_2 + 0x1f) = (undefined1)local_10.wHour;
  *(undefined1 *)((int)param_2 + 0x21) = (undefined1)local_10.wMonth;
  *(undefined1 *)((int)param_2 + 0x22) = (undefined1)local_10.wYear;
  *(undefined1 *)((int)param_2 + 0x23) = 0;
  FileTimeToSystemTime((FILETIME *)(&DAT_0091f1c4 + iVar6),&local_10);
  *(undefined1 *)((int)param_2 + 0x15) = (undefined1)local_10.wSecond;
  *(undefined1 *)((int)param_2 + 0x16) = (undefined1)local_10.wMinute;
  *(undefined1 *)((int)param_2 + 0x17) = (undefined1)local_10.wHour;
  *(undefined1 *)(param_2 + 6) = (undefined1)local_10.wDay;
  *(undefined1 *)((int)param_2 + 0x19) = (undefined1)local_10.wMonth;
  *(undefined1 *)((int)param_2 + 0x1a) = (undefined1)local_10.wYear;
  *(undefined1 *)((int)param_2 + 0x1b) = 0;
  if (lpFindFileData->dwFileAttributes == 0xffffffff) {
    return 0;
  }
  BVar4 = FindNextFileA(*(HANDLE *)(&DAT_0091ef40 + param_1 * 4),lpFindFileData);
  if (BVar4 != 1) {
    lpFindFileData->dwFileAttributes = 0xffffffff;
  }
  do {
    iVar2 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar2 != '\0');
  return (int)piVar5 - ((int)param_2 + 0x41);
}

