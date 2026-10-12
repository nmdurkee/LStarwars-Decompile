/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x5439d0; label: FUN_005439d0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005439d0(int param_1,void *param_2,size_t param_3)

{
  char cVar1;
  char *pcVar2;
  FILE *_File;
  uint uVar3;
  int iVar4;
  size_t _Size;
  void *_Str;
  uint uVar5;
  char *pcVar6;
  size_t _Count;
  FILE *_File_00;
  void *local_2470;
  undefined4 local_246c;
  undefined4 local_2468;
  undefined4 local_2464;
  undefined4 local_2460;
  undefined4 local_245c;
  undefined4 local_2458;
  undefined1 local_2454 [16];
  WCHAR local_2444 [1024];
  WCHAR local_1c44 [1024];
  undefined2 local_1444;
  WCHAR local_c44 [1024];
  CHAR local_444 [63];
  char cStack_405;
  CHAR local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2470;
  local_2470 = param_2;
  if ((&DAT_02989540)[param_1] == 0) {
    FUN_00543670(param_1);
  }
  pcVar2 = (char *)FUN_005436e0(param_1);
  _File = _fopen(pcVar2,"wb");
  _memset(&local_246c,0,0x2028);
  local_246c = 0x52474d48;
  local_2468 = 1;
  local_2464 = 0x2028;
  local_2460 = 0;
  local_245c = 0;
  local_2458 = FUN_006dfda0();
  FUN_004ef660(local_2454,&DAT_02975c28,0x10);
  local_1444 = 0;
  GetDateFormatA(0x400,0,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_404,0x40);
  pcVar2 = &cStack_405;
  do {
    pcVar6 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (*pcVar6 != '\0');
  pcVar2[0] = ' ';
  pcVar2[1] = '\0';
  GetTimeFormatA(0x400,0,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_444,0x40);
  pcVar2 = local_444;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = (int)pcVar2 - (int)local_444;
  pcVar2 = &cStack_405;
  do {
    pcVar6 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (*pcVar6 != '\0');
  pcVar6 = local_444;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  MultiByteToWideChar(0,0,local_404,0x400,local_c44,0x400);
  MultiByteToWideChar(0,0,PTR_s_TitleNotSet_00827614,0x400,local_2444,0x400);
  _sprintf(local_404,"Save Slot %d",param_1);
  MultiByteToWideChar(0,0,local_404,0x400,local_1c44,0x400);
  _fwrite(&local_246c,0x2028,1,_File);
  iVar4 = FUN_006dfdb0();
  if (iVar4 != 0) {
    _Count = 1;
    _File_00 = _File;
    _Size = FUN_006dfda0();
    _Str = (void *)FUN_006dfdb0();
    _fwrite(_Str,_Size,_Count,_File_00);
  }
  _fwrite(local_2470,param_3,1,_File);
  _fwrite(&stack0x00000010,4,1,_File);
  _fclose(_File);
  __security_check_cookie(local_4 ^ (uint)&local_2470);
  return;
}

