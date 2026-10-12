/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff970; label: FUN_004ff970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004ff970(LPCSTR param_1,uint *param_2)

{
  _SYSTEMTIME local_34;
  uint local_24;
  FILETIME local_20 [2];
  FILETIME local_10;
  uint local_4;
  
  GetFileAttributesExA(param_1,GetFileExInfoStandard,&local_24);
  *param_2 = ((local_24 & 0x4000 | 0x400) >> 9 | local_24 & 0x10) >> 1 | ~(local_24 * 2) & 2;
  *(undefined1 *)(param_2 + 6) = 0;
  param_2[1] = local_4;
  FileTimeToSystemTime(local_20,&local_34);
  *(WORD *)((int)param_2 + 0xe) = local_34.wYear;
  *(undefined1 *)(param_2 + 3) = (undefined1)local_34.wMonth;
  *(undefined1 *)((int)param_2 + 10) = (undefined1)local_34.wHour;
  *(undefined1 *)((int)param_2 + 0xb) = (undefined1)local_34.wDay;
  *(undefined1 *)((int)param_2 + 9) = (undefined1)local_34.wMinute;
  *(undefined1 *)(param_2 + 2) = (undefined1)local_34.wSecond;
  FileTimeToSystemTime(&local_10,&local_34);
  *(WORD *)((int)param_2 + 0x16) = local_34.wYear;
  *(undefined1 *)(param_2 + 5) = (undefined1)local_34.wMonth;
  *(undefined1 *)((int)param_2 + 0x13) = (undefined1)local_34.wDay;
  *(undefined1 *)((int)param_2 + 0x12) = (undefined1)local_34.wHour;
  *(undefined1 *)((int)param_2 + 0x11) = (undefined1)local_34.wMinute;
  *(undefined1 *)(param_2 + 4) = (undefined1)local_34.wSecond;
  return 1;
}

