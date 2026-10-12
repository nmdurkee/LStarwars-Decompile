/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74ee50; label: FUN_0074ee50
 */

void FUN_0074ee50(int param_1,ushort *param_2,localeinfo_struct *param_3,wchar_t *param_4)

{
  ushort uVar1;
  wchar_t wVar2;
  short *psVar3;
  int *piVar4;
  wchar_t *pwVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  int extraout_ECX;
  uint uVar10;
  int iVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  bool bVar14;
  longlong lVar15;
  uint local_470;
  uint local_46c;
  uint local_468;
  undefined4 local_464;
  int local_460;
  localeinfo_struct local_45c;
  int local_454;
  char local_450;
  int local_44c;
  wchar_t *local_448;
  ushort *local_444;
  int local_440;
  undefined2 local_43c;
  short local_43a;
  char local_438;
  undefined1 local_437;
  int local_434;
  uint local_430;
  int local_42c;
  int local_428;
  int local_424;
  wchar_t *local_420;
  uint local_41c;
  uint local_418;
  wchar_t *local_414;
  uint local_410;
  uint local_40c;
  wchar_t local_408 [8];
  undefined1 local_3f8 [495];
  undefined2 local_209;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)local_3f8;
  local_434 = param_1;
  local_420 = param_4;
  local_44c = 0;
  local_40c = 0;
  local_430 = 0;
  local_410 = 0;
  local_428 = 0;
  local_440 = 0;
  local_42c = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_45c,param_3);
  if ((local_434 == 0) || (param_2 == (ushort *)0x0)) {
    puVar6 = (undefined4 *)FUN_006ead5f();
    *puVar6 = 0x16;
LAB_0074eec0:
    FUN_006e9fc2(0,0,0,0,0);
    if (local_450 != '\0') {
      *(uint *)(local_454 + 0x70) = *(uint *)(local_454 + 0x70) & 0xfffffffd;
    }
  }
  else {
    uVar1 = *param_2;
    local_424 = 0;
    local_418 = 0;
    local_448 = (wchar_t *)0x0;
    iVar11 = 0;
    while (local_41c = (uint)uVar1, uVar1 != 0) {
      local_444 = param_2 + 1;
      if (local_424 < 0) break;
      if ((ushort)(uVar1 - 0x20) < 0x59) {
        uVar7 = *(byte *)((int)&PTR_DAT_00777e80 + local_41c) & 0xf;
      }
      else {
        uVar7 = 0;
      }
      local_460 = (int)(char)(&DAT_00777ea0)[uVar7 * 8 + iVar11] >> 4;
      switch(local_460) {
      case 0:
switchD_0074ef40_caseD_0:
        local_42c = 1;
        write_char(local_41c);
        break;
      case 1:
        local_410 = 0xffffffff;
        local_464 = 0;
        local_440 = 0;
        local_430 = 0;
        local_428 = 0;
        local_40c = 0;
        local_42c = 0;
        break;
      case 2:
        if (local_41c == 0x20) {
          local_40c = local_40c | 2;
        }
        else if (local_41c == 0x23) {
          local_40c = local_40c | 0x80;
        }
        else if (local_41c == 0x2b) {
          local_40c = local_40c | 1;
        }
        else if (local_41c == 0x2d) {
          local_40c = local_40c | 4;
        }
        else if (local_41c == 0x30) {
          local_40c = local_40c | 8;
        }
        break;
      case 3:
        if (uVar1 == 0x2a) {
          local_420 = param_4 + 2;
          local_430 = *(uint *)param_4;
          if ((int)local_430 < 0) {
            local_40c = local_40c | 4;
            local_430 = -local_430;
          }
        }
        else {
          local_430 = local_41c + local_430 * 10 + -0x30;
        }
        break;
      case 4:
        local_410 = 0;
        break;
      case 5:
        if (uVar1 == 0x2a) {
          local_420 = param_4 + 2;
          local_410 = *(uint *)param_4;
          if ((int)local_410 < 0) {
            local_410 = 0xffffffff;
          }
        }
        else {
          local_410 = local_41c + local_410 * 10 + -0x30;
        }
        break;
      case 6:
        if (local_41c == 0x49) {
          uVar1 = *local_444;
          if ((uVar1 == 0x36) && (param_2[2] == 0x34)) {
            local_444 = param_2 + 3;
            local_40c = local_40c | 0x8000;
          }
          else if ((uVar1 == 0x33) && (param_2[2] == 0x32)) {
            local_444 = param_2 + 3;
            local_40c = local_40c & 0xffff7fff;
          }
          else if (((((uVar1 != 100) && (uVar1 != 0x69)) && (uVar1 != 0x6f)) &&
                   ((uVar1 != 0x75 && (uVar1 != 0x78)))) && (uVar1 != 0x58)) {
            local_460 = 0;
            goto switchD_0074ef40_caseD_0;
          }
        }
        else if (local_41c == 0x68) {
          local_40c = local_40c | 0x20;
        }
        else if (local_41c == 0x6c) {
          if (*local_444 == 0x6c) {
            local_444 = param_2 + 2;
            local_40c = local_40c | 0x1000;
          }
          else {
            local_40c = local_40c | 0x10;
          }
        }
        else if (local_41c == 0x77) {
          local_40c = local_40c | 0x800;
        }
        break;
      case 7:
        if (local_41c < 0x65) {
          if (local_41c == 100) {
LAB_0074f349:
            local_40c = local_40c | 0x40;
LAB_0074f34d:
            local_41c = 10;
LAB_0074f354:
            if (((local_40c & 0x8000) == 0) && ((local_40c & 0x1000) == 0)) {
              local_420 = param_4 + 2;
              if ((local_40c & 0x20) == 0) {
                uVar7 = *(uint *)param_4;
                if ((local_40c & 0x40) == 0) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = (int)uVar7 >> 0x1f;
                }
              }
              else {
                if ((local_40c & 0x40) == 0) {
                  uVar7 = (uint)(ushort)*param_4;
                }
                else {
                  uVar7 = (uint)*param_4;
                }
                uVar10 = (int)uVar7 >> 0x1f;
              }
            }
            else {
              uVar7 = *(uint *)param_4;
              uVar10 = *(uint *)(param_4 + 2);
              local_420 = param_4 + 4;
            }
            if ((((local_40c & 0x40) != 0) && ((int)uVar10 < 1)) && ((int)uVar10 < 0)) {
              bVar14 = uVar7 != 0;
              uVar7 = -uVar7;
              uVar10 = -(uVar10 + bVar14);
              local_40c = local_40c | 0x100;
            }
            if ((local_40c & 0x9000) == 0) {
              uVar10 = 0;
            }
            lVar15 = CONCAT44(uVar10,uVar7);
            if ((int)local_410 < 0) {
              local_410 = 1;
            }
            else {
              local_40c = local_40c & 0xfffffff7;
              if (0x200 < (int)local_410) {
                local_410 = 0x200;
              }
            }
            if (uVar7 == 0 && uVar10 == 0) {
              local_428 = 0;
            }
            pwVar13 = &local_209;
            while ((uVar7 = local_410 - 1, 0 < (int)local_410 || (lVar15 != 0))) {
              local_410 = uVar7;
              lVar15 = __aulldvrm(lVar15,local_41c,(int)local_41c >> 0x1f);
              iVar11 = extraout_ECX + 0x30;
              if (0x39 < iVar11) {
                iVar11 = iVar11 + local_44c;
              }
              *(byte *)pwVar13 = (byte)iVar11;
              pwVar13 = (wchar_t *)((int)pwVar13 + -1);
            }
            local_418 = (int)&local_209 + -(int)pwVar13;
            local_414 = (wchar_t *)((int)pwVar13 + 1);
            local_410 = uVar7;
            if (((local_40c & 0x200) != 0) && ((local_418 == 0 || (*(byte *)local_414 != 0x30)))) {
              *(byte *)pwVar13 = 0x30;
              local_418 = (int)&local_209 + -(int)pwVar13 + 1;
              local_414 = pwVar13;
            }
          }
          else if (local_41c < 0x54) {
            if (local_41c == 0x53) {
              if ((local_40c & 0x830) == 0) {
                local_40c = local_40c | 0x20;
              }
              goto LAB_0074f19f;
            }
            if (local_41c != 0x41) {
              if (local_41c == 0x43) {
                if ((local_40c & 0x830) == 0) {
                  local_40c = local_40c | 0x20;
                }
LAB_0074f226:
                wVar2 = *param_4;
                local_468 = (uint)(ushort)wVar2;
                local_420 = param_4 + 2;
                local_42c = 1;
                if ((local_40c & 0x20) == 0) {
                  local_408[0] = wVar2;
                }
                else {
                  local_438 = (char)wVar2;
                  local_437 = 0;
                  iVar11 = __mbtowc_l(local_408,&local_438,
                                      (size_t)(local_45c.locinfo)->locale_name[3],&local_45c);
                  if (iVar11 < 0) {
                    local_440 = 1;
                  }
                }
                local_418 = 1;
                local_414 = local_408;
                goto LAB_0074f5ca;
              }
              if ((local_41c != 0x45) && (local_41c != 0x47)) goto LAB_0074f5ca;
            }
            local_41c = local_41c + 0x20;
            local_464 = 1;
LAB_0074f156:
            local_40c = local_40c | 0x40;
            local_418 = 0x200;
            pwVar12 = local_408;
            uVar7 = local_418;
            pwVar13 = local_408;
            if ((int)local_410 < 0) {
              local_410 = 6;
            }
            else if (local_410 == 0) {
              if ((short)local_41c == 0x67) {
                local_410 = 1;
              }
            }
            else {
              if (0x200 < (int)local_410) {
                local_410 = 0x200;
              }
              if (0xa3 < (int)local_410) {
                uVar7 = local_410 + 0x15d;
                local_414 = local_408;
                local_448 = __malloc_crt(uVar7);
                pwVar12 = local_448;
                pwVar13 = local_448;
                if (local_448 == (wchar_t *)0x0) {
                  local_410 = 0xa3;
                  pwVar12 = local_408;
                  uVar7 = local_418;
                  pwVar13 = local_414;
                }
              }
            }
            local_414 = pwVar13;
            local_418 = uVar7;
            local_470 = *(uint *)param_4;
            local_420 = param_4 + 4;
            local_46c = *(uint *)(param_4 + 2);
            pcVar8 = (code *)FUN_006f01bc(PTR_LAB_00829a98,&local_470,pwVar12,local_418,
                                          (int)(char)local_41c,local_410,local_464,&local_45c);
            (*pcVar8)();
            uVar7 = local_40c & 0x80;
            if ((uVar7 != 0) && (local_410 == 0)) {
              pcVar8 = (code *)FUN_006f01bc(PTR_LAB_00829aa4,pwVar12,&local_45c);
              (*pcVar8)();
            }
            if (((short)local_41c == 0x67) && (uVar7 == 0)) {
              pcVar8 = (code *)FUN_006f01bc(PTR_LAB_00829aa0,pwVar12,&local_45c);
              (*pcVar8)();
            }
            pwVar13 = pwVar12;
            pwVar5 = local_414;
            if ((byte)*pwVar12 == 0x2d) {
              local_40c = local_40c | 0x100;
              pwVar13 = (wchar_t *)((int)pwVar12 + 1);
              pwVar5 = (wchar_t *)((int)pwVar12 + 1);
            }
LAB_0074f2bf:
            local_414 = pwVar5;
            local_418 = _strlen((char *)pwVar13);
          }
          else {
            if (local_41c == 0x58) goto LAB_0074f455;
            if (local_41c == 0x5a) {
              psVar3 = *(short **)param_4;
              local_420 = param_4 + 2;
              pwVar13 = (wchar_t *)PTR_DAT_00829aa8;
              pwVar5 = (wchar_t *)PTR_DAT_00829aa8;
              if ((psVar3 == (short *)0x0) ||
                 (local_414 = *(wchar_t **)(psVar3 + 2), pwVar5 = (wchar_t *)PTR_DAT_00829aa8,
                 local_414 == (wchar_t *)0x0)) goto LAB_0074f2bf;
              local_418 = (uint)*psVar3;
              if ((local_40c & 0x800) != 0) {
                iVar11 = local_418 - ((int)local_418 >> 0x1f);
                goto LAB_0074f5c5;
              }
              local_42c = 0;
            }
            else {
              if (local_41c == 0x61) goto LAB_0074f156;
              if (local_41c == 99) goto LAB_0074f226;
            }
          }
LAB_0074f5ca:
          uVar7 = local_418;
          if (local_440 == 0) {
            if ((local_40c & 0x40) != 0) {
              if ((local_40c & 0x100) == 0) {
                if ((local_40c & 1) == 0) {
                  if ((local_40c & 2) == 0) goto LAB_0074f606;
                  local_43c = 0x20;
                }
                else {
                  local_43c = 0x2b;
                }
              }
              else {
                local_43c = 0x2d;
              }
              local_428 = 1;
            }
LAB_0074f606:
            iVar11 = local_430 + (-local_428 - local_418);
            if ((local_40c & 0xc) == 0) {
              write_multi_char(0x20,iVar11,local_434);
            }
            iVar9 = local_434;
            write_string(local_428);
            if (((local_40c & 8) != 0) && ((local_40c & 4) == 0)) {
              write_multi_char(0x30,iVar11,iVar9);
            }
            if ((local_42c == 0) && (0 < (int)uVar7)) {
              local_41c = uVar7;
              pwVar13 = local_414;
              do {
                local_41c = local_41c - 1;
                iVar9 = __mbtowc_l((wchar_t *)&local_468,(char *)pwVar13,
                                   (size_t)(local_45c.locinfo)->locale_name[3],&local_45c);
                if (iVar9 < 1) {
                  local_424 = -1;
                  break;
                }
                write_char(local_468);
                pwVar13 = (wchar_t *)((int)pwVar13 + iVar9);
              } while (0 < (int)local_41c);
            }
            else {
              write_string(uVar7);
            }
            if ((-1 < local_424) && ((local_40c & 4) != 0)) {
              write_multi_char(0x20,iVar11,local_434);
            }
          }
        }
        else {
          if (0x70 < local_41c) {
            if (local_41c == 0x73) {
LAB_0074f19f:
              uVar7 = local_410;
              if (local_410 == 0xffffffff) {
                uVar7 = 0x7fffffff;
              }
              local_420 = param_4 + 2;
              local_414 = *(wchar_t **)param_4;
              if ((local_40c & 0x20) == 0) {
                pwVar13 = local_414;
                if (local_414 == (wchar_t *)0x0) {
                  pwVar13 = (wchar_t *)PTR_u__null__00829aac;
                  local_414 = (wchar_t *)PTR_u__null__00829aac;
                }
                for (; (uVar7 != 0 && (uVar7 = uVar7 - 1, *pwVar13 != L'\0')); pwVar13 = pwVar13 + 1
                    ) {
                }
                iVar11 = (int)pwVar13 - (int)local_414;
LAB_0074f5c5:
                local_420 = param_4 + 2;
                local_42c = 1;
                local_418 = iVar11 >> 1;
              }
              else {
                if (local_414 == (wchar_t *)0x0) {
                  local_414 = (wchar_t *)PTR_DAT_00829aa8;
                }
                local_418 = 0;
                pwVar13 = local_414;
                if (0 < (int)uVar7) {
                  do {
                    if ((byte)*pwVar13 == 0) break;
                    iVar11 = __isleadbyte_l((uint)(byte)*pwVar13,&local_45c);
                    if (iVar11 != 0) {
                      pwVar13 = (wchar_t *)((int)pwVar13 + 1);
                    }
                    pwVar13 = (wchar_t *)((int)pwVar13 + 1);
                    local_418 = local_418 + 1;
                  } while ((int)local_418 < (int)uVar7);
                }
              }
              goto LAB_0074f5ca;
            }
            if (local_41c == 0x75) goto LAB_0074f34d;
            if (local_41c != 0x78) goto LAB_0074f5ca;
            local_44c = 0x27;
LAB_0074f47b:
            local_41c = 0x10;
            if ((local_40c & 0x80) != 0) {
              local_43a = (short)local_44c + 0x51;
              local_43c = 0x30;
              local_428 = 2;
            }
            goto LAB_0074f354;
          }
          if (local_41c == 0x70) {
            local_410 = 8;
LAB_0074f455:
            local_44c = 7;
            goto LAB_0074f47b;
          }
          if (local_41c < 0x65) goto LAB_0074f5ca;
          if (local_41c < 0x68) goto LAB_0074f156;
          if (local_41c == 0x69) goto LAB_0074f349;
          if (local_41c != 0x6e) {
            if (local_41c != 0x6f) goto LAB_0074f5ca;
            local_41c = 8;
            if ((local_40c & 0x80) != 0) {
              local_40c = local_40c | 0x200;
            }
            goto LAB_0074f354;
          }
          piVar4 = *(int **)param_4;
          local_420 = param_4 + 2;
          iVar11 = FUN_006e7a93();
          if (iVar11 == 0) {
            puVar6 = (undefined4 *)FUN_006ead5f();
            *puVar6 = 0x16;
            goto LAB_0074eec0;
          }
          if ((local_40c & 0x20) == 0) {
            *piVar4 = local_424;
          }
          else {
            *(undefined2 *)piVar4 = (undefined2)local_424;
          }
          local_440 = 1;
        }
        if (local_448 != (wchar_t *)0x0) {
          _free(local_448);
          local_448 = (wchar_t *)0x0;
        }
      }
      iVar11 = local_460;
      param_4 = local_420;
      param_2 = local_444;
      uVar1 = *local_444;
    }
    if (local_450 != '\0') {
      *(uint *)(local_454 + 0x70) = *(uint *)(local_454 + 0x70) & 0xfffffffd;
    }
  }
  __security_check_cookie(local_8 ^ (uint)local_3f8);
  return;
}

