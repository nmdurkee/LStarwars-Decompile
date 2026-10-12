/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70ac50; label: ___init_ctype
 */

/* Library Function - Single Match
    ___init_ctype
   
   Library: Visual Studio 2005 Release */

int __cdecl ___init_ctype(threadlocinfo *_LocInfo)

{
  BYTE *pBVar1;
  byte bVar2;
  LONG *lpAddend;
  undefined2 *_Dst;
  int iVar3;
  BOOL BVar4;
  BYTE *pBVar5;
  LONG LVar6;
  BYTE *pBVar7;
  uint uVar8;
  localeinfo_struct local_4c;
  wchar_t *local_44;
  LPWORD local_40;
  undefined2 *local_3c;
  int *local_38;
  wchar_t *local_34;
  undefined4 *local_30;
  void *local_2c;
  undefined2 *local_28;
  LPCSTR local_24;
  BYTE *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_30 = (undefined4 *)0x0;
  local_28 = (undefined2 *)0x0;
  local_20 = (BYTE *)0x0;
  local_2c = (void *)0x0;
  local_24 = (LPCSTR)0x0;
  local_4c.locinfo = _LocInfo;
  local_4c.mbcinfo = (pthreadmbcinfo)0x0;
  if (_LocInfo->lc_category[0].wlocale == (wchar_t *)0x0) {
    lpAddend = (LONG *)_LocInfo[1].lc_collate_cp;
    if (lpAddend != (LONG *)0x0) {
      InterlockedDecrement(lpAddend);
    }
    _LocInfo[1].lc_collate_cp = 0;
    _LocInfo[1].lc_time_cp = 0;
    _LocInfo[1].lc_category[0].locale = " ";
    _LocInfo[1].lc_category[0].wlocale = (wchar_t *)&DAT_007817a8;
    _LocInfo[1].lc_category[0].refcount = (int *)&DAT_00781928;
    _LocInfo->locale_name[3] = (wchar_t *)0x1;
    goto LAB_0070afd6;
  }
  if ((_LocInfo->lc_codepage == 0) &&
     (iVar3 = ___getlocaleinfo(&local_4c,0,
                               (LPCWSTR)(uint)*(ushort *)&_LocInfo->lc_category[2].locale,0x1004,
                               &_LocInfo->lc_codepage), iVar3 != 0)) {
LAB_0070af69:
    _free(local_30);
    _free(local_28);
    _free(local_20);
    _free(local_2c);
  }
  else {
    local_30 = __malloc_crt(4);
    local_28 = __calloc_crt(0x180,2);
    local_20 = __calloc_crt(0x180,1);
    local_2c = __calloc_crt(0x180,1);
    local_24 = __calloc_crt(0x101,1);
    if ((local_30 == (undefined4 *)0x0) ||
       ((((local_28 == (undefined2 *)0x0 || (local_24 == (LPCSTR)0x0)) || (local_20 == (BYTE *)0x0))
        || (local_2c == (void *)0x0)))) goto LAB_0070af69;
    *local_30 = 0;
    iVar3 = 0;
    do {
      local_24[iVar3] = (CHAR)iVar3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x100);
    BVar4 = GetCPInfo(_LocInfo->lc_codepage,&local_1c);
    if ((BVar4 == 0) || (5 < local_1c.MaxCharSize)) goto LAB_0070af69;
    local_34 = (wchar_t *)(local_1c.MaxCharSize & 0xffff);
    if (((wchar_t *)0x1 < local_34) && (local_1c.LeadByte[0] != '\0')) {
      pBVar5 = local_1c.LeadByte + 1;
      do {
        bVar2 = *pBVar5;
        if (bVar2 == 0) break;
        for (uVar8 = (uint)pBVar5[-1]; (int)uVar8 <= (int)(uint)bVar2; uVar8 = uVar8 + 1) {
          local_24[uVar8] = ' ';
          bVar2 = *pBVar5;
        }
        pBVar7 = pBVar5 + 1;
        pBVar5 = pBVar5 + 2;
      } while (*pBVar7 != 0);
    }
    local_40 = local_28 + 0x80;
    BVar4 = ___crtGetStringTypeA((_locale_t)0x0,1,local_24,0x100,local_40,_LocInfo->lc_codepage,0);
    if (((BVar4 == 0) ||
        (iVar3 = ___crtLCMapStringA((_locale_t)0x0,_LocInfo->lc_category[0].wlocale,0x100,
                                    local_24 + 1,0xff,(LPSTR)(local_20 + 0x81),0xff,
                                    _LocInfo->lc_codepage,0), iVar3 == 0)) ||
       (iVar3 = ___crtLCMapStringA((_locale_t)0x0,_LocInfo->lc_category[0].wlocale,0x200,
                                   local_24 + 1,0xff,(LPSTR)((int)local_2c + 0x81),0xff,
                                   _LocInfo->lc_codepage,0), pBVar5 = local_20, _Dst = local_28,
       iVar3 == 0)) goto LAB_0070af69;
    local_3c = local_28 + 0x7f;
    *local_3c = 0;
    local_44 = (wchar_t *)(local_20 + 0x80);
    local_20[0x7f] = 0;
    *(undefined1 *)((int)local_2c + 0x7f) = 0;
    *(byte *)local_44 = 0;
    local_38 = (int *)((int)local_2c + 0x80);
    *(undefined1 *)local_38 = 0;
    if ((1 < (int)local_34) && (local_1c.LeadByte[0] != '\0')) {
      pBVar7 = local_1c.LeadByte + 1;
      do {
        local_20 = pBVar7;
        if (*pBVar7 == 0) break;
        uVar8 = (uint)pBVar7[-1];
        if (uVar8 <= *pBVar7) {
          local_28 = _Dst + uVar8 + 0x80;
          do {
            *local_28 = 0x8000;
            uVar8 = uVar8 + 1;
            local_28 = local_28 + 1;
          } while ((int)uVar8 <= (int)(uint)*pBVar7);
        }
        local_20 = pBVar7 + 2;
        pBVar1 = pBVar7 + 1;
        pBVar7 = local_20;
      } while (*pBVar1 != 0);
    }
    _memcpy(_Dst,_Dst + 0x100,0xfe);
    _memcpy(pBVar5,pBVar5 + 0x100,0x7f);
    _memcpy(local_2c,(void *)((int)local_2c + 0x100),0x7f);
    if (((LONG *)_LocInfo[1].lc_collate_cp != (LONG *)0x0) &&
       (LVar6 = InterlockedDecrement((LONG *)_LocInfo[1].lc_collate_cp), LVar6 == 0)) {
      _free((void *)(_LocInfo[1].lc_time_cp - 0xfe));
      _free(_LocInfo[1].lc_category[0].wlocale + -0x40);
      _free(_LocInfo[1].lc_category[0].refcount + -0x20);
      _free((void *)_LocInfo[1].lc_collate_cp);
    }
    *local_30 = 1;
    _LocInfo[1].lc_collate_cp = (uint)local_30;
    _LocInfo[1].lc_category[0].locale = (char *)local_40;
    _LocInfo[1].lc_time_cp = (uint)local_3c;
    _LocInfo[1].lc_category[0].wlocale = local_44;
    _LocInfo[1].lc_category[0].refcount = local_38;
    _LocInfo->locale_name[3] = local_34;
  }
  _free(local_24);
LAB_0070afd6:
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

