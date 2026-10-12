/* Ghidra pseudocode, not original source.
 * ev_bde5c5f75e817edbac891f5cdb42210190c78104eb02ca0378b00d023a3e9188
 * Entry: 0x6f516a; label: FUN_006f516a
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006f516a(uint param_1,LPWSTR param_2,LPWSTR param_3)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  WCHAR WVar4;
  uint uVar5;
  WCHAR *pWVar6;
  undefined4 *puVar7;
  uint uVar8;
  LPWSTR pWVar9;
  BOOL BVar10;
  DWORD DVar11;
  LPWSTR pWVar12;
  int iVar13;
  int iVar14;
  int unaff_EDI;
  bool bVar15;
  longlong lVar16;
  uint local_1c;
  int local_18;
  LPWSTR local_14;
  LPWSTR local_10;
  undefined2 local_c;
  char local_6;
  char local_5;
  
  uVar5 = (uint)param_3;
  local_18 = -2;
  if (param_1 == 0xfffffffe) {
    puVar7 = (undefined4 *)FUN_006ead72();
    *puVar7 = 0;
    puVar7 = (undefined4 *)FUN_006ead5f();
    *puVar7 = 9;
    return -1;
  }
  if (((int)param_1 < 0) || (DAT_029a9b2c <= param_1)) {
    puVar7 = (undefined4 *)FUN_006ead72();
    *puVar7 = 0;
    puVar7 = (undefined4 *)FUN_006ead5f();
    *puVar7 = 9;
    FUN_006e9fc2(0,0,0,0,0);
    return -1;
  }
  iVar14 = (param_1 & 0x1f) * 0x38;
  piVar1 = &DAT_029a9b40 + ((int)param_1 >> 5);
  bVar3 = *(byte *)(*piVar1 + iVar14 + 4);
  if ((bVar3 & 1) == 0) {
    puVar7 = (undefined4 *)FUN_006ead72();
    *puVar7 = 0;
    puVar7 = (undefined4 *)FUN_006ead5f();
    *puVar7 = 9;
    goto LAB_006f5272;
  }
  if (param_3 < 0x80000000) {
    local_14 = (LPWSTR)0x0;
    if ((param_3 == (LPWSTR)0x0) || ((bVar3 & 2) != 0)) {
      return 0;
    }
    if (param_2 != (LPWSTR)0x0) {
      local_6 = (char)(*(char *)(*piVar1 + iVar14 + 0x24) * '\x02') >> 1;
      if (local_6 == '\x01') {
        if ((~(uint)param_3 & 1) == 0) goto LAB_006f5260;
        uVar8 = (uint)param_3 >> 1;
        param_3 = (LPWSTR)0x4;
        if (3 < uVar8) {
          param_3 = (LPWSTR)uVar8;
        }
        local_10 = __malloc_crt((size_t)param_3);
        if (local_10 == (LPWSTR)0x0) {
          puVar7 = (undefined4 *)FUN_006ead5f();
          *puVar7 = 0xc;
          puVar7 = (undefined4 *)FUN_006ead72();
          *puVar7 = 8;
          return -1;
        }
        lVar16 = __lseeki64_nolock(param_1,0x100000000,unaff_EDI);
        iVar13 = *piVar1;
        *(int *)(iVar14 + 0x28 + iVar13) = (int)lVar16;
        *(int *)(iVar14 + 0x2c + iVar13) = (int)((ulonglong)lVar16 >> 0x20);
      }
      else {
        if (local_6 == '\x02') {
          if ((~(uint)param_3 & 1) == 0) goto LAB_006f5260;
          param_3 = (LPWSTR)((uint)param_3 & 0xfffffffe);
        }
        local_10 = param_2;
      }
      pWVar9 = local_10;
      uVar8 = (uint)param_3;
      if ((((*(byte *)(*piVar1 + iVar14 + 4) & 0x48) != 0) &&
          (bVar3 = *(byte *)(*piVar1 + iVar14 + 5), bVar3 != 10)) && (param_3 != (LPWSTR)0x0)) {
        *(byte *)local_10 = bVar3;
        pWVar9 = (LPWSTR)((int)local_10 + 1);
        uVar8 = (int)param_3 - 1;
        local_14 = (LPWSTR)0x1;
        *(undefined1 *)(iVar14 + 5 + *piVar1) = 10;
        if (((local_6 != '\0') && (bVar3 = *(byte *)(iVar14 + 0x25 + *piVar1), bVar3 != 10)) &&
           (uVar8 != 0)) {
          *(byte *)pWVar9 = bVar3;
          pWVar9 = local_10 + 1;
          uVar8 = (int)param_3 - 2;
          local_14 = (LPWSTR)0x2;
          *(undefined1 *)(iVar14 + 0x25 + *piVar1) = 10;
          if (((local_6 == '\x01') && (bVar3 = *(byte *)(iVar14 + 0x26 + *piVar1), bVar3 != 10)) &&
             (uVar8 != 0)) {
            *(byte *)pWVar9 = bVar3;
            pWVar9 = (LPWSTR)((int)local_10 + 3);
            local_14 = (LPWSTR)0x3;
            *(undefined1 *)(iVar14 + 0x26 + *piVar1) = 10;
            uVar8 = (int)param_3 - 3;
          }
        }
      }
      param_3 = (LPWSTR)uVar8;
      BVar10 = ReadFile(*(HANDLE *)(iVar14 + *piVar1),pWVar9,(DWORD)param_3,&local_1c,
                        (LPOVERLAPPED)0x0);
      if (((BVar10 == 0) || ((int)local_1c < 0)) || (param_3 < local_1c)) {
        DVar11 = GetLastError();
        if (DVar11 != 5) {
          if (DVar11 == 0x6d) {
            local_18 = 0;
            goto LAB_006f557f;
          }
          goto LAB_006f5574;
        }
        puVar7 = (undefined4 *)FUN_006ead5f();
        *puVar7 = 9;
        puVar7 = (undefined4 *)FUN_006ead72();
        *puVar7 = 5;
      }
      else {
        local_14 = (LPWSTR)((int)local_14 + local_1c);
        pbVar2 = (byte *)(iVar14 + 4 + *piVar1);
        if ((*pbVar2 & 0x80) == 0) goto LAB_006f557f;
        if (local_6 == '\x02') {
          if ((local_1c == 0) || (*local_10 != L'\n')) {
            *pbVar2 = *pbVar2 & 0xfb;
          }
          else {
            *pbVar2 = *pbVar2 | 4;
          }
          local_14 = (LPWSTR)((int)local_14 + (int)local_10);
          param_3 = local_10;
          pWVar9 = local_10;
          if (local_10 < local_14) {
            do {
              WVar4 = *param_3;
              if (WVar4 == L'\x1a') {
                pbVar2 = (byte *)(iVar14 + 4 + *piVar1);
                if ((*pbVar2 & 0x40) == 0) {
                  *pbVar2 = *pbVar2 | 2;
                }
                else {
                  *pWVar9 = *param_3;
                  pWVar9 = pWVar9 + 1;
                }
                break;
              }
              if (WVar4 == L'\r') {
                if (param_3 < local_14 + -1) {
                  if (param_3[1] == L'\n') {
                    pWVar6 = param_3 + 2;
                    goto LAB_006f5622;
                  }
LAB_006f56b7:
                  param_3 = param_3 + 1;
                  *pWVar9 = L'\r';
                }
                else {
                  pWVar6 = param_3 + 1;
                  BVar10 = ReadFile(*(HANDLE *)(iVar14 + *piVar1),&local_c,2,&local_1c,
                                    (LPOVERLAPPED)0x0);
                  if (((BVar10 == 0) && (DVar11 = GetLastError(), DVar11 != 0)) || (local_1c == 0))
                  goto LAB_006f56b7;
                  if ((*(byte *)(iVar14 + 4 + *piVar1) & 0x48) == 0) {
                    if ((pWVar9 == local_10) && (local_c == 10)) goto LAB_006f5622;
                    __lseeki64_nolock(param_1,0x1ffffffff,unaff_EDI);
                    if (local_c == 10) goto LAB_006f56be;
                    goto LAB_006f56b7;
                  }
                  if (local_c == 10) {
LAB_006f5622:
                    param_3 = pWVar6;
                    *pWVar9 = L'\n';
                  }
                  else {
                    *pWVar9 = L'\r';
                    *(undefined1 *)(iVar14 + 5 + *piVar1) = (undefined1)local_c;
                    *(undefined1 *)(iVar14 + 0x25 + *piVar1) = local_c._1_1_;
                    *(undefined1 *)(iVar14 + 0x26 + *piVar1) = 10;
                    param_3 = pWVar6;
                  }
                }
                pWVar9 = pWVar9 + 1;
                pWVar6 = param_3;
              }
              else {
                *pWVar9 = WVar4;
                pWVar9 = pWVar9 + 1;
                pWVar6 = param_3 + 1;
              }
LAB_006f56be:
              param_3 = pWVar6;
            } while (param_3 < local_14);
          }
          local_14 = (LPWSTR)((int)pWVar9 - (int)local_10);
          goto LAB_006f557f;
        }
        if ((local_1c == 0) || ((byte)*local_10 != 10)) {
          *pbVar2 = *pbVar2 & 0xfb;
        }
        else {
          *pbVar2 = *pbVar2 | 4;
        }
        local_14 = (LPWSTR)((int)local_14 + (int)local_10);
        param_3 = local_10;
        pWVar9 = local_10;
        if (local_10 < local_14) {
          do {
            bVar3 = (byte)*param_3;
            if (bVar3 == 0x1a) {
              pbVar2 = (byte *)(iVar14 + 4 + *piVar1);
              if ((*pbVar2 & 0x40) == 0) {
                *pbVar2 = *pbVar2 | 2;
              }
              else {
                *(byte *)pWVar9 = (byte)*param_3;
                pWVar9 = (LPWSTR)((int)pWVar9 + 1);
              }
              break;
            }
            if (bVar3 == 0xd) {
              if (param_3 < (LPWSTR)((int)local_14 + -1)) {
                if (*(byte *)((int)param_3 + 1) == 10) {
                  pWVar12 = param_3 + 1;
                  goto LAB_006f53ff;
                }
LAB_006f5476:
                param_3 = (LPWSTR)((int)param_3 + 1);
                *(byte *)pWVar9 = 0xd;
              }
              else {
                pWVar12 = (LPWSTR)((int)param_3 + 1);
                BVar10 = ReadFile(*(HANDLE *)(iVar14 + *piVar1),&local_5,1,&local_1c,
                                  (LPOVERLAPPED)0x0);
                if (((BVar10 == 0) && (DVar11 = GetLastError(), DVar11 != 0)) || (local_1c == 0))
                goto LAB_006f5476;
                if ((*(byte *)(iVar14 + 4 + *piVar1) & 0x48) == 0) {
                  if ((pWVar9 == local_10) && (local_5 == '\n')) goto LAB_006f53ff;
                  __lseeki64_nolock(param_1,0x1ffffffff,unaff_EDI);
                  if (local_5 == '\n') goto LAB_006f547a;
                  goto LAB_006f5476;
                }
                if (local_5 == '\n') {
LAB_006f53ff:
                  param_3 = pWVar12;
                  *(byte *)pWVar9 = 10;
                }
                else {
                  *(byte *)pWVar9 = 0xd;
                  *(char *)(iVar14 + 5 + *piVar1) = local_5;
                  param_3 = pWVar12;
                }
              }
              pWVar9 = (LPWSTR)((int)pWVar9 + 1);
              pWVar12 = param_3;
            }
            else {
              *(byte *)pWVar9 = bVar3;
              pWVar9 = (LPWSTR)((int)pWVar9 + 1);
              pWVar12 = (LPWSTR)((int)param_3 + 1);
            }
LAB_006f547a:
            param_3 = pWVar12;
          } while (param_3 < local_14);
        }
        local_14 = (LPWSTR)((int)pWVar9 - (int)local_10);
        if ((local_6 != '\x01') || (local_14 == (LPWSTR)0x0)) goto LAB_006f557f;
        bVar3 = *(byte *)((int)pWVar9 + -1);
        if ((char)bVar3 < '\0') {
          iVar13 = 1;
          pWVar9 = (LPWSTR)((int)pWVar9 + -1);
          while ((((&DAT_00829d78)[bVar3] == '\0' && (iVar13 < 5)) && (local_10 <= pWVar9))) {
            pWVar9 = (LPWSTR)((int)pWVar9 + -1);
            bVar3 = *(byte *)pWVar9;
            iVar13 = iVar13 + 1;
          }
          if ((char)(&DAT_00829d78)[(byte)*pWVar9] == 0) {
            puVar7 = (undefined4 *)FUN_006ead5f();
            *puVar7 = 0x2a;
            goto LAB_006f557b;
          }
          if ((char)(&DAT_00829d78)[(byte)*pWVar9] + 1 == iVar13) {
            pWVar9 = (LPWSTR)((int)pWVar9 + iVar13);
          }
          else if ((*(byte *)(*piVar1 + iVar14 + 4) & 0x48) == 0) {
            __lseeki64_nolock(param_1,CONCAT44(1,-iVar13 >> 0x1f),unaff_EDI);
          }
          else {
            pWVar12 = (LPWSTR)((int)pWVar9 + 1);
            *(byte *)(*piVar1 + iVar14 + 5) = (byte)*pWVar9;
            if (1 < iVar13) {
              *(byte *)(iVar14 + 0x25 + *piVar1) = *(byte *)pWVar12;
              pWVar12 = pWVar9 + 1;
            }
            if (iVar13 == 3) {
              *(byte *)(iVar14 + 0x26 + *piVar1) = (byte)*pWVar12;
              pWVar12 = (LPWSTR)((int)pWVar12 + 1);
            }
            pWVar9 = (LPWSTR)((int)pWVar12 - iVar13);
          }
        }
        iVar13 = (int)pWVar9 - (int)local_10;
        local_14 = (LPWSTR)MultiByteToWideChar(0xfde9,0,(LPCSTR)local_10,iVar13,param_2,uVar5 >> 1);
        if (local_14 != (LPWSTR)0x0) {
          bVar15 = local_14 != (LPWSTR)iVar13;
          local_14 = (LPWSTR)((int)local_14 * 2);
          *(uint *)(iVar14 + 0x30 + *piVar1) = (uint)bVar15;
          goto LAB_006f557f;
        }
        DVar11 = GetLastError();
LAB_006f5574:
        FUN_006ead85(DVar11);
      }
LAB_006f557b:
      local_18 = -1;
LAB_006f557f:
      if (local_10 != param_2) {
        _free(local_10);
      }
      if (local_18 == -2) {
        return (int)local_14;
      }
      return local_18;
    }
  }
LAB_006f5260:
  puVar7 = (undefined4 *)FUN_006ead72();
  *puVar7 = 0;
  puVar7 = (undefined4 *)FUN_006ead5f();
  *puVar7 = 0x16;
LAB_006f5272:
  FUN_006e9fc2(0,0,0,0,0);
  return -1;
}

