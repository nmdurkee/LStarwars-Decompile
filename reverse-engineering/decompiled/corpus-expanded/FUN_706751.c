/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x706751; label: UnDecorator::getScope
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getScope(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getScope(void)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  DName *pDVar4;
  DName *pDVar5;
  DName *this;
  char *pcVar6;
  DName *this_00;
  DName *in_stack_00000004;
  char cVar7;
  char local_94 [8];
  DName local_8c [8];
  DName local_84 [8];
  undefined1 local_7c [8];
  undefined1 local_74 [8];
  DName local_6c [8];
  DName local_64 [8];
  char local_5c [8];
  DName local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [16];
  undefined1 local_34 [8];
  undefined1 local_2c [8];
  DName local_24 [8];
  DName local_1c [8];
  DName local_14 [8];
  DName local_c [8];
  
  *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffff000;
  *(undefined4 *)in_stack_00000004 = 0;
  bVar1 = false;
  if ((*(uint *)(in_stack_00000004 + 4) & 0xf) == 0) {
    do {
      if ((*DAT_0297cb78 == '\0') || (*DAT_0297cb78 == '@')) break;
      if ((DAT_0297cb90 != '\0') && (DAT_0297cb91 == '\0')) {
        return in_stack_00000004;
      }
      iVar3 = DName::isEmpty(in_stack_00000004);
      if (iVar3 == 0) {
        pDVar4 = (DName *)operator+(local_94,(DName *)&DAT_00781014);
        DName::operator=(in_stack_00000004,pDVar4);
        if (bVar1) {
          pDVar4 = (DName *)operator+((char)local_7c,(DName *)0x5b);
          DName::operator=(in_stack_00000004,pDVar4);
          bVar1 = false;
        }
      }
      if (*DAT_0297cb78 == '?') {
        pcVar6 = DAT_0297cb78 + 1;
        cVar7 = *pcVar6;
        if (cVar7 == '$') {
          pDVar4 = local_6c;
          uVar2 = SUB41(local_14,0);
          goto LAB_00706948;
        }
        if (cVar7 != '%') {
          if (cVar7 != '?') {
            if (cVar7 == 'A') goto LAB_007068f0;
            if (cVar7 != 'I') {
              pDVar4 = local_8c;
              DAT_0297cb78 = pcVar6;
              pDVar5 = (DName *)getLexicalFrame();
              goto LAB_00706952;
            }
            pDVar4 = local_84;
            cVar7 = (char)local_44;
            DAT_0297cb78 = DAT_0297cb78 + 2;
            pDVar5 = (DName *)getZName(SUB41(local_74,0));
            pDVar5 = (DName *)DName::operator+(pDVar5,cVar7);
            pDVar4 = (DName *)DName::operator+(pDVar5,pDVar4);
            DName::operator=(in_stack_00000004,pDVar4);
            bVar1 = true;
            goto LAB_00706961;
          }
          if ((DAT_0297cb78[2] == '_') && (DAT_0297cb78[3] == '?')) {
            pDVar4 = local_54;
            DAT_0297cb78 = DAT_0297cb78 + 2;
            pDVar5 = (DName *)getOperatorName(SUB41(local_2c,0),(bool *)0x0);
            pDVar4 = (DName *)DName::operator+(pDVar5,pDVar4);
            DName::operator=(in_stack_00000004,pDVar4);
            if (*DAT_0297cb78 == '@') {
              DAT_0297cb78 = DAT_0297cb78 + 1;
            }
            goto LAB_00706961;
          }
          pDVar4 = local_64;
          cVar7 = (char)local_34;
          DAT_0297cb78 = pcVar6;
          getDecoratedName();
          pDVar5 = (DName *)operator+((char)local_4c,(DName *)0x60);
          pDVar5 = (DName *)DName::operator+(pDVar5,cVar7);
          goto LAB_00706952;
        }
LAB_007068f0:
        DAT_0297cb78 = pcVar6;
        DName::DName(local_c,&DAT_0297cb78,'@');
        pDVar4 = (DName *)operator+(local_5c,(DName *)"`anonymous namespace\'");
        DName::operator=(in_stack_00000004,pDVar4);
        if (*(int *)DAT_0297cb70 != 9) {
          Replicator::operator+=(DAT_0297cb70,local_c);
        }
      }
      else {
        pDVar4 = local_24;
        uVar2 = SUB41(local_1c,0);
LAB_00706948:
        pDVar5 = (DName *)getZName((bool)uVar2);
LAB_00706952:
        pDVar4 = (DName *)DName::operator+(pDVar5,pDVar4);
        DName::operator=(in_stack_00000004,pDVar4);
      }
LAB_00706961:
    } while (((byte)in_stack_00000004[4] & 0xf) == 0);
  }
  if (*DAT_0297cb78 == '\0') {
    iVar3 = DName::isEmpty(in_stack_00000004);
    if (iVar3 == 0) {
      pDVar4 = local_1c;
      pDVar5 = local_24;
      this = (DName *)DName::DName(local_14,2);
      pDVar5 = (DName *)DName::operator+(this,(char *)pDVar5);
      pDVar4 = (DName *)DName::operator+(pDVar5,pDVar4);
      DName::operator=(in_stack_00000004,pDVar4);
    }
    else {
      DName::operator=(this_00,2);
    }
  }
  else if (*DAT_0297cb78 != '@') {
    *(undefined4 *)in_stack_00000004 = 0;
    if (((byte)*(uint *)(in_stack_00000004 + 4) & 0xf) != 3) {
      *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffffff1 | 1;
    }
  }
  return in_stack_00000004;
}

