/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x707981; label: UnDecorator::getPrimaryDataType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getPrimaryDataType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getPrimaryDataType(DName *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  DName *in_stack_00000008;
  DName local_1c [8];
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  cVar1 = *DAT_0297cb78;
  local_8 = local_8 & 0xfffff000;
  local_c = 0;
  pcVar4 = DAT_0297cb78;
  if (cVar1 != '\0') {
    if (cVar1 != '$') {
      if (cVar1 != 'A') {
        if (cVar1 != 'B') {
          FUN_007075fa(param_1);
          return param_1;
        }
        DName::operator=((DName *)&local_c,"volatile");
        iVar2 = DName::isEmpty(in_stack_00000008);
        if (iVar2 == 0) {
          DName::operator+=((DName *)&local_c,' ');
        }
      }
      DName::DName((DName *)&local_14,in_stack_00000008);
      DAT_0297cb78 = DAT_0297cb78 + 1;
      local_10 = local_10 | 0x10;
      getPtrRefType(param_1,(DName *)&local_c,(char)&local_14);
      return param_1;
    }
    if (DAT_0297cb78[1] == '$') {
      pcVar4 = DAT_0297cb78 + 2;
      cVar1 = *pcVar4;
      if (cVar1 != '\0') {
        if (cVar1 == 'A') {
          DAT_0297cb78 = DAT_0297cb78 + 3;
          getFunctionIndirectType(param_1);
          return param_1;
        }
        if (cVar1 == 'B') {
          DAT_0297cb78 = DAT_0297cb78 + 3;
          getPtrRefDataType(param_1,(int)in_stack_00000008);
          return param_1;
        }
        if (cVar1 == 'C') {
          local_10 = local_10 & 0xfffff000;
          DAT_0297cb78 = DAT_0297cb78 + 3;
          local_14 = 0;
          uVar3 = getDataIndirectType(local_1c,(char)in_stack_00000008,(DName *)0x0,(int)&local_14);
          FUN_007075fa(param_1,uVar3);
          return param_1;
        }
        goto LAB_00707a26;
      }
    }
    else if (DAT_0297cb78[1] != '\0') {
LAB_00707a26:
      DAT_0297cb78 = pcVar4;
      DName::DName(param_1,1);
      return param_1;
    }
  }
  DAT_0297cb78 = pcVar4;
  operator+((DNameStatus)param_1,(DName *)0x2);
  return param_1;
}

