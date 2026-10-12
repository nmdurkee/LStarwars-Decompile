/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f5e9b; label: __write_nolock
 */

/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    __write_nolock
   
   Library: Visual Studio 2005 Release */

int __cdecl __write_nolock(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  WCHAR *pWVar1;
  char cVar2;
  wchar_t *pwVar3;
  WCHAR WVar4;
  wchar_t wVar5;
  undefined4 *puVar6;
  int iVar7;
  _ptiddata p_Var8;
  BOOL BVar9;
  DWORD nNumberOfBytesToWrite;
  int iVar10;
  uint uVar11;
  WCHAR *pWVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 uVar15;
  int unaff_EDI;
  int *piVar16;
  UINT local_598;
  uint local_594;
  WCHAR *local_590;
  int *local_58c;
  char *local_588;
  int local_584;
  WCHAR *local_580;
  char *local_57c;
  WCHAR *local_578;
  char local_571;
  DWORD local_570;
  WCHAR *local_56c;
  WCHAR local_568 [38];
  undefined1 local_51c [264];
  CHAR local_414 [688];
  WCHAR local_164 [170];
  CHAR local_10 [8];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)local_51c;
  local_580 = _Buf;
  local_57c = (char *)0x0;
  local_584 = 0;
  if (_MaxCharCount == 0) goto LAB_006f644b;
  if (_Buf == (void *)0x0) {
    puVar6 = (undefined4 *)FUN_006ead72();
    *puVar6 = 0;
    puVar6 = (undefined4 *)FUN_006ead5f();
    *puVar6 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    goto LAB_006f644b;
  }
  iVar10 = (_FileHandle & 0x1fU) * 0x38;
  piVar16 = &DAT_029a9b40 + (_FileHandle >> 5);
  local_571 = (char)(*(char *)(*piVar16 + iVar10 + 0x24) * '\x02') >> 1;
  local_58c = piVar16;
  if (((local_571 == '\x02') || (local_571 == '\x01')) && ((~_MaxCharCount & 1) == 0)) {
    puVar6 = (undefined4 *)FUN_006ead72();
    *puVar6 = 0;
    puVar6 = (undefined4 *)FUN_006ead5f();
    *puVar6 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    goto LAB_006f644b;
  }
  if ((*(byte *)(*piVar16 + iVar10 + 4) & 0x20) != 0) {
    __lseeki64_nolock(_FileHandle,0x200000000,unaff_EDI);
  }
  iVar7 = __isatty(_FileHandle);
  if ((iVar7 == 0) || ((*(byte *)(iVar10 + 4 + *piVar16) & 0x80) == 0)) {
LAB_006f6186:
    if ((*(byte *)((undefined4 *)(*piVar16 + iVar10) + 1) & 0x80) == 0) {
      BVar9 = WriteFile(*(HANDLE *)(*piVar16 + iVar10),local_580,_MaxCharCount,(LPDWORD)&local_588,
                        (LPOVERLAPPED)0x0);
      if (BVar9 == 0) {
LAB_006f63e0:
        local_570 = GetLastError();
      }
      else {
        local_570 = 0;
        local_57c = local_588;
      }
LAB_006f63e9:
      piVar16 = local_58c;
      if (local_57c != (char *)0x0) goto LAB_006f644b;
      goto LAB_006f63f3;
    }
    local_570 = 0;
    if (local_571 == '\0') {
      local_56c = local_580;
      if (_MaxCharCount == 0) goto LAB_006f641a;
      do {
        local_578 = (WCHAR *)0x0;
        uVar11 = (int)local_56c - (int)local_580;
        pWVar12 = local_568;
        do {
          if (_MaxCharCount <= uVar11) break;
          pWVar1 = (WCHAR *)((int)local_56c + 1);
          WVar4 = *local_56c;
          uVar11 = uVar11 + 1;
          if ((char)WVar4 == '\n') {
            local_584 = local_584 + 1;
            *(char *)pWVar12 = '\r';
            pWVar12 = (WCHAR *)((int)pWVar12 + 1);
            local_578 = (WCHAR *)((int)local_578 + 1);
          }
          *(char *)pWVar12 = (char)WVar4;
          pWVar12 = (WCHAR *)((int)pWVar12 + 1);
          local_578 = (WCHAR *)((int)local_578 + 1);
          local_56c = pWVar1;
        } while (local_578 < (WCHAR *)0x400);
        BVar9 = WriteFile(*(HANDLE *)(iVar10 + *piVar16),local_568,(int)pWVar12 - (int)local_568,
                          (LPDWORD)&local_588,(LPOVERLAPPED)0x0);
        if (BVar9 == 0) goto LAB_006f63e0;
        local_57c = local_57c + (int)local_588;
      } while (((int)pWVar12 - (int)local_568 <= (int)local_588) &&
              ((uint)((int)local_56c - (int)local_580) < _MaxCharCount));
      goto LAB_006f63e9;
    }
    if (local_571 == '\x02') {
      local_56c = local_580;
      if (_MaxCharCount != 0) {
        do {
          uVar13 = 0;
          uVar11 = (int)local_56c - (int)local_580;
          pWVar12 = local_568;
          do {
            if (_MaxCharCount <= uVar11) break;
            pWVar1 = local_56c + 1;
            WVar4 = *local_56c;
            uVar11 = uVar11 + 2;
            if (WVar4 == L'\n') {
              local_584 = local_584 + 2;
              *pWVar12 = L'\r';
              pWVar12 = pWVar12 + 1;
              uVar13 = uVar13 + 2;
            }
            *pWVar12 = WVar4;
            pWVar12 = pWVar12 + 1;
            uVar13 = uVar13 + 2;
            piVar16 = local_58c;
            local_56c = pWVar1;
          } while (uVar13 < 0x3ff);
          BVar9 = WriteFile(*(HANDLE *)(iVar10 + *piVar16),local_568,(int)pWVar12 - (int)local_568,
                            (LPDWORD)&local_588,(LPOVERLAPPED)0x0);
          if (BVar9 == 0) goto LAB_006f63e0;
          local_57c = local_57c + (int)local_588;
        } while (((int)pWVar12 - (int)local_568 <= (int)local_588) &&
                ((uint)((int)local_56c - (int)local_580) < _MaxCharCount));
        goto LAB_006f63e9;
      }
    }
    else {
      local_578 = local_580;
      if (_MaxCharCount != 0) {
        do {
          local_56c = (WCHAR *)0x0;
          uVar11 = (int)local_578 - (int)local_580;
          pWVar12 = local_164;
          do {
            if (_MaxCharCount <= uVar11) break;
            WVar4 = *local_578;
            local_578 = local_578 + 1;
            uVar11 = uVar11 + 2;
            if (WVar4 == L'\n') {
              *pWVar12 = L'\r';
              pWVar12 = pWVar12 + 1;
              local_56c = local_56c + 1;
            }
            local_56c = local_56c + 1;
            *pWVar12 = WVar4;
            pWVar12 = pWVar12 + 1;
          } while (local_56c < (WCHAR *)0x152);
          pcVar14 = (char *)0x0;
          iVar7 = WideCharToMultiByte(0xfde9,0,local_164,((int)pWVar12 - (int)local_164) / 2,
                                      local_414,0x2ab,(LPCSTR)0x0,(LPBOOL)0x0);
          if (iVar7 == 0) goto LAB_006f63e0;
          do {
            BVar9 = WriteFile(*(HANDLE *)(iVar10 + *local_58c),local_414 + (int)pcVar14,
                              iVar7 - (int)pcVar14,(LPDWORD)&local_588,(LPOVERLAPPED)0x0);
            if (BVar9 == 0) {
              local_570 = GetLastError();
              break;
            }
            pcVar14 = pcVar14 + (int)local_588;
          } while ((int)pcVar14 < iVar7);
        } while ((iVar7 <= (int)pcVar14) &&
                (local_57c = (char *)((int)local_578 - (int)local_580), local_57c < _MaxCharCount));
        goto LAB_006f63e9;
      }
    }
LAB_006f641a:
    uVar15 = 0;
    if (((*(byte *)(iVar10 + 4 + *piVar16) & 0x40) != 0) && ((char)*local_580 == '\x1a'))
    goto LAB_006f644b;
    puVar6 = (undefined4 *)FUN_006ead5f();
    *puVar6 = 0x1c;
  }
  else {
    p_Var8 = __getptd();
    pwVar3 = p_Var8->ptlocinfo->lc_category[0].wlocale;
    BVar9 = GetConsoleMode(*(HANDLE *)(iVar10 + *piVar16),&local_598);
    if ((BVar9 == 0) || ((pwVar3 == (wchar_t *)0x0 && (local_571 == '\0')))) goto LAB_006f6186;
    local_598 = GetConsoleCP();
    local_56c = (WCHAR *)0x0;
    local_590 = local_580;
    if (_MaxCharCount != 0) {
      local_578 = (WCHAR *)0x0;
      do {
        pWVar12 = local_590;
        if (local_571 == '\0') {
          cVar2 = (char)*local_590;
          local_594 = (uint)(cVar2 == '\n');
          iVar7 = _isleadbyte(CONCAT22(cVar2 >> 7,(short)cVar2));
          if (iVar7 == 0) {
            iVar7 = _mbtowc((wchar_t *)&local_570,(char *)pWVar12,1);
            if (iVar7 == -1) break;
          }
          else {
            if (((char *)((int)local_580 + (_MaxCharCount - (int)pWVar12)) < (char *)0x2) ||
               (iVar7 = _mbtowc((wchar_t *)&local_570,(char *)pWVar12,2), iVar7 == -1)) break;
            pWVar12 = (WCHAR *)((int)pWVar12 + 1);
            local_578 = (WCHAR *)((int)local_578 + 1);
          }
          local_590 = (WCHAR *)((int)pWVar12 + 1);
          local_578 = (WCHAR *)((int)local_578 + 1);
          nNumberOfBytesToWrite =
               WideCharToMultiByte(local_598,0,(LPCWSTR)&local_570,1,local_10,5,(LPCSTR)0x0,
                                   (LPBOOL)0x0);
          if (nNumberOfBytesToWrite == 0) break;
          BVar9 = WriteFile(*(HANDLE *)(iVar10 + *piVar16),local_10,nNumberOfBytesToWrite,
                            (LPDWORD)&local_56c,(LPOVERLAPPED)0x0);
          if (BVar9 == 0) goto LAB_006f63e0;
          local_57c = local_57c + (int)local_56c;
          if ((int)local_56c < (int)nNumberOfBytesToWrite) break;
          if (local_594 != 0) {
            local_10[0] = '\r';
            BVar9 = WriteFile(*(HANDLE *)(iVar10 + *piVar16),local_10,1,(LPDWORD)&local_56c,
                              (LPOVERLAPPED)0x0);
            if (BVar9 == 0) goto LAB_006f63e0;
            if ((int)local_56c < 1) break;
            local_584 = local_584 + 1;
            local_57c = local_57c + 1;
          }
        }
        else {
          if ((local_571 == '\x01') || (local_571 == '\x02')) {
            local_570 = (DWORD)(ushort)*local_590;
            local_594 = (uint)(*local_590 == L'\n');
            local_590 = local_590 + 1;
            local_578 = local_578 + 1;
          }
          if ((local_571 == '\x01') || (local_571 == '\x02')) {
            wVar5 = __putwch_nolock((wchar_t)local_570);
            if (wVar5 != (wchar_t)local_570) goto LAB_006f63e0;
            local_57c = local_57c + 1;
            if (local_594 != 0) {
              local_570 = 0xd;
              wVar5 = __putwch_nolock(L'\r');
              if (wVar5 != (wchar_t)local_570) goto LAB_006f63e0;
              local_57c = local_57c + 1;
              local_584 = local_584 + 1;
            }
          }
        }
      } while (local_578 < _MaxCharCount);
      goto LAB_006f63e9;
    }
LAB_006f63f3:
    if (local_570 == 0) goto LAB_006f641a;
    uVar15 = 5;
    if (local_570 != 5) {
      FUN_006ead85((short)local_570);
      goto LAB_006f644b;
    }
    puVar6 = (undefined4 *)FUN_006ead5f();
    *puVar6 = 9;
  }
  puVar6 = (undefined4 *)FUN_006ead72();
  *puVar6 = uVar15;
LAB_006f644b:
  iVar10 = __security_check_cookie(local_8 ^ (uint)local_51c);
  return iVar10;
}

