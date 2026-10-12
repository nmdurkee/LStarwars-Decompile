/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x707abf; label: UnDecorator::getDataType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getDataType(class DName *)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getDataType(DName *param_1)

{
  char cVar1;
  int iVar2;
  DName *pDVar3;
  DName *in_stack_00000008;
  DName local_1c [8];
  undefined4 local_14;
  uint local_10;
  DName local_c [8];
  
  DName::DName(local_c,in_stack_00000008);
  cVar1 = *DAT_0297cb78;
  if (cVar1 == '\0') {
    operator+((DNameStatus)param_1,(DName *)0x2);
  }
  else {
    if (cVar1 == '?') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      local_10 = local_10 & 0xfffff000;
      local_14 = 0;
      pDVar3 = (DName *)getDataIndirectType(local_1c,(char)local_c,(DName *)0x0,(int)&local_14);
      DName::operator=(local_c,pDVar3);
    }
    else if (cVar1 == 'X') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      iVar2 = DName::isEmpty(local_c);
      if (iVar2 == 0) {
        operator+((char *)param_1,(DName *)"void ");
        return param_1;
      }
      DName::DName(param_1,"void");
      return param_1;
    }
    getPrimaryDataType(param_1);
  }
  return param_1;
}

