/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704be2; label: UnDecorator::getPtrRefDataType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getPtrRefDataType(class DName const &,int)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getPtrRefDataType(DName *param_1,int param_2)

{
  int iVar1;
  DName *pDVar2;
  int in_stack_0000000c;
  char *pcVar3;
  char local_14 [8];
  DName local_c [8];
  
  if (*DAT_0297cb78 == '\0') {
    operator+((DNameStatus)param_1,(DName *)0x2);
    return param_1;
  }
  if ((in_stack_0000000c != 0) && (*DAT_0297cb78 == 'X')) {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    iVar1 = DName::isEmpty((DName *)param_2);
    if (iVar1 == 0) {
      operator+((char *)param_1,(DName *)"void ");
      return param_1;
    }
    DName::DName(param_1,"void");
    return param_1;
  }
  if (*DAT_0297cb78 == 'Y') {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    getArrayType(param_1);
    return param_1;
  }
  FUN_007075fa(local_c,param_2);
  if ((*(uint *)(param_2 + 4) & 0x400) == 0) {
    if ((*(uint *)(param_2 + 4) & 0x200) == 0) goto LAB_00704c98;
    pcVar3 = "cli::pin_ptr<";
  }
  else {
    pcVar3 = "cli::array<";
  }
  pDVar2 = (DName *)operator+(local_14,(DName *)pcVar3);
  DName::operator=(local_c,pDVar2);
LAB_00704c98:
  DName::DName(param_1,local_c);
  return param_1;
}

