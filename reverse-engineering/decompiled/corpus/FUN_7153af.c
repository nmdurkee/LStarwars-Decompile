/* Ghidra analysis pseudocode, not original source.
 * ev_184ff99a51593b5727527cffebd3a7fadc537097cd097c26104c250d652dc9a5
 * Entry: 0x7153af; label: FUN_007153af
 */

undefined4 FUN_007153af(undefined4 *param_1,int param_2)

{
  uint _Size;
  uchar *_Str;
  undefined4 *puVar1;
  uchar *puVar2;
  int iVar3;
  uint _Count;
  int *piVar4;
  size_t sVar5;
  char *_Dst;
  errno_t eVar6;
  BOOL BVar7;
  int *piVar8;
  bool bVar9;
  size_t _Size_00;
  uchar *_Src;
  undefined4 local_14;
  
  local_14 = 0;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0xffffffff;
  }
  _Str = (uchar *)*param_1;
  if (((_Str == (uchar *)0x0) || (puVar2 = __mbschr(_Str,0x3d), puVar2 == (uchar *)0x0)) ||
     (_Str == puVar2)) {
LAB_0071543d:
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  bVar9 = puVar2[1] == '\0';
  if (DAT_0297c1d4 == DAT_0297c1d8) {
    DAT_0297c1d4 = (int *)copy_environ();
  }
  if (DAT_0297c1d4 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0297c1dc == (undefined4 *)0x0)) {
      if (bVar9) {
        return 0;
      }
      DAT_0297c1d4 = __malloc_crt(4);
      if (DAT_0297c1d4 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0297c1d4 = 0;
      if (DAT_0297c1dc == (undefined4 *)0x0) {
        DAT_0297c1dc = __malloc_crt(4);
        if (DAT_0297c1dc == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0297c1dc = 0;
      }
    }
    else {
      iVar3 = ___wtomb_environ();
      if (iVar3 != 0) goto LAB_0071543d;
    }
  }
  piVar4 = DAT_0297c1d4;
  if (DAT_0297c1d4 == (int *)0x0) {
    return 0xffffffff;
  }
  _Count = findenv(_Str);
  if (((int)_Count < 0) || (*piVar4 == 0)) {
    if (bVar9) {
      _free(_Str);
      *param_1 = 0;
      return 0;
    }
    if ((int)_Count < 0) {
      _Count = -_Count;
    }
    _Size = _Count + 2;
    if ((int)_Size < (int)_Count) {
      return 0xffffffff;
    }
    if (0x3ffffffe < _Size) {
      return 0xffffffff;
    }
    piVar4 = __recalloc_crt(DAT_0297c1d4,4,_Size);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar4[_Count] = (int)_Str;
    (piVar4 + _Count)[1] = 0;
    *param_1 = 0;
  }
  else {
    piVar8 = piVar4 + _Count;
    _free((void *)*piVar8);
    if (!bVar9) {
      *piVar8 = (int)_Str;
      *param_1 = 0;
      goto LAB_0071554e;
    }
    while (*piVar8 != 0) {
      *piVar8 = piVar8[1];
      _Count = _Count + 1;
      piVar8 = piVar4 + _Count;
    }
    if ((0x3ffffffe < _Count) ||
       (piVar4 = __recalloc_crt(DAT_0297c1d4,_Count,4), piVar4 == (int *)0x0)) goto LAB_0071554e;
  }
  DAT_0297c1d4 = piVar4;
LAB_0071554e:
  if (param_2 != 0) {
    _Size_00 = 1;
    sVar5 = _strlen((char *)_Str);
    _Dst = __calloc_crt(sVar5 + 2,_Size_00);
    if (_Dst != (char *)0x0) {
      _Src = _Str;
      sVar5 = _strlen((char *)_Str);
      eVar6 = _strcpy_s(_Dst,sVar5 + 2,(char *)_Src);
      if (eVar6 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      puVar2[(int)_Dst - (int)_Str] = '\0';
      BVar7 = SetEnvironmentVariableA
                        (_Dst,(LPCSTR)(~-(uint)bVar9 & (uint)(puVar2 + ((int)_Dst - (int)_Str) + 1))
                        );
      if (BVar7 == 0) {
        local_14 = 0xffffffff;
        puVar1 = (undefined4 *)FUN_006ead5f();
        *puVar1 = 0x2a;
      }
      _free(_Dst);
    }
  }
  if (bVar9) {
    _free(_Str);
    *param_1 = 0;
    return local_14;
  }
  return local_14;
}

