/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4abac0; label: FUN_004abac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004abac0(float param_1,float *param_2,float param_3,undefined4 param_4,float *param_5)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  undefined *puVar8;
  float fVar9;
  int iVar10;
  char extraout_DL;
  char cVar11;
  float *pfVar12;
  float *pfVar13;
  float10 fVar14;
  float10 fVar15;
  float10 extraout_ST0;
  int local_18;
  float local_8;
  float local_4;
  
  fVar9 = param_1;
  local_4 = _DAT_0087b8dc;
  fVar15 = (float10)0;
  _DAT_0087b8dc = (float)fVar15;
  bVar6 = false;
  if (*(int *)((int)param_1 + 0xe64) != 0) {
    return;
  }
  uVar3 = *(uint *)((int)param_1 + 0x1fc);
  if (((uVar3 & 0x20) != 0) || (*(int *)((int)param_1 + 0x10b0) != 0)) {
    return;
  }
  cVar11 = *(char *)((int)param_1 + 0x7b5);
  if ((((*(uint *)(PTR_PTR_007fb0e4 + cVar11 * 0x10 + 8) & 0x400) != 0) &&
      ((cVar11 != 'D' ||
       ((*(short *)((int)param_1 + 0x7aa) != 6 && (*(short *)((int)param_1 + 0x7aa) != 5)))))) ||
     ((cVar11 == '_' && ((*(uint *)((int)param_1 + 0x7bc) & 0x100) != 0)))) {
    return;
  }
  pfVar13 = param_2;
  if (cVar11 == 'K') {
    if (*(int *)((int)param_1 + 0xcbc) == 0) {
      return;
    }
    if ((*(byte *)(*(int *)((int)param_1 + 0xcbc) + 0xc) & 0x10) == 0) {
      return;
    }
    param_1 = -1.0;
    pfVar13 = &param_1;
  }
  if ((uVar3 & 4) != 0) {
    return;
  }
  if ((*(uint *)((int)fVar9 + 0xeec) & 0x80000000) != 0) {
    return;
  }
  if (cVar11 == ',') {
    return;
  }
  if (((*(byte *)((int)fVar9 + 0xe20) & 0x20) != 0) ||
     ((local_18 = *(int *)((int)fVar9 + 0x54), (*(uint *)(local_18 + 4) & 0x2000) == 0 &&
      ((cVar11 == '#' || (cVar11 == '$')))))) goto LAB_004abe9f;
  if (((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x40000) != 0) &&
     ((pfVar13 == (float *)0x0 && (fVar15 == (float10)*(float *)(*(int *)(local_18 + 0x24) + 0x24)))
     )) {
    return;
  }
  if (*(char *)((int)fVar9 + 0x107a) == '\x04') {
    return;
  }
  fVar1 = _DAT_007fbecc;
  pfVar12 = param_5;
  if (((cVar11 != '\x1e') && (fVar1 = _DAT_007fc000, cVar11 != '\"')) &&
     (fVar1 = _DAT_007fc008, cVar11 != 'B')) {
    if (((cVar11 == '\x1c') && (iVar10 = *(int *)((int)fVar9 + 0x790), iVar10 != 0)) &&
       ((uVar4 = *(uint *)(iVar10 + 0xe20), (char)uVar4 < '\0' || ((uVar4 & 0x100) != 0)))) {
      if (*(char *)(iVar10 + 0x7b3) == '\x01') {
        return;
      }
      if (((uVar4 & 0x400) == 0) &&
         (((uVar4 & 0x100) == 0 || ((*(uint *)(*(int *)(local_18 + 0x24) + 0x90) & 0x4000) == 0))))
      {
        local_8 = *(float *)(iVar10 + 0x1a0);
        param_3 = (*(float *)(iVar10 + 0x194) - *(float *)(iVar10 + 0x1a0)) * 0.75;
        param_4 = 0x41000000;
        pfVar12 = &local_8;
      }
      goto LAB_004abc44;
    }
    if ((cVar11 != ']') || (*(float *)((int)fVar9 + 0x778) == 1e+09)) goto LAB_004abc44;
    param_1 = (*(float *)((int)fVar9 + 0x60) - *(float *)((int)fVar9 + 0x778)) *
              *(float *)(*(int *)(local_18 + 0x24) + 0x24) * 0.333;
    uVar5 = 0x41000000;
    goto LAB_004ac1bd;
  }
  param_3 = fVar1;
  param_4 = 0x41000000;
