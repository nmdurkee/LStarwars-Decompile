/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x70437e; label: UnDecorator::getThrowTypes
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getThrowTypes(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getThrowTypes(void)

{
  DName *pDVar1;
  DName *this;
  DName *in_stack_00000004;
  char *pcVar2;
  char cVar3;
  char local_14 [8];
  undefined4 local_c;
  uint local_8;
  
  if (*DAT_0297cb78 == '\0') {
    pcVar2 = local_14;
    pDVar1 = in_stack_00000004;
    this = (DName *)DName::DName((DName *)&local_c," throw(");
    cVar3 = (char)pDVar1;
    pDVar1 = (DName *)DName::operator+(this,(DNameStatus)pcVar2);
  }
  else {
    if (*DAT_0297cb78 == 'Z') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      local_c = 0;
      local_8 = local_8 & 0xfffff000;
      DName::DName(in_stack_00000004,(DName *)&local_c);
      return in_stack_00000004;
    }
    pDVar1 = in_stack_00000004;
    getArgumentTypes();
    cVar3 = (char)pDVar1;
    pDVar1 = (DName *)operator+(local_14,(DName *)" throw(");
  }
  DName::operator+(pDVar1,cVar3);
  return in_stack_00000004;
}

