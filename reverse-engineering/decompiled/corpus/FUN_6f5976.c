/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f5976; label: FUN_006f5976
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006f5976(char *param_1,char *param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  uchar uVar3;
  undefined4 *puVar4;
  int iVar5;
  errno_t eVar6;
  char *pcVar7;
  uchar *_Str2;
  uchar *_Str1;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_0297cb9c;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  for (pcVar7 = param_2; *pcVar7 == ' '; pcVar7 = pcVar7 + 1) {
  }
  cVar1 = *pcVar7;
  if (cVar1 == 'a') {
    param_2 = (char *)0x109;
LAB_006f59e2:
    local_8 = DAT_0297cb9c | 2;
  }
  else {
    if (cVar1 != 'r') {
      if (cVar1 != 'w') {
        puVar4 = (undefined4 *)FUN_006ead5f();
        *puVar4 = 0x16;
        FUN_006e9fc2(0,0,0,0,0);
        return (undefined4 *)0x0;
      }
      param_2 = (char *)0x301;
      goto LAB_006f59e2;
    }
    local_8 = DAT_0297cb9c | 1;
    param_2 = (char *)0x0;
  }
  bVar2 = true;
  _Str2 = (uchar *)(pcVar7 + 1);
  uVar3 = *_Str2;
  if (uVar3 != '\0') {
    do {
      if (!bVar2) break;
      if ((char)uVar3 < 'T') {
        if (uVar3 == 'S') {
          if (local_c != 0) goto LAB_006f5b1a;
          param_2 = (char *)((uint)param_2 | 0x20);
          local_c = 1;
        }
        else if (uVar3 != ' ') {
          if (uVar3 == '+') {
            if (((uint)param_2 & 2) != 0) goto LAB_006f5b1a;
            param_2 = (char *)((uint)param_2 & 0xfffffffe | 2);
            local_8 = local_8 & 0xfffffffc | 0x80;
          }
          else if (uVar3 == ',') {
            local_14 = 1;
LAB_006f5b1a:
            bVar2 = false;
          }
          else if (uVar3 == 'D') {
            if (((uint)param_2 & 0x40) != 0) goto LAB_006f5b1a;
            param_2 = (char *)((uint)param_2 | 0x40);
          }
          else if (uVar3 == 'N') {
            param_2 = (char *)((uint)param_2 | 0x80);
          }
          else {
            if (uVar3 != 'R') goto LAB_006f5bb5;
            if (local_c != 0) goto LAB_006f5b1a;
            param_2 = (char *)((uint)param_2 | 0x10);
            local_c = 1;
          }
        }
      }
      else if (uVar3 == 'T') {
        if (((uint)param_2 & 0x1000) != 0) goto LAB_006f5b1a;
        param_2 = (char *)((uint)param_2 | 0x1000);
      }
      else if (uVar3 == 'b') {
        if (((uint)param_2 & 0xc000) != 0) goto LAB_006f5b1a;
        param_2 = (char *)((uint)param_2 | 0x8000);
      }
      else if (uVar3 == 'c') {
        if (local_10 != 0) goto LAB_006f5b1a;
        local_8 = local_8 | 0x4000;
        local_10 = 1;
      }
      else if (uVar3 == 'n') {
        if (local_10 != 0) goto LAB_006f5b1a;
        local_8 = local_8 & 0xffffbfff;
        local_10 = 1;
      }
      else {
        if (uVar3 != 't') goto LAB_006f5bb5;
        if (((uint)param_2 & 0xc000) != 0) goto LAB_006f5b1a;
        param_2 = (char *)((uint)param_2 | 0x4000);
      }
      _Str2 = _Str2 + 1;
      uVar3 = *_Str2;
    } while (uVar3 != '\0');
    if (local_14 != 0) {
      for (; *_Str2 == ' '; _Str2 = _Str2 + 1) {
      }
      iVar5 = __mbsnbcmp("ccs=",_Str2,4);
      if (iVar5 != 0) goto LAB_006f5bb5;
      _Str1 = _Str2 + 4;
      iVar5 = __mbsicmp(_Str1,(uchar *)"UTF-8");
      if (iVar5 == 0) {
        _Str2 = _Str2 + 9;
        param_2 = (char *)((uint)param_2 | 0x40000);
      }
      else {
        iVar5 = __mbsicmp(_Str1,(uchar *)"UTF-16LE");
        if (iVar5 == 0) {
          _Str2 = _Str2 + 0xc;
          param_2 = (char *)((uint)param_2 | 0x20000);
        }
        else {
          iVar5 = __mbsicmp(_Str1,(uchar *)"UNICODE");
          if (iVar5 != 0) goto LAB_006f5bb5;
          _Str2 = _Str2 + 0xb;
          param_2 = (char *)((uint)param_2 | 0x10000);
        }
      }
    }
  }
  for (; *_Str2 == ' '; _Str2 = _Str2 + 1) {
  }
  if (*_Str2 == '\0') {
    eVar6 = FID_conflict___sopen_s(&local_14,param_1,(int)param_2,param_3,0x180);
    if (eVar6 != 0) {
      return (undefined4 *)0x0;
    }
    _DAT_0297c198 = _DAT_0297c198 + 1;
    param_4[3] = local_8;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = local_14;
    return param_4;
  }
LAB_006f5bb5:
  puVar4 = (undefined4 *)FUN_006ead5f();
  *puVar4 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return (undefined4 *)0x0;
}

