/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x70734d; label: UnDecorator::getPtrRefType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getPtrRefType(class DName const &,class DName
   const &,char)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getPtrRefType(DName *param_1,DName *param_2,char param_3)

{
  char cVar1;
  int iVar2;
  DName *extraout_ECX;
  undefined3 in_stack_0000000d;
  DName *in_stack_00000010;
  DName local_c [8];
  
  cVar1 = *DAT_0297cb78;
  if (cVar1 == '\0') {
    DName::DName(local_c,2);
    DName::operator+=(local_c,(char)in_stack_00000010);
    iVar2 = DName::isEmpty(param_2);
    if (iVar2 == 0) {
      DName::operator+=(local_c,extraout_ECX);
    }
    iVar2 = DName::isEmpty(_param_3);
    if (iVar2 == 0) {
      iVar2 = DName::isEmpty(param_2);
      if (iVar2 == 0) {
        DName::operator+=(local_c,' ');
      }
      DName::operator+=(local_c,_param_3);
    }
    DName::DName(param_1,local_c);
  }
  else if (((cVar1 < '6') || ('9' < cVar1)) && (cVar1 != '_')) {
    getDataIndirectType(local_c,param_3,in_stack_00000010,(int)param_2);
    getPtrRefDataType(param_1,(int)local_c);
  }
  else {
    DName::DName(local_c,(char)in_stack_00000010);
    iVar2 = DName::isEmpty(param_2);
    if (iVar2 == 0) {
      iVar2 = DName::isEmpty(_param_3);
      if ((iVar2 != 0) || (((byte)_param_3[4] & 0x10) == 0)) {
        DName::operator+=(local_c,param_2);
      }
    }
    iVar2 = DName::isEmpty(_param_3);
    if (iVar2 == 0) {
      DName::operator+=(local_c,_param_3);
    }
    getFunctionIndirectType(param_1);
  }
  return param_1;
}

