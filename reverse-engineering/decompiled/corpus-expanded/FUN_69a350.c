/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a350; label: FUN_0069a350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069a350(HANDLE param_1,char *param_2,uint *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  uint *lpBuffer;
  int iVar5;
  BOOL BVar6;
  DWORD unaff_EDI;
  int local_8;
  int local_4;
  
  lpBuffer = param_3;
  cVar1 = param_2[1];
  cVar2 = param_2[3];
  cVar3 = param_2[2];
  cVar4 = *param_2;
  iVar5 = ReadFile(param_1,param_3,8,(LPDWORD)&param_2,(LPOVERLAPPED)0x0);
  while( true ) {
    if ((iVar5 == 0) || (param_2 != (char *)0x8)) {
      return 0;
    }
    if (*lpBuffer == ((((int)cVar2 << 8 | (int)cVar3) << 8 | (int)cVar1) << 8 | (int)cVar4)) {
      SetFilePointerEx(param_1,(LARGE_INTEGER)(ZEXT48(&local_8) << 0x20),(PLARGE_INTEGER)0x1,
                       unaff_EDI);
      lpBuffer[2] = local_4 - *(int *)(local_8 + 0x10);
      return 1;
    }
    BVar6 = SetFilePointerEx(param_1,(LARGE_INTEGER)(ZEXT48(&local_8) << 0x20),(PLARGE_INTEGER)0x1,
                             unaff_EDI);
    if (BVar6 == -1) break;
    unaff_EDI = 0;
    iVar5 = ReadFile(param_1,lpBuffer,8,(LPDWORD)&param_3,(LPOVERLAPPED)0x0);
  }
  return 0;
}