LAB_004abc44:
  if (*(float *)((int)fVar9 + 0x1028) != 1e+09) {
    param_3 = *(float *)((int)fVar9 + 0x1028);
  }
  fVar14 = (float10)param_3;
  if ((fVar14 != fVar15) && (fVar15 < (float10)*(float *)((int)fVar9 + 0xd9c))) {
    if (((DAT_0087af78 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af78)) &&
       ((DAT_0087b01c == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b01c)))) {
      if ((*(char *)(*(int *)(local_18 + 0x24) + 0x116) == '\x02') && ((uVar3 & 0x80) != 0)) {
        if ((fVar15 < (float10)*(float *)((int)fVar9 + 0xd9c)) &&
           (*(float *)((int)fVar9 + 0xdb4) != 2e+06)) {
          bVar6 = true;
          fVar1 = *(float *)((int)fVar9 + 0xd9c);
          if (!NAN(fVar1) && 0.6 < fVar1 != (fVar1 == 0.6)) {
            *(float *)((int)fVar9 + 0xdb4) = *(float *)((int)fVar9 + 0xdb4) - _DAT_00925018 * 3.0;
          }
        }
        goto LAB_004abe3e;
      }
      param_3 = (float)(fVar14 - (float10)*(float *)((int)fVar9 + 0xd9c) * (float10)0.5);
    }
    else {
      param_3 = (float)fVar15;
    }
    fVar14 = (float10)param_3;
  }
