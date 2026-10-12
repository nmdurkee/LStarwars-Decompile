/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x70596c; label: UnDecorator::getBasedType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

