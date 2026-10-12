/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7043fc; label: UnDecorator::getExtendedDataIndirectType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getExtendedDataIndirectType(char &,bool &,int)
   
   Library: Visual Studio 2005 Release */

char * __cdecl UnDecorator::getExtendedDataIndirectType(char *param_1,bool *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  DName *pDVar3;
  char *pcVar4;
  int in_stack_00000010;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  DName local_1c [8];
  DName local_14 [8];
  undefined4 local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = local_8 & 0xfffff000;
  pcVar4 = (char *)((int)DAT_0297cb78 + 1);
  iVar2 = (int)*pcVar4;
  if (iVar2 == 0x41) {
    DAT_0297cb78 = pcVar4;
    if (in_stack_00000010 == 0) {
      *param_2 = (bool)(((*param_2 != true) - 1U & 199) + 0x5e);
    }
  }
  else if (iVar2 == 0x42) {
    DAT_0297cb78 = pcVar4;
    *(undefined1 *)param_3 = 1;
    DName::operator=((DName *)&local_c,'>');
  }
  else {
    if (iVar2 != 0x43) {
      uVar1 = (iVar2 + -0x30) * 0x10 + -0x30 + (int)*(char *)((int)DAT_0297cb78 + 2);
      DAT_0297cb78 = (char *)((int)DAT_0297cb78 + 3);
      if (1 < uVar1) {
        DName::operator=((DName *)&local_c,',');
        DName::DName(local_14,(ulonglong)uVar1);
        pDVar3 = (DName *)DName::operator+((DName *)&local_c,local_1c);
        DName::operator=((DName *)&local_c,pDVar3);
      }
      pDVar3 = (DName *)DName::operator+((DName *)&local_c,(char)local_24);
      DName::operator=((DName *)&local_c,pDVar3);
      if (*DAT_0297cb78 == '$') {
        DAT_0297cb78 = DAT_0297cb78 + 1;
      }
      else {
        pDVar3 = (DName *)DName::operator+((DName *)&local_c,(char)local_2c);
        DName::operator=((DName *)&local_c,pDVar3);
      }
      DAT_0297cb78 = DAT_0297cb78 + 1;
      local_8 = local_8 | 0x400;
      DName::DName((DName *)param_1,(DName *)&local_c);
      return param_1;
    }
    DAT_0297cb78 = pcVar4;
    *param_2 = true;
  }
  DAT_0297cb78 = DAT_0297cb78 + 1;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffff000;
  return param_1;
}

