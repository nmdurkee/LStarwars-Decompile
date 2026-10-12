/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x70596c; label: UnDecorator::getBasedType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getBasedType(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getBasedType(void)

{
  char cVar1;
  char *pcVar2;
  DName *pDVar3;
  DName *in_stack_00000004;
  DName local_c [8];
  
  pcVar2 = UScore(0);
  DName::DName(local_c,pcVar2);
  if (*DAT_0297cb78 == '\0') {
    DName::operator+=(local_c,2);
  }
  else {
    cVar1 = *DAT_0297cb78;
    DAT_0297cb78 = DAT_0297cb78 + 1;
    if (cVar1 == '0') {
      DName::operator+=(local_c,"void");
    }
    else if (cVar1 == '2') {
      pDVar3 = (DName *)getScopedName();
      DName::operator+=(local_c,pDVar3);
    }
    else if (cVar1 == '5') {
      DName::DName(in_stack_00000004,1);
      return in_stack_00000004;
    }
  }
  DName::operator+=(local_c,") ");
  DName::DName(in_stack_00000004,local_c);
  return in_stack_00000004;
}

