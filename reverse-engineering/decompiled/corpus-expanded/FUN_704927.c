/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x704927; label: UnDecorator::getTemplateConstant
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getTemplateConstant(void)
   
   Library: Visual Studio 2005 Release */

void __cdecl UnDecorator::getTemplateConstant(void)

{
  int iVar1;
  char *pcVar2;
  DName *pDVar3;
  long lVar4;
  DName *in_stack_00000004;
  char cVar5;
  char *pcVar6;
  DNameStatus DVar7;
  DName local_d4 [8];
  char local_cc [16];
  DName local_bc [16];
  undefined1 local_ac [32];
  char local_8c [8];
  DName local_84 [8];
  char local_7c;
  char local_7b;
  char local_7a;
  undefined1 local_78 [96];
  char local_18 [8];
  DName local_10 [8];
  uint local_8;
  
  pcVar2 = DAT_0297cb78;
  local_8 = DAT_00829570 ^ (uint)local_78;
  cVar5 = *DAT_0297cb78;
  DAT_0297cb78 = DAT_0297cb78 + 1;
  if (cVar5 < 'E') {
    if (cVar5 == 'D') {
LAB_00704ab6:
      getSignedDimension();
      if (((ushort)DAT_0297cb88 & 0x4000) != 0) {
        DName::getString(local_84,local_18,0x10);
        lVar4 = _atol(local_18);
        pcVar2 = (char *)(*DAT_0297cb8c)(lVar4);
        if (pcVar2 != (char *)0x0) {
LAB_00704a2a:
          DName::DName(in_stack_00000004,pcVar2);
          goto LAB_00704bce;
        }
      }
      if (cVar5 == 'D') {
        pcVar6 = "`template-parameter";
        pcVar2 = local_8c;
      }
      else {
        pcVar6 = "`non-type-template-parameter";
        pcVar2 = local_cc;
      }
      pDVar3 = (DName *)operator+(pcVar2,(DName *)pcVar6);
      DName::operator+(pDVar3,(char *)in_stack_00000004);
      goto LAB_00704bce;
    }
    if (cVar5 != '\0') {
      if (cVar5 == '0') {
        getSignedDimension();
        goto LAB_00704bce;
      }
      if (cVar5 == '1') {
        if (*DAT_0297cb78 == '@') {
          DAT_0297cb78 = pcVar2 + 2;
          pcVar2 = "NULL";
          goto LAB_00704a2a;
        }
        getDecoratedName();
        pDVar3 = (DName *)DName::DName(local_bc,"&");
LAB_00704a09:
        DName::operator+(pDVar3,in_stack_00000004);
        goto LAB_00704bce;
      }
      if (cVar5 == '2') {
        getSignedDimension();
        getSignedDimension();
        iVar1 = DName::isValid(local_84);
        pcVar2 = DAT_0297cb78;
        if ((iVar1 == 0) || (iVar1 = DName::isValid(local_10), pcVar2 = DAT_0297cb78, iVar1 == 0))
        goto LAB_00704a62;
        pcVar2 = DName::getString(local_84,&local_7b,100);
        if (pcVar2 != (char *)0x0) {
          local_7c = local_7b;
          if (local_7b == '-') {
            local_7b = local_7a;
            local_7a = '.';
          }
          else {
            local_7b = '.';
          }
          cVar5 = (char)local_ac;
          pDVar3 = (DName *)DName::DName(local_d4,&local_7c);
          pDVar3 = (DName *)DName::operator+(pDVar3,cVar5);
          goto LAB_00704a09;
        }
      }
      goto LAB_007049c3;
    }
LAB_00704a62:
    DAT_0297cb78 = pcVar2;
    DVar7 = 2;
  }
  else {
    if (cVar5 == 'E') {
      getDecoratedName();
      goto LAB_00704bce;
    }
    if ('E' < cVar5) {
      if (cVar5 < 'K') {
        DName::DName(local_84,'{');
        if (('G' < cVar5) && (cVar5 < 'K')) {
          pDVar3 = (DName *)getDecoratedName();
          DName::operator+=(local_84,pDVar3);
          DName::operator+=(local_84,',');
        }
        if (cVar5 == 'F') {
LAB_00704b8a:
          pDVar3 = (DName *)getSignedDimension();
          DName::operator+=(local_84,pDVar3);
          DName::operator+=(local_84,',');
LAB_00704ba7:
          pDVar3 = (DName *)getSignedDimension();
          DName::operator+=(local_84,pDVar3);
        }
        else {
          if (cVar5 == 'G') {
LAB_00704b6d:
            pDVar3 = (DName *)getSignedDimension();
            DName::operator+=(local_84,pDVar3);
            DName::operator+=(local_84,',');
            goto LAB_00704b8a;
          }
          if (cVar5 == 'H') goto LAB_00704ba7;
          if (cVar5 == 'I') goto LAB_00704b8a;
          if (cVar5 == 'J') goto LAB_00704b6d;
        }
        DName::operator+(local_84,(char)in_stack_00000004);
        goto LAB_00704bce;
      }
      if (cVar5 == 'Q') goto LAB_00704ab6;
      if (cVar5 == 'R') {
        getZName(SUB41(local_10,0));
        getSignedDimension();
        DName::DName(in_stack_00000004,local_10);
        goto LAB_00704bce;
      }
    }
LAB_007049c3:
    DVar7 = 1;
  }
  DName::DName(in_stack_00000004,DVar7);
LAB_00704bce:
  __security_check_cookie(local_8 ^ (uint)local_78);
  return;
}

