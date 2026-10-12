/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704e87; label: UnDecorator::getOperatorName
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getOperatorName(bool,bool *)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getOperatorName(bool param_1,bool *param_2)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  DName *pDVar5;
  DName *this;
  DName *pDVar6;
  DName *extraout_ECX;
  undefined3 in_stack_00000005;
  undefined1 *in_stack_0000000c;
  char *pcVar7;
  DNameStatus DVar8;
  undefined1 local_a4 [24];
  undefined1 local_8c [8];
  undefined1 local_84 [16];
  undefined1 local_74 [8];
  undefined1 local_6c [8];
  DName local_64 [16];
  undefined1 local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [8];
  undefined1 local_3c [16];
  undefined1 local_2c [8];
  char local_24 [8];
  undefined4 local_1c;
  uint local_18;
  DName local_14 [4];
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  cVar2 = *DAT_0297cb78;
  local_8 = local_8 & 0xfffff000;
  local_18 = local_18 & 0xfffff000;
  bVar1 = false;
  pcVar3 = DAT_0297cb78 + 1;
  local_c = 0;
  local_1c = 0;
  if (cVar2 < 'B') {
    if (cVar2 == 'A') {
LAB_007053c2:
      cVar2 = *DAT_0297cb78;
      DAT_0297cb78 = pcVar3;
      DName::operator=((DName *)&local_c,*(char **)(&DAT_00780c84 + cVar2 * 4));
      pcVar3 = DAT_0297cb78;
      if (bVar1) {
        iVar4 = DName::isEmpty((DName *)&local_c);
        if (iVar4 == 0) {
          local_8 = local_8 | 0x20;
        }
      }
      else {
LAB_00704ef8:
        DAT_0297cb78 = pcVar3;
        iVar4 = DName::isEmpty((DName *)&local_c);
        if (iVar4 == 0) {
          pDVar5 = (DName *)operator+(local_24,(DName *)"operator");
          DName::operator=((DName *)&local_c,pDVar5);
        }
      }
LAB_00704f21:
      pDVar5 = (DName *)&local_c;
LAB_00704f24:
      DName::DName(_param_1,pDVar5);
      return _param_1;
    }
    if (cVar2 == '\0') goto LAB_0070500a;
    if ('/' < cVar2) {
      if (cVar2 < '2') {
        local_1c = 0;
        if ((char)param_2 != '\0') {
          DAT_0297cb78 = pcVar3;
          getTemplateArgumentList();
          pDVar5 = (DName *)operator+((char)local_a4,(DName *)0x3c);
          DName::operator+=((DName *)&local_1c,pDVar5);
          cVar2 = DName::getLastChar((DName *)&local_1c);
          if (cVar2 == '>') {
            DName::operator+=((DName *)&local_1c,' ');
          }
          DName::operator+=((DName *)&local_1c,'>');
          if (in_stack_0000000c != (undefined1 *)0x0) {
            *in_stack_0000000c = 1;
          }
          if (*DAT_0297cb78 == '\0') {
            pDVar5 = (DName *)&local_1c;
            goto LAB_00704f24;
          }
          pcVar3 = DAT_0297cb78 + 1;
        }
        DAT_0297cb78 = pcVar3;
        pDVar5 = (DName *)getZName(SUB41(local_3c,0));
        DName::operator=((DName *)&local_c,pDVar5);
        DAT_0297cb78 = pcVar3;
        iVar4 = DName::isEmpty((DName *)&local_c);
        if ((iVar4 == 0) && (pcVar3[-1] == '1')) {
          pDVar5 = (DName *)operator+((char)local_8c,(DName *)0x7e);
          DName::operator=((DName *)&local_c,pDVar5);
        }
        iVar4 = DName::isEmpty((DName *)&local_1c);
        if (iVar4 == 0) {
          DName::operator+=((DName *)&local_c,extraout_ECX);
        }
        goto LAB_00704f21;
      }
      if (cVar2 < ':') {
        pcVar7 = *(char **)(&DAT_00780ca0 + *DAT_0297cb78 * 4);
        DAT_0297cb78 = pcVar3;
        goto LAB_00704ef0;
      }
    }
  }
  else {
    if (cVar2 == 'B') {
      bVar1 = true;
      goto LAB_007053c2;
    }
    if (cVar2 < 'C') goto LAB_00705111;
    if (cVar2 < '[') goto LAB_007053c2;
    if (cVar2 == '_') {
      cVar2 = *pcVar3;
      pcVar3 = DAT_0297cb78 + 2;
      if (cVar2 < 'P') {
        if ('C' < cVar2) {
LAB_0070539f:
          pcVar7 = *(char **)("__cdecl" + DAT_0297cb78[1] * 4);
          DAT_0297cb78 = pcVar3;
LAB_00705088:
          DName::DName(_param_1,pcVar7);
          return _param_1;
        }
        if (cVar2 < ':') {
          if (cVar2 == '9') {
            pcVar7 = DAT_0297cb78 + 1;
            DAT_0297cb78 = pcVar3;
            DName::DName(local_14,(&PTR_s___pascal_00780d30)[*pcVar7]);
            local_10 = local_10 | 0x800;
LAB_007050bf:
            pDVar5 = local_14;
            goto LAB_00704f24;
          }
          if (cVar2 == '\0') {
LAB_0070500a:
            pcVar3 = pcVar3 + -1;
LAB_00705010:
            DAT_0297cb78 = pcVar3;
            DVar8 = 2;
            goto LAB_00705012;
          }
          if ('/' < cVar2) {
            if (cVar2 < '7') {
              pcVar7 = (&PTR_s___pascal_00780d30)[DAT_0297cb78[1]];
              DAT_0297cb78 = pcVar3;
              goto LAB_00704ef0;
            }
            if (cVar2 < '9') {
              pcVar7 = (&PTR_s___pascal_00780d30)[DAT_0297cb78[1]];
              DAT_0297cb78 = pcVar3;
              goto LAB_00705088;
            }
          }
        }
        else if (cVar2 == '?') {
          cVar2 = *pcVar3;
          pcVar3 = DAT_0297cb78 + 3;
          if (cVar2 == '\0') goto LAB_0070500a;
          if (cVar2 == '0') {
            pcVar7 = "`anonymous namespace\'";
            DAT_0297cb78 = pcVar3;
LAB_007050e6:
            getStringEncoding((char *)local_14,(int)pcVar7);
            local_10 = local_10 | 0x100;
            goto LAB_007050bf;
          }
        }
        else if ('@' < cVar2) {
          if (cVar2 < 'C') goto LAB_0070539f;
          if (cVar2 == 'C') {
            pcVar7 = "`string\'";
            DAT_0297cb78 = pcVar3;
            goto LAB_007050e6;
          }
        }
      }
      else if (cVar2 < 'U') {
        if ('R' < cVar2) goto LAB_0070539f;
        pDVar5 = _param_1;
        if (cVar2 == 'P') {
          pcVar7 = DAT_0297cb78 + 1;
          DAT_0297cb78 = pcVar3;
          DName::operator=((DName *)&local_c,*(char **)("__cdecl" + *pcVar7 * 4));
          pDVar6 = (DName *)getOperatorName(SUB41(local_84,0),(bool *)0x0);
          DName::operator=((DName *)&local_1c,pDVar6);
          iVar4 = DName::isEmpty((DName *)&local_1c);
          if ((iVar4 != 0) || (pcVar3 = DAT_0297cb78, (local_18 & 0x40) == 0)) {
LAB_00705193:
            pDVar6 = (DName *)&local_c;
LAB_0070519d:
            DName::operator+(pDVar6,pDVar5);
            return _param_1;
          }
        }
        else {
          if (cVar2 == 'Q') goto LAB_00704ef8;
          if (cVar2 == 'R') {
            pcVar7 = DAT_0297cb78 + 1;
            DAT_0297cb78 = pcVar3;
            DName::operator=((DName *)&local_c,*(char **)("__cdecl" + *pcVar7 * 4));
            DName::operator=((DName *)&local_1c,*(char **)("operator" + *DAT_0297cb78 * 4 + 8));
            pcVar3 = DAT_0297cb78;
            iVar4 = (int)*DAT_0297cb78;
            DAT_0297cb78 = DAT_0297cb78 + 1;
            if (iVar4 == 0x30) {
              getDataType(local_14);
              pDVar6 = local_64;
              this = (DName *)DName::operator+(local_14,(char)local_74);
              pDVar6 = (DName *)DName::operator+(this,pDVar6);
              goto LAB_0070519d;
            }
            if (iVar4 == 0x31) {
              DName::operator+((DName *)&local_c,local_14);
              cVar2 = (char)local_4c;
              pDVar5 = (DName *)getSignedDimension();
              pDVar5 = (DName *)DName::operator+(pDVar5,cVar2);
              DName::operator+=(local_14,pDVar5);
              cVar2 = (char)local_2c;
              pDVar5 = (DName *)getSignedDimension();
              pDVar5 = (DName *)DName::operator+(pDVar5,cVar2);
              DName::operator+=(local_14,pDVar5);
              cVar2 = (char)local_6c;
              pDVar5 = (DName *)getSignedDimension();
              pDVar5 = (DName *)DName::operator+(pDVar5,cVar2);
              DName::operator+=(local_14,pDVar5);
              cVar2 = (char)local_44;
              pDVar5 = (DName *)getDimension(SUB41(local_54,0));
              pDVar5 = (DName *)DName::operator+(pDVar5,cVar2);
              DName::operator+=(local_14,pDVar5);
              DName::operator+(local_14,param_1);
              return _param_1;
            }
            if (iVar4 - 0x32U < 3) goto LAB_00705193;
            goto LAB_00705010;
          }
        }
      }
      else if ('T' < cVar2) {
        if (cVar2 < 'W') {
          pcVar7 = *(char **)("__cdecl" + DAT_0297cb78[1] * 4);
          DAT_0297cb78 = pcVar3;
LAB_00704ef0:
          DName::operator=((DName *)&local_c,pcVar7);
          pcVar3 = DAT_0297cb78;
          goto LAB_00704ef8;
        }
        if ('W' < cVar2) {
          if (cVar2 < 'Z') goto LAB_0070539f;
          if (cVar2 == '_') {
            cVar2 = *pcVar3;
            pcVar3 = DAT_0297cb78 + 3;
            if ('@' < cVar2) {
              if ('D' < cVar2) {
                if (cVar2 < 'G') {
                  pcVar7 = DAT_0297cb78 + 2;
                  DAT_0297cb78 = pcVar3;
                  DName::DName(local_14,(&PTR_DAT_00780d78)[*pcVar7]);
                  if (*DAT_0297cb78 == '?') {
                    pDVar5 = (DName *)getDecoratedName();
                    DName::operator+=(local_14,pDVar5);
                    if (*DAT_0297cb78 == '@') {
                      DAT_0297cb78 = DAT_0297cb78 + 1;
                    }
                  }
                  else {
                    pDVar5 = (DName *)getSymbolName();
                    DName::operator+=(local_14,pDVar5);
                  }
                  DName::operator+=(local_14,"\'\'");
                  goto LAB_007050bf;
                }
                if ('J' < cVar2) goto LAB_00705111;
              }
              pcVar7 = (&PTR_DAT_00780d78)[DAT_0297cb78[2]];
              DAT_0297cb78 = pcVar3;
              goto LAB_00705088;
            }
          }
        }
      }
    }
  }
LAB_00705111:
  DAT_0297cb78 = pcVar3;
  DVar8 = 1;
LAB_00705012:
  DName::DName(_param_1,DVar8);
  return _param_1;
}