LAB_004abe3e:
  if (cVar11 != '3') {
    if (((((*(byte *)((int)fVar9 + 0x281) & 1) != 0) && (*(char *)((int)fVar9 + 0x1078) == '\0')) &&
        (fVar15 == (float10)*(float *)((int)fVar9 + 0x6c))) &&
       (_DAT_029920bc < *(float *)((int)fVar9 + 0xf28))) {
      *(byte *)((int)fVar9 + 0x281) = *(byte *)((int)fVar9 + 0x281) & 0xfe;
    }
    if ((fVar15 == fVar14) && ((*(byte *)((int)fVar9 + 0x281) & 1) != 0)) {
LAB_004abe9f:
      *(float *)((int)fVar9 + 0x6c) = (float)fVar15;
      return;
    }
  }
  bVar7 = false;
  if (pfVar13 == (float *)0x0) {
    if ((*(float *)((int)fVar9 + 0x21c) == 2e+06) || (fVar15 == fVar14)) {
      if (DAT_007f39e4 == 0) {
LAB_004ac210:
        if (cVar11 == '\0') {
          param_1 = _DAT_00802da4;
          if (*(char *)((int)fVar9 + 0x7b8) == '\x04') goto LAB_004ac2e5;
          if (*(char *)((int)fVar9 + 0x7b8) == '\x05') {
            if (*(char *)((int)fVar9 + 0x285) == '\x1a') {
              *(undefined1 *)((int)fVar9 + 0xe32) = 3;
            }
            else if ((*(uint *)(*(int *)((int)fVar9 + 0xca4) + 4) & DAT_00802278) != 0) {
              param_1 = -1.0;
              if (*(char *)((int)fVar9 + 0xe32) == '\x03') goto LAB_004ac2e5;
              if (*(char *)((int)fVar9 + 0xe32) == '\x02') {
LAB_004ac1da:
                *(float *)((int)fVar9 + 0x6c) = (float)fVar15;
                return;
              }
              bVar7 = true;
              goto LAB_004ac2a0;
            }
            if (*(char *)((int)fVar9 + 0xe32) == '\x02') {
              *(undefined1 *)((int)fVar9 + 0xe32) = 3;
            }
            *(float *)((int)fVar9 + 0xd64) = (float)fVar15;
          }
        }
        goto LAB_004ac2a0;
      }
      if (cVar11 != '\0') goto LAB_004ac2a0;
      if (*(char *)((int)fVar9 + 0x7b8) != '\x03') goto LAB_004ac210;
      param_1 = -10.0;
    }
    else {
      if (cVar11 != '+') {
        if (bVar6) {
          *(float *)((int)fVar9 + 0xd7c) = (float)fVar15;
          param_1 = (*(float *)((int)fVar9 + 0x60) - *(float *)((int)fVar9 + 0xdb4)) *
                    *(float *)(*(int *)(local_18 + 0x24) + 0x24);
LAB_004ac1af:
          param_1 = param_1 * 0.333;
          uVar5 = param_4;
        }
        else if (((*(char *)((int)fVar9 + 0x283) == '\a') ||
                 (*(char *)((int)fVar9 + 0x283) == '\x10')) &&
                ((DAT_00951288 != 0 ||
                 (((*(byte *)(*(int *)(local_18 + 0x24) + 0x90) & 0x40) == 0 ||
                  (*(int *)((int)fVar9 + 0xcd0) != 0)))))) {
          FUN_00498590(fVar9,&param_1);
          param_1 = *(float *)((int)fVar9 + 0x220) + param_1;
          if (*(float *)((int)fVar9 + 0x1028) != 1e+09) {
            param_1 = *(float *)((int)fVar9 + 0x1028) + param_1;
          }
          fVar15 = (float10)FUN_00498320(fVar9);
          if ((*(char *)((int)fVar9 + 0x288) != '\0') || (_DAT_00925018 < 0.016666668)) {
            param_1 = (*(float *)((int)fVar9 + 0x84) - (float)(fVar15 + (float10)param_1)) *
                      *(float *)(*(int *)(*(int *)((int)fVar9 + 0x54) + 0x24) + 0x24);
            goto LAB_004ac1af;
          }
          param_1 = ((*(float *)((int)fVar9 + 0x84) - (float)(fVar15 + (float10)param_1)) *
                    *(float *)(*(int *)(*(int *)((int)fVar9 + 0x54) + 0x24) + 0x24)) /
                    (_DAT_00925018 * 180.0);
          uVar5 = param_4;
        }
        else {
          if ((DAT_0087af5c != 0) &&
             (((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c && ((uVar3 & 0x80) != 0)) &&
              (iVar10 = FUN_0056d800(PTR_DAT_00802c54,fVar9,1), iVar10 != 0)))) {
            pfVar12 = (float *)(iVar10 + 0x28);
          }
          iVar10 = DAT_0087af5c;
          puVar8 = PTR_DAT_00802c54;
          if ((pfVar12 == (float *)0x0) || (*pfVar12 == 2e+06)) {
            param_1 = *(float *)((int)fVar9 + 0x21c);
          }
          else {
            param_1 = *pfVar12;
          }
          if (((*(float *)((int)fVar9 + 0x220) != 2e+06) &&
              (param_1 < *(float *)((int)fVar9 + 0x220))) &&
             ((cVar11 = *(char *)((int)fVar9 + 0x283), cVar11 != '\x05' &&
              ((cVar11 != '\a' && (cVar11 != '\x10')))))) {
            param_1 = *(float *)((int)fVar9 + 0x220);
          }
          fVar15 = (float10)FUN_00498320(fVar9);
          local_8 = (float)fVar15;
          local_18 = *(int *)((int)fVar9 + 0x54);
          fVar1 = local_8 + param_1 + local_4;
          param_3 = local_8 + param_3;
          local_4 = *(float *)((int)fVar9 + 0x1ac);
          if (((*(byte *)(*(int *)(local_18 + 0x24) + 0x94) & 0x20) == 0) &&
             ((((iVar10 == 0 || (*(int *)(puVar8 + 300) != iVar10)) &&
               (1.0 < _DAT_00924fdc != (_DAT_00924fdc == 1.0))) && (param_3 * 5.0 + fVar1 < local_4)
              ))) goto LAB_004ac2a0;
          *(float *)((int)fVar9 + 0xd7c) = param_3;
          if ((DAT_0087af5c == 0) ||
             (param_1 = _DAT_007fb0e0, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
            param_1 = *(float *)(*(int *)(local_18 + 0x24) + 0x24);
          }
          if ((*(char *)((int)fVar9 + 0x288) != '\0') || (_DAT_00925018 < 0.016666668)) {
            param_1 = (local_4 - (param_3 + fVar1)) * param_1;
            goto LAB_004ac1af;
          }
          param_1 = (param_1 * (local_4 - (fVar1 + param_3))) / (_DAT_00925018 * 180.0);
          uVar5 = param_4;
        }
LAB_004ac1bd:
        fVar15 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar9 + 0x6c),param_1,uVar5);
        goto LAB_004ac1da;
      }
LAB_004ac2a0:
      cVar11 = *(char *)((int)fVar9 + 0x7b5);
      fVar1 = *(float *)(*(int *)(local_18 + 0x24) + 0x24);
      param_1 = fVar1;
      if (cVar11 == '+') {
        cVar2 = *(char *)((int)fVar9 + 0xe37);
        if (cVar2 == '\x03') {
          param_1 = -fVar1;
        }
        else {
          param_1 = _DAT_007fc004;
          if ((cVar2 != '\x02') && (param_1 = fVar1, cVar2 == '\x04')) {
            param_1 = -2.0;
          }
        }
      }
    }
