/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a460; label: FUN_0069a460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069a460(int param_1,LPCSTR param_2,undefined4 *param_3)

{
  short *lpBuffer;
  LARGE_INTEGER liDistanceToMove;
  LPCSTR lpFileName;
  int iVar1;
  HANDLE pvVar2;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  BOOL BVar3;
  int iVar4;
  int in_ECX;
  DWORD unaff_EDI;
  undefined1 local_20 [8];
  undefined1 auStack_18 [4];
  uint local_14;
  undefined4 local_10;
  int local_c [2];
  int iStack_4;
  
  lpFileName = param_2;
  iVar4 = param_1;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (param_1 == 0) {
    lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)FUN_0069a180(param_2);
    pvVar2 = CreateFileA(lpFileName,0x80000000,1,lpSecurityAttributes,3,0x8000001,
                         lpSecurityAttributes);
    *(HANDLE *)(in_ECX + 8) = pvVar2;
  }
  else {
    iVar1 = FUN_004fa740(param_1,param_2,(undefined4 *)(in_ECX + 0x10),&param_1);
    if (iVar1 != 0) {
      pvVar2 = CreateFileA(*(LPCSTR *)(iVar4 + 0xb8),0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                           (HANDLE)0x0);
      *(HANDLE *)(in_ECX + 8) = pvVar2;
      if (pvVar2 == (HANDLE)0xffffffff) {
        FUN_0069a180(*(undefined4 *)(iVar4 + 0xb8));
      }
      else {
        liDistanceToMove.s.HighPart = (LONG)local_20;
        liDistanceToMove.s.LowPart = *(undefined4 *)(in_ECX + 0x14);
        SetFilePointerEx(pvVar2,liDistanceToMove,(PLARGE_INTEGER)0x0,unaff_EDI);
      }
    }
  }
  if (*(HANDLE *)(in_ECX + 8) != (HANDLE)0xffffffff) {
    BVar3 = ReadFile(*(HANDLE *)(in_ECX + 8),local_c,0xc,(LPDWORD)&param_2,(LPOVERLAPPED)0x0);
    if (((((BVar3 != 0) && (param_2 == (LPCSTR)0xc)) && (local_c[0] == 0x46464952)) &&
        ((iStack_4 == 0x45564157 &&
         (iVar4 = FUN_0069a350(*(undefined4 *)(in_ECX + 8),&DAT_0076efd8,auStack_18), iVar4 != 0))))
       && (0xf < local_14)) {
      lpBuffer = (short *)(in_ECX + 0x18);
      lpBuffer[0] = 0;
      lpBuffer[1] = 0;
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      *(undefined4 *)(in_ECX + 0x20) = 0;
      *(undefined4 *)(in_ECX + 0x24) = 0;
      *(undefined2 *)(in_ECX + 0x28) = 0;
      BVar3 = ReadFile(*(HANDLE *)(in_ECX + 8),lpBuffer,0x10,(LPDWORD)&param_2,(LPOVERLAPPED)0x0);
      if ((BVar3 != 0) && (param_2 == (LPCSTR)0x10)) {
        *(undefined2 *)(in_ECX + 0x28) = 0;
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)lpBuffer;
          param_3[1] = *(undefined4 *)(in_ECX + 0x1c);
          param_3[2] = *(undefined4 *)(in_ECX + 0x20);
          param_3[3] = *(undefined4 *)(in_ECX + 0x24);
          *(undefined2 *)(param_3 + 4) = *(undefined2 *)(in_ECX + 0x28);
        }
        if (*lpBuffer == 1) {
          FUN_0069a410(*(undefined4 *)(in_ECX + 8),auStack_18);
          iVar4 = FUN_0069a350(*(undefined4 *)(in_ECX + 8),&DAT_0076efd0,auStack_18);
          if (iVar4 != 0) {
            *(undefined4 *)(in_ECX + 0x38) = local_10;
            *(uint *)(in_ECX + 0x3c) = local_14;
            if (local_14 != 0) {
              *(undefined4 *)(in_ECX + 0x2c) = 0;
              *(undefined4 *)(in_ECX + 0x34) = 0;
              *(int *)(in_ECX + 0x30) = (int)local_14 / (int)(uint)*(ushort *)(in_ECX + 0x24) + -1;
              return 0;
            }
          }
        }
      }
    }
    CloseHandle(*(HANDLE *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
    return 0x80004005;
  }
  FUN_0069a180(lpFileName);
  return 0x80004005;
}

