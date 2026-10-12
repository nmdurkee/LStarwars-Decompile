/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x707ec2; label: FUN_00707ec2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00707ec2(undefined4 *param_1,LPCSTR param_2,uint param_3,int param_4,byte param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint *in_EAX;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  DWORD DVar6;
  int *piVar7;
  HANDLE pvVar8;
  long lVar9;
  int iVar10;
  byte bVar11;
  int unaff_EDI;
  bool bVar12;
  longlong lVar13;
  _SECURITY_ATTRIBUTES local_38;
  int local_2c;
  uint local_28 [2];
  HANDLE local_20;
  undefined *local_1c;
  DWORD local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  char local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  
  bVar12 = (param_3 & 0x80) == 0;
  local_28[0] = 0;
  local_2c = 0;
  local_6 = 0;
  local_38.nLength = 0xc;
  local_38.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar12) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_38.bInheritHandle = (BOOL)bVar12;
  iVar3 = FUN_00712f89(local_28);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  iVar3 = __get_osplatform(&local_2c);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (((param_3 & 0x8000) == 0) && (((param_3 & 0x74000) != 0 || (local_28[0] != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar4 = param_3 & 3;
  if (uVar4 == 0) {
    local_c = 0x80000000;
  }
  else {
    if (uVar4 == 1) {
      if (((param_3 & 8) == 0) || ((param_3 & 0x70000) == 0)) {
        local_c = 0x40000000;
        goto LAB_00707fab;
      }
    }
    else if (uVar4 != 2) goto LAB_00707f67;
    local_c = 0xc0000000;
  }
LAB_00707fab:
  if (param_4 == 0x10) {
    local_14 = 0;
  }
  else if (param_4 == 0x20) {
    local_14 = 1;
  }
  else if (param_4 == 0x30) {
    local_14 = 2;
  }
  else if (param_4 == 0x40) {
    local_14 = 3;
  }
  else {
    if (param_4 != 0x80) goto LAB_00707f67;
    local_14 = (uint)(local_c == 0x80000000);
  }
  uVar4 = param_3 & 0x700;
  if (uVar4 < 0x401) {
    if ((uVar4 == 0x400) || (uVar4 == 0)) {
      local_18 = 3;
    }
    else if (uVar4 == 0x100) {
      local_18 = 4;
    }
    else {
      if (uVar4 == 0x200) goto LAB_007080b5;
      if (uVar4 != 0x300) goto LAB_00707f67;
      local_18 = 2;
    }
  }
  else {
    if (uVar4 != 0x500) {
      if (uVar4 == 0x600) {
LAB_007080b5:
        local_18 = 5;
        goto LAB_0070805f;
      }
      if (uVar4 != 0x700) {
LAB_00707f67:
        puVar5 = (undefined4 *)FUN_006ead72();
        *puVar5 = 0;
        *in_EAX = 0xffffffff;
        puVar5 = (undefined4 *)FUN_006ead5f();
        *puVar5 = 0x16;
        FUN_006e9fc2(0,0,0,0,0);
        return 0x16;
      }
    }
    local_18 = 1;
  }
LAB_0070805f:
  local_10 = 0x80;
  if (((param_3 & 0x100) != 0) && (-1 < (char)(~(byte)DAT_0297c1b0 & param_5))) {
    local_10 = 1;
  }
  if ((param_3 & 0x40) != 0) {
    local_10 = local_10 | 0x4000000;
    local_c = local_c | 0x10000;
    if (local_2c == 2) {
      local_14 = local_14 | 4;
    }
  }
  if ((param_3 & 0x1000) != 0) {
    local_10 = local_10 | 0x100;
  }
  if ((param_3 & 0x20) == 0) {
    if ((param_3 & 0x10) != 0) {
      local_10 = local_10 | 0x10000000;
    }
  }
  else {
    local_10 = local_10 | 0x8000000;
  }
  uVar4 = __alloc_osfhnd();
  *in_EAX = uVar4;
  if (uVar4 == 0xffffffff) {
    puVar5 = (undefined4 *)FUN_006ead72();
    *puVar5 = 0;
    *in_EAX = 0xffffffff;
    puVar5 = (undefined4 *)FUN_006ead5f();
    *puVar5 = 0x18;
    goto LAB_0070817d;
  }
  *param_1 = 1;
  local_20 = CreateFileA(param_2,local_c,local_14,&local_38,local_18,local_10,(HANDLE)0x0);
  if (local_20 == (HANDLE)0xffffffff) {
    if (((local_c & 0xc0000000) == 0xc0000000) && ((param_3 & 1) != 0)) {
      local_c = local_c & 0x7fffffff;
      local_20 = CreateFileA(param_2,local_c,local_14,&local_38,local_18,local_10,(HANDLE)0x0);
      if (local_20 != (HANDLE)0xffffffff) goto LAB_00708189;
    }
    pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x38);
    *pbVar1 = *pbVar1 & 0xfe;
    DVar6 = GetLastError();
    FUN_006ead85(DVar6);
    goto LAB_0070817d;
  }
LAB_00708189:
  DVar6 = GetFileType(local_20);
  if (DVar6 == 0) {
    pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x38);
    *pbVar1 = *pbVar1 & 0xfe;
    DVar6 = GetLastError();
    FUN_006ead85(DVar6);
    CloseHandle(local_20);
    if (DVar6 == 0) {
      puVar5 = (undefined4 *)FUN_006ead5f();
      *puVar5 = 0xd;
    }
    goto LAB_0070817d;
  }
  if (DVar6 == 2) {
    local_5 = local_5 | 0x40;
  }
  else if (DVar6 == 3) {
    local_5 = local_5 | 8;
  }
  __set_osfhnd(*in_EAX,(intptr_t)local_20);
  bVar11 = local_5 | 1;
  *(byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x38) = bVar11;
  pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x38);
  *pbVar1 = *pbVar1 & 0x80;
  local_7 = local_5 & 0x48;
  if (local_7 == 0) {
    bVar2 = local_5 & 0x80;
    local_5 = bVar11;
    if (bVar2 == 0) goto LAB_00708393;
    if ((param_3 & 2) == 0) goto LAB_007082c3;
    local_1c = (undefined *)__lseek_nolock(*in_EAX,-1,2);
    if (local_1c == (undefined *)0xffffffff) {
      piVar7 = (int *)FUN_006ead72();
      bVar11 = local_5;
      if (*piVar7 == 0x83) goto LAB_007082c3;
    }
    else {
      local_8 = '\0';
      iVar3 = FUN_006f516a(*in_EAX,&local_8,1);
      if ((((iVar3 != 0) || (local_8 != '\x1a')) ||
          (iVar3 = __chsize_nolock(*in_EAX,CONCAT44(unaff_EDI,(int)local_1c >> 0x1f)), iVar3 != -1))
         && (lVar9 = __lseek_nolock(*in_EAX,0,0), bVar11 = local_5, lVar9 != -1)) goto LAB_007082c3;
    }
LAB_00708276:
    __close_nolock(*in_EAX);
    goto LAB_0070817d;
  }
LAB_007082c3:
  local_5 = bVar11;
  if ((local_5 & 0x80) != 0) {
    if ((param_3 & 0x74000) == 0) {
      if ((local_28[0] & 0x74000) == 0) {
        param_3 = param_3 | 0x4000;
      }
      else {
        param_3 = param_3 | local_28[0] & 0x74000;
      }
    }
    uVar4 = param_3 & 0x74000;
    if (uVar4 == 0x4000) {
      local_6 = 0;
    }
    else if ((uVar4 == 0x10000) || (uVar4 == 0x14000)) {
      if ((param_3 & 0x301) == 0x301) goto LAB_00708332;
    }
    else if ((uVar4 == 0x20000) || (uVar4 == 0x24000)) {
LAB_00708332:
      local_6 = 2;
    }
    else if ((uVar4 == 0x40000) || (uVar4 == 0x44000)) {
      local_6 = 1;
    }
    if (((param_3 & 0x70000) != 0) && (local_1c = (undefined *)0x0, (local_5 & 0x40) == 0)) {
      uVar4 = local_c & 0xc0000000;
      if (uVar4 == 0x40000000) {
        if (local_18 == 0) goto LAB_00708393;
        if (2 < local_18) {
          if (local_18 < 5) {
            lVar13 = __lseeki64_nolock(*in_EAX,0x200000000,unaff_EDI);
            if (lVar13 == 0) goto LAB_00708595;
            lVar13 = __lseeki64_nolock(*in_EAX,0,unaff_EDI);
            uVar4 = (uint)lVar13 & (uint)((ulonglong)lVar13 >> 0x20);
            goto LAB_0070852b;
          }
LAB_0070838a:
          if (local_18 != 5) goto LAB_00708393;
        }
LAB_00708595:
        iVar3 = 0;
        if (local_6 == 1) {
          local_1c = &DAT_00bfbbef;
          local_18 = 3;
        }
        else {
          if (local_6 != 2) goto LAB_00708393;
          local_1c = (undefined *)0xfeff;
          local_18 = 2;
        }
        do {
          iVar10 = __write(*in_EAX,(void *)((int)&local_1c + iVar3),local_18 - iVar3);
          if (iVar10 == -1) {
            __close_nolock(*in_EAX);
            puVar5 = (undefined4 *)FUN_006ead5f();
            return *puVar5;
          }
          iVar3 = iVar3 + iVar10;
        } while (iVar3 < (int)local_18);
      }
      else {
        if (uVar4 != 0x80000000) {
          if ((uVar4 == 0xc0000000) && (local_18 != 0)) {
            if (2 < local_18) {
              if (4 < local_18) goto LAB_0070838a;
              lVar13 = __lseeki64_nolock(*in_EAX,0x200000000,unaff_EDI);
              if (lVar13 != 0) {
                lVar13 = __lseeki64_nolock(*in_EAX,0,unaff_EDI);
                if (lVar13 == -1) goto LAB_00708276;
                goto LAB_007084b4;
              }
            }
            goto LAB_00708595;
          }
          goto LAB_00708393;
        }
LAB_007084b4:
        iVar3 = FUN_006f516a(*in_EAX,&local_1c,3);
        if (iVar3 == -1) goto LAB_00708276;
        if (iVar3 == 2) {
LAB_00708539:
          if (((uint)local_1c & 0xffff) == 0xfffe) {
            __close_nolock(*in_EAX);
            puVar5 = (undefined4 *)FUN_006ead5f();
            *puVar5 = 0x16;
            return 0x16;
          }
          if (((uint)local_1c & 0xffff) == 0xfeff) {
            lVar9 = __lseek_nolock(*in_EAX,2,0);
            if (lVar9 == -1) goto LAB_00708276;
            local_6 = 2;
            goto LAB_00708393;
          }
        }
        else if (iVar3 == 3) {
          if (local_1c == &DAT_00bfbbef) {
            local_6 = 1;
            goto LAB_00708393;
          }
          goto LAB_00708539;
        }
        uVar4 = __lseek_nolock(*in_EAX,0,0);
LAB_0070852b:
        if (uVar4 == 0xffffffff) goto LAB_00708276;
      }
    }
  }
LAB_00708393:
  uVar4 = local_c;
  pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x38);
  *pbVar1 = *pbVar1 ^ (*pbVar1 ^ local_6) & 0x7f;
  pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x38);
  *pbVar1 = (char)(param_3 >> 0x10) << 7 | *pbVar1 & 0x7f;
  if ((local_7 == 0) && ((param_3 & 8) != 0)) {
    pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x38);
    *pbVar1 = *pbVar1 | 0x20;
  }
  if (((local_c & 0xc0000000) == 0xc0000000) && ((param_3 & 1) != 0)) {
    CloseHandle(local_20);
    pvVar8 = CreateFileA(param_2,uVar4 & 0x7fffffff,local_14,&local_38,3,local_10,(HANDLE)0x0);
    if (pvVar8 == (HANDLE)0xffffffff) {
      DVar6 = GetLastError();
      FUN_006ead85(DVar6);
      pbVar1 = (byte *)((&DAT_029a9b40)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x38);
      *pbVar1 = *pbVar1 & 0xfe;
      __free_osfhnd(*in_EAX);
LAB_0070817d:
      puVar5 = (undefined4 *)FUN_006ead5f();
      return *puVar5;
    }
    *(HANDLE *)((*in_EAX & 0x1f) * 0x38 + (&DAT_029a9b40)[(int)*in_EAX >> 5]) = pvVar8;
  }
  return 0;
}