LAB_004ac2e5:
    fVar15 = (float10)0;
    if ((((((*(char *)((int)fVar9 + 0x281) == '\0') && (*(char *)((int)fVar9 + 0x1078) != '\0')) &&
          (local_4 = (*(float *)((int)fVar9 + 0xff4) - *(float *)((int)fVar9 + 0xff0)) * 0.5 *
                     *(float *)((int)fVar9 + 0xa8) +
                     (*(float *)((int)fVar9 + 0x60) -
                     *(float *)((int)fVar9 + 0xff0) * *(float *)((int)fVar9 + 0xa8)),
          *(float *)((int)fVar9 + 0x6ac) < local_4)) &&
         (((*(char *)((int)fVar9 + 0x39) == '\0' &&
           (*(int *)(*(int *)(*(int *)((int)fVar9 + 0x50) + 0xc) + *(short *)((int)fVar9 + 0x3e) * 4
                    ) != 0)) &&
          (iVar10 = FUN_004982f0(), fVar15 = extraout_ST0, cVar11 = extraout_DL, iVar10 != 0)))) ||
        (fVar15 < (float10)*(float *)((int)fVar9 + 0x103c))) &&
       (param_1 = param_1 + param_1, -5.0 < param_1)) {
      param_1 = -5.0;
    }
  }
  else {
    param_1 = *pfVar13;
  }
  fVar1 = *(float *)((int)fVar9 + 0x6c);
  if (((*(char *)((int)fVar9 + 0x281) == '\0') || (*(char *)((int)fVar9 + 0x281) == '\x02')) ||
     (*(short *)((int)fVar9 + 0x1064) == DAT_007f191c)) {
    *(float *)((int)fVar9 + 0x6c) = _DAT_00925018 * param_1 + *(float *)((int)fVar9 + 0x6c);
  }
  if (cVar11 == '+') {
    if (*(char *)((int)fVar9 + 0xe37) == '\x03') {
      if (0.1 <= *(float *)((int)fVar9 + 0x6c)) goto LAB_004ac3f9;
      uVar5 = 0x3dcccccd;
    }
    else {
      if (*(float *)((int)fVar9 + 0x6c) <= -0.1) goto LAB_004ac3f9;
      uVar5 = 0xbdcccccd;
    }
    *(undefined4 *)((int)fVar9 + 0x6c) = uVar5;
  }
LAB_004ac3f9:
  if (((!bVar7) || ((float10)fVar1 <= fVar15)) || (fVar15 < (float10)*(float *)((int)fVar9 + 0x6c)))
  {
    return;
  }
  if ((float10)*(float *)(*(int *)(local_18 + 0x24) + 0x48) <= fVar15) {
    *(undefined1 *)((int)fVar9 + 0xe32) = 3;
    return;
  }
  *(float *)((int)fVar9 + 0x6c) = (float)fVar15;
  fVar1 = *(float *)(*(int *)(local_18 + 0x24) + 0x48);
  *(float *)((int)fVar9 + 0xd64) = fVar1;
  if ((*(byte *)((int)fVar9 + 0x1fc) & 0x80) != 0) {
    *(undefined1 *)((int)fVar9 + 0xe32) = 2;
    return;
  }
  *(float *)((int)fVar9 + 0xd64) = fVar1 * 1.5;
  *(undefined1 *)((int)fVar9 + 0xe32) = 2;
  return;
}

