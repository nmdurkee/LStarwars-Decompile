/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7046e7; label: UnDecorator::getVfTableType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getVfTableType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getVfTableType(DName *param_1)

{
  int iVar1;
  DName *this;
  DName *pDVar2;
  DName *this_00;
  DName *extraout_ECX;
  DName *extraout_ECX_00;
  DName *this_01;
  char *extraout_EDX;
  DName *in_stack_00000008;
  char cVar3;
  char *pcVar4;
  undefined1 local_1c [8];
  DName local_14 [8];
  DName local_c [8];
  
  DName::DName(param_1,in_stack_00000008);
  iVar1 = DName::isValid(param_1);
  if ((iVar1 == 0) || (*DAT_0297cb78 == '\0')) {
    iVar1 = DName::isValid(this_00);
    if (iVar1 != 0) {
      pDVar2 = (DName *)operator+((DNameStatus)local_1c,(DName *)0x2);
      DName::operator=(param_1,pDVar2);
    }
  }
  else {
    getDataIndirectType();
    pDVar2 = local_14;
    this = (DName *)DName::operator+(local_c,(char)local_1c);
    pDVar2 = (DName *)DName::operator+(this,pDVar2);
    DName::operator=(param_1,pDVar2);
    iVar1 = DName::isValid(param_1);
    if (iVar1 != 0) {
      if (*DAT_0297cb78 != '@') {
        pcVar4 = "{for ";
        pDVar2 = extraout_ECX;
        do {
          DName::operator+=(pDVar2,pcVar4);
          do {
            iVar1 = DName::isValid(param_1);
            if (((iVar1 == 0) || (*DAT_0297cb78 == '\0')) || (*DAT_0297cb78 == '@')) {
              iVar1 = DName::isValid(param_1);
              if (iVar1 != 0) {
                if (*DAT_0297cb78 == '\0') {
                  DName::operator+=(this_01,2);
                }
                DName::operator+=(param_1,'}');
              }
              if (*DAT_0297cb78 != '@') {
                return param_1;
              }
              goto LAB_0070480a;
            }
            cVar3 = (char)local_1c;
            getScope();
            pDVar2 = (DName *)operator+((char)local_c,(DName *)0x60);
            pDVar2 = (DName *)DName::operator+(pDVar2,cVar3);
            DName::operator+=(param_1,pDVar2);
            if (*DAT_0297cb78 == '@') {
              DAT_0297cb78 = DAT_0297cb78 + 1;
            }
            iVar1 = DName::isValid(param_1);
          } while ((iVar1 == 0) || (*extraout_EDX == '@'));
          pcVar4 = "s ";
          pDVar2 = extraout_ECX_00;
        } while( true );
      }
LAB_0070480a:
      DAT_0297cb78 = DAT_0297cb78 + 1;
    }
  }
  return param_1;
}

