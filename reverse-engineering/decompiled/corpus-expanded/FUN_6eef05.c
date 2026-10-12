/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6eef05; label: FUN_006eef05
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */

void FUN_006eef05(FILE *param_1,byte *param_2,localeinfo_struct *param_3,wchar_t *param_4)

{
  byte bVar1;
  wchar_t _WCh;
  short *psVar2;
  wchar_t *pwVar3;
  int *piVar4;
  ulonglong uVar5;
  FILE *pFVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  code *pcVar11;
  errno_t eVar12;
  int extraout_ECX;
  byte *pbVar13;
  size_t sVar14;
  wchar_t *pwVar15;
  bool bVar16;
  longlong lVar17;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  int local_270;
  int local_26c [2];
  size_t local_264;
  localeinfo_struct local_260;
  int local_258;
  char local_254;
  wchar_t *local_250;
  int local_24c;
  int local_248;
  byte *local_244;
  int local_240;
  int local_23c;
  int local_238;
  undefined1 local_234;
  char local_233;
  int local_230;
  FILE *local_22c;
  wchar_t *local_228;
  size_t local_224;
  wchar_t *local_220;
  int local_21c;
  byte local_215;
  uint local_214;
  wchar_t local_210 [10];
  undefined1 local_1fc [491];
  undefined2 local_11;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)local_1fc;
  local_22c = param_1;
  local_228 = param_4;
  local_248 = 0;
  local_214 = 0;
  local_23c = 0;
  local_21c = 0;
  local_238 = 0;
  local_24c = 0;
  local_240 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_260,param_3);
  if (local_22c != (FILE *)0x0) {
    if ((local_22c->_flag & 0x40) == 0) {
      iVar8 = __fileno(local_22c);
      if ((iVar8 == -1) || (iVar8 = __fileno(local_22c), iVar8 == -2)) {
        puVar10 = &DAT_00829c00;
      }
      else {
        iVar8 = __fileno(local_22c);
        uVar9 = __fileno(local_22c);
        puVar10 = (undefined *)((uVar9 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar8 >> 5]);
      }
      if ((puVar10[0x24] & 0x7f) == 0) {
        iVar8 = __fileno(local_22c);
        if ((iVar8 == -1) || (iVar8 = __fileno(local_22c), iVar8 == -2)) {
          puVar10 = &DAT_00829c00;
        }
        else {
          iVar8 = __fileno(local_22c);
          uVar9 = __fileno(local_22c);
          puVar10 = (undefined *)((uVar9 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar8 >> 5]);
        }
        if ((puVar10[0x24] & 0x80) == 0) goto LAB_006ef043;
      }
    }
    else {
LAB_006ef043:
      if (param_2 != (byte *)0x0) {
        local_215 = *param_2;
        local_230 = 0;
        local_224 = 0;
        local_250 = (wchar_t *)0x0;
        iVar8 = 0;
        while ((local_215 != 0 && (pbVar13 = param_2 + 1, local_244 = pbVar13, -1 < local_230))) {
          if ((byte)(local_215 - 0x20) < 0x59) {
            uVar9 = *(byte *)((int)&PTR_DAT_00777e80 + (int)(char)local_215) & 0xf;
          }
          else {
            uVar9 = 0;
          }
          local_270 = (int)(char)(&DAT_00777ea0)[uVar9 * 8 + iVar8] >> 4;
          switch(local_270) {
          case 0:
switchD_006ef0a7_caseD_0:
            local_240 = 0;
            iVar8 = __isleadbyte_l((uint)local_215,&local_260);
            if (iVar8 != 0) {
              write_char();
              local_244 = param_2 + 2;
              if (*pbVar13 == 0) {
LAB_006ef83a:
                puVar7 = (undefined4 *)FUN_006ead5f();
                *puVar7 = 0x16;
                goto LAB_006eef75;
              }
            }
            write_char();
            break;
          case 1:
            local_21c = -1;
            local_274 = 0;
            local_24c = 0;
            local_23c = 0;
            local_238 = 0;
            local_214 = 0;
            local_240 = 0;
            break;
          case 2:
            if (local_215 == 0x20) {
              local_214 = local_214 | 2;
            }
            else if (local_215 == 0x23) {
              local_214 = local_214 | 0x80;
            }
            else if (local_215 == 0x2b) {
              local_214 = local_214 | 1;
            }
            else if (local_215 == 0x2d) {
              local_214 = local_214 | 4;
            }
            else if (local_215 == 0x30) {
              local_214 = local_214 | 8;
            }
            break;
          case 3:
            if (local_215 == 0x2a) {
              local_228 = param_4 + 2;
              local_23c = *(int *)param_4;
              if (local_23c < 0) {
                local_214 = local_214 | 4;
                local_23c = -local_23c;
              }
            }
            else {
              local_23c = local_23c * 10 + -0x30 + (int)(char)local_215;
            }
            break;
          case 4:
            local_21c = 0;
            break;
          case 5:
            if (local_215 == 0x2a) {
              local_228 = param_4 + 2;
              local_21c = *(int *)param_4;
              if (local_21c < 0) {
                local_21c = -1;
              }
            }
            else {
              local_21c = local_21c * 10 + -0x30 + (int)(char)local_215;
            }
            break;
          case 6:
            if (local_215 == 0x49) {
              bVar1 = *pbVar13;
              if ((bVar1 == 0x36) && (param_2[2] == 0x34)) {
                local_214 = local_214 | 0x8000;
                local_244 = param_2 + 3;
              }
              else if ((bVar1 == 0x33) && (param_2[2] == 0x32)) {
                local_214 = local_214 & 0xffff7fff;
                local_244 = param_2 + 3;
              }
              else if (((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
                       ((bVar1 != 0x75 && (bVar1 != 0x78)))) && (bVar1 != 0x58)) {
                local_270 = 0;
                goto switchD_006ef0a7_caseD_0;
              }
            }
            else if (local_215 == 0x68) {
              local_214 = local_214 | 0x20;
            }
            else if (local_215 == 0x6c) {
              if (*pbVar13 == 0x6c) {
                local_214 = local_214 | 0x1000;
                local_244 = param_2 + 2;
              }
              else {
                local_214 = local_214 | 0x10;
              }
            }
            else if (local_215 == 0x77) {
              local_214 = local_214 | 0x800;
            }
            break;
          case 7:
            if ((char)local_215 < 'e') {
              if (local_215 == 100) {
LAB_006ef486:
                local_214 = local_214 | 0x40;
LAB_006ef48a:
                local_224 = 10;
LAB_006ef491:
                if (((short)local_214 < 0) || ((local_214 & 0x1000) != 0)) {
                  uVar9 = *(uint *)param_4;
                  iVar8 = *(int *)(param_4 + 2);
                  local_228 = param_4 + 4;
                }
                else {
                  local_228 = param_4 + 2;
                  if ((local_214 & 0x20) == 0) {
                    uVar9 = *(uint *)param_4;
                    if ((local_214 & 0x40) == 0) {
                      iVar8 = 0;
                    }
                    else {
                      iVar8 = (int)uVar9 >> 0x1f;
                    }
                  }
                  else {
                    if ((local_214 & 0x40) == 0) {
                      uVar9 = (uint)(ushort)*param_4;
                    }
                    else {
                      uVar9 = (uint)*param_4;
                    }
                    iVar8 = (int)uVar9 >> 0x1f;
                  }
                }
                if ((((local_214 & 0x40) != 0) && (iVar8 < 1)) && (iVar8 < 0)) {
                  bVar16 = uVar9 != 0;
                  uVar9 = -uVar9;
                  iVar8 = -(iVar8 + (uint)bVar16);
                  local_214 = local_214 | 0x100;
                }
                if ((local_214 & 0x9000) == 0) {
                  iVar8 = 0;
                }
                lVar17 = CONCAT44(iVar8,uVar9);
                if (local_21c < 0) {
                  local_21c = 1;
                }
                else {
                  local_214 = local_214 & 0xfffffff7;
                  if (0x200 < local_21c) {
                    local_21c = 0x200;
                  }
                }
                if (uVar9 == 0 && iVar8 == 0) {
                  local_238 = 0;
                }
                pwVar15 = &local_11;
                while( true ) {
                  uVar5 = (ulonglong)lVar17 >> 0x20;
                  iVar8 = local_21c + -1;
                  if ((local_21c < 1) && (lVar17 == 0)) break;
                  local_21c = iVar8;
                  lVar17 = __aulldvrm(lVar17,local_224,(int)local_224 >> 0x1f);
                  iVar8 = extraout_ECX + 0x30;
                  if (0x39 < iVar8) {
                    iVar8 = iVar8 + local_248;
                  }
                  *(char *)pwVar15 = (char)iVar8;
                  pwVar15 = (wchar_t *)((int)pwVar15 + -1);
                  local_264 = (size_t)uVar5;
                }
                local_224 = (int)&local_11 + -(int)pwVar15;
                local_220 = (wchar_t *)((int)pwVar15 + 1);
                local_21c = iVar8;
                if (((local_214 & 0x200) != 0) && ((local_224 == 0 || (*(char *)local_220 != '0'))))
                {
                  *(char *)pwVar15 = '0';
                  local_224 = (int)&local_11 + -(int)pwVar15 + 1;
                  local_220 = pwVar15;
                }
              }
              else if ((char)local_215 < 'T') {
                if (local_215 == 0x53) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
                  goto LAB_006ef30f;
                }
                if (local_215 == 0x41) {
LAB_006ef2bb:
                  local_215 = local_215 + 0x20;
                  local_274 = 1;
LAB_006ef2c8:
                  local_214 = local_214 | 0x40;
                  local_264 = 0x200;
                  pwVar15 = local_210;
                  sVar14 = local_264;
                  pwVar3 = local_210;
                  if (local_21c < 0) {
                    local_21c = 6;
                  }
                  else if (local_21c == 0) {
                    if (local_215 == 0x67) {
                      local_21c = 1;
                    }
                  }
                  else {
                    if (0x200 < local_21c) {
                      local_21c = 0x200;
                    }
                    if (0xa3 < local_21c) {
                      sVar14 = local_21c + 0x15d;
                      local_220 = local_210;
                      local_250 = __malloc_crt(sVar14);
                      pwVar15 = local_250;
                      pwVar3 = local_250;
                      if (local_250 == (wchar_t *)0x0) {
                        local_21c = 0xa3;
                        pwVar15 = local_210;
                        sVar14 = local_264;
                        pwVar3 = local_220;
                      }
                    }
                  }
                  local_220 = pwVar3;
                  local_264 = sVar14;
                  local_27c = *(undefined4 *)param_4;
                  local_228 = param_4 + 4;
                  local_278 = *(undefined4 *)(param_4 + 2);
                  pcVar11 = (code *)FUN_006f01bc(PTR_LAB_00829a98,&local_27c,pwVar15,local_264,
                                                 (int)(char)local_215,local_21c,local_274,&local_260
                                                );
                  (*pcVar11)();
                  uVar9 = local_214 & 0x80;
                  if ((uVar9 != 0) && (local_21c == 0)) {
                    pcVar11 = (code *)FUN_006f01bc(PTR_LAB_00829aa4,pwVar15,&local_260);
                    (*pcVar11)();
                  }
                  if ((local_215 == 0x67) && (uVar9 == 0)) {
                    pcVar11 = (code *)FUN_006f01bc(PTR_LAB_00829aa0,pwVar15,&local_260);
                    (*pcVar11)();
                  }
                  if ((char)*pwVar15 == '-') {
                    local_214 = local_214 | 0x100;
                    local_220 = (wchar_t *)((int)pwVar15 + 1);
                    pwVar15 = local_220;
                  }
LAB_006ef3fc:
                  local_224 = _strlen((char *)pwVar15);
                }
                else if (local_215 == 0x43) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
LAB_006ef36c:
                  local_228 = param_4 + 2;
                  if ((local_214 & 0x810) == 0) {
                    local_210[0]._0_1_ = (char)*param_4;
                    local_224 = 1;
                  }
                  else {
                    eVar12 = _wctomb_s((int *)&local_224,(char *)local_210,0x200,*param_4);
                    if (eVar12 != 0) {
                      local_24c = 1;
                    }
                  }
                  local_220 = local_210;
                }
                else if ((local_215 == 0x45) || (local_215 == 0x47)) goto LAB_006ef2bb;
              }
              else {
                if (local_215 == 0x58) goto LAB_006ef591;
                if (local_215 == 0x5a) {
                  psVar2 = *(short **)param_4;
                  local_228 = param_4 + 2;
                  pwVar15 = (wchar_t *)PTR_DAT_00829aa8;
                  local_220 = (wchar_t *)PTR_DAT_00829aa8;
                  if ((psVar2 == (short *)0x0) ||
                     (pwVar3 = *(wchar_t **)(psVar2 + 2), pwVar3 == (wchar_t *)0x0))
                  goto LAB_006ef3fc;
                  local_224 = (size_t)*psVar2;
                  local_220 = pwVar3;
                  if ((local_214 & 0x800) == 0) {
                    local_240 = 0;
                  }
                  else {
                    local_224 = (int)local_224 / 2;
                    local_240 = 1;
                  }
                }
                else {
                  if (local_215 == 0x61) goto LAB_006ef2c8;
                  if (local_215 == 99) goto LAB_006ef36c;
                }
              }
LAB_006ef709:
              if (local_24c == 0) {
                if ((local_214 & 0x40) != 0) {
                  if ((local_214 & 0x100) == 0) {
                    if ((local_214 & 1) == 0) {
                      if ((local_214 & 2) == 0) goto LAB_006ef73f;
                      local_234 = 0x20;
                    }
                    else {
                      local_234 = 0x2b;
                    }
                  }
                  else {
                    local_234 = 0x2d;
                  }
                  local_238 = 1;
                }
LAB_006ef73f:
                iVar8 = (local_23c - local_224) - local_238;
                if ((local_214 & 0xc) == 0) {
                  write_multi_char(0x20,iVar8,local_22c);
                }
                pFVar6 = local_22c;
                write_string(local_238);
                if (((local_214 & 8) != 0) && ((local_214 & 4) == 0)) {
                  write_multi_char(0x30,iVar8,pFVar6);
                }
                if ((local_240 == 0) || ((int)local_224 < 1)) {
                  write_string(local_224);
                }
                else {
                  local_264 = local_224;
                  pwVar15 = local_220;
                  do {
                    _WCh = *pwVar15;
                    local_264 = local_264 - 1;
                    pwVar15 = pwVar15 + 1;
                    eVar12 = _wctomb_s(local_26c,(char *)((int)&local_11 + 1),6,_WCh);
                    if ((eVar12 != 0) || (local_26c[0] == 0)) {
                      local_230 = -1;
                      break;
                    }
                    write_string(local_26c[0]);
                  } while (local_264 != 0);
                }
                if ((-1 < local_230) && ((local_214 & 4) != 0)) {
                  write_multi_char(0x20,iVar8,pFVar6);
                }
              }
            }
            else {
              if ('p' < (char)local_215) {
                if (local_215 == 0x73) {
LAB_006ef30f:
                  iVar8 = local_21c;
                  if (local_21c == -1) {
                    iVar8 = 0x7fffffff;
                  }
                  local_228 = param_4 + 2;
                  local_220 = *(wchar_t **)param_4;
                  if ((local_214 & 0x810) == 0) {
                    pwVar15 = local_220;
                    if (local_220 == (wchar_t *)0x0) {
                      pwVar15 = (wchar_t *)PTR_DAT_00829aa8;
                      local_220 = (wchar_t *)PTR_DAT_00829aa8;
                    }
                    for (; (iVar8 != 0 && (iVar8 = iVar8 + -1, (char)*pwVar15 != '\0'));
                        pwVar15 = (wchar_t *)((int)pwVar15 + 1)) {
                    }
                    local_224 = (int)pwVar15 - (int)local_220;
                  }
                  else {
                    if (local_220 == (wchar_t *)0x0) {
                      local_220 = (wchar_t *)PTR_u__null__00829aac;
                    }
                    local_240 = 1;
                    for (pwVar15 = local_220;
                        (iVar8 != 0 && (iVar8 = iVar8 + -1, *pwVar15 != L'\0'));
                        pwVar15 = pwVar15 + 1) {
                    }
                    local_224 = (int)pwVar15 - (int)local_220 >> 1;
                  }
                  goto LAB_006ef709;
                }
                if (local_215 == 0x75) goto LAB_006ef48a;
                if (local_215 != 0x78) goto LAB_006ef709;
                local_248 = 0x27;
LAB_006ef5b7:
                local_224 = 0x10;
                if ((local_214 & 0x80) != 0) {
                  local_233 = (char)local_248 + 'Q';
                  local_234 = 0x30;
                  local_238 = 2;
                }
                goto LAB_006ef491;
              }
              if (local_215 == 0x70) {
                local_21c = 8;
LAB_006ef591:
                local_248 = 7;
                goto LAB_006ef5b7;
              }
              if ((char)local_215 < 'e') goto LAB_006ef709;
              if ((char)local_215 < 'h') goto LAB_006ef2c8;
              if (local_215 == 0x69) goto LAB_006ef486;
              if (local_215 != 0x6e) {
                if (local_215 != 0x6f) goto LAB_006ef709;
                local_224 = 8;
                if ((local_214 & 0x80) != 0) {
                  local_214 = local_214 | 0x200;
                }
                goto LAB_006ef491;
              }
              piVar4 = *(int **)param_4;
              local_228 = param_4 + 2;
              iVar8 = FUN_006e7a93();
              if (iVar8 == 0) goto LAB_006ef83a;
              if ((local_214 & 0x20) == 0) {
                *piVar4 = local_230;
              }
              else {
                *(undefined2 *)piVar4 = (undefined2)local_230;
              }
              local_24c = 1;
            }
            if (local_250 != (wchar_t *)0x0) {
              _free(local_250);
              local_250 = (wchar_t *)0x0;
            }
          }
          local_215 = *local_244;
          iVar8 = local_270;
          param_2 = local_244;
          param_4 = local_228;
        }
        if (local_254 != '\0') {
          *(uint *)(local_258 + 0x70) = *(uint *)(local_258 + 0x70) & 0xfffffffd;
        }
        goto LAB_006ef861;
      }
    }
  }
  puVar7 = (undefined4 *)FUN_006ead5f();
  *puVar7 = 0x16;
LAB_006eef75:
  FUN_006e9fc2(0,0,0,0,0);
  if (local_254 != '\0') {
    *(uint *)(local_258 + 0x70) = *(uint *)(local_258 + 0x70) & 0xfffffffd;
  }
LAB_006ef861:
  __security_check_cookie(local_8 ^ (uint)local_1fc);
  return;
}

