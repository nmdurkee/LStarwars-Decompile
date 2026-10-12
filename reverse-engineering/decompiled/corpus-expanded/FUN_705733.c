/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x705733; label: UnDecorator::getScopedName
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getScopedName(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getScopedName(void)

{
  DName *pDVar1;
  DName *pDVar2;
  int iVar3;
  DName *this;
  DName *in_stack_00000004;
  char *pcVar4;
  DName local_1c [8];
  char local_14 [8];
  DName local_c [8];
  
  *(undefined4 *)in_stack_00000004 = 0;
  *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffff000;
  pDVar1 = (DName *)getZName(SUB41(local_c,0));
  DName::operator=(in_stack_00000004,pDVar1);
  if ((((byte)in_stack_00000004[4] & 0xf) == 0) && (*DAT_0297cb78 != '\0')) {
    if (*DAT_0297cb78 == '@') goto LAB_007057ac;
    pDVar1 = local_c;
    pcVar4 = local_14;
    pDVar2 = (DName *)getScope();
    pDVar2 = (DName *)DName::operator+(pDVar2,pcVar4);
    pDVar1 = (DName *)DName::operator+(pDVar2,pDVar1);
    DName::operator=(in_stack_00000004,pDVar1);
  }
  if (*DAT_0297cb78 != '@') {
    if (*DAT_0297cb78 == '\0') {
      iVar3 = DName::isEmpty(in_stack_00000004);
      if (iVar3 != 0) {
        DName::operator=(this,2);
        return in_stack_00000004;
      }
      pDVar1 = local_1c;
      pcVar4 = local_14;
      pDVar2 = (DName *)DName::DName(local_c,2);
      pDVar2 = (DName *)DName::operator+(pDVar2,pcVar4);
      pDVar1 = (DName *)DName::operator+(pDVar2,pDVar1);
      DName::operator=(in_stack_00000004,pDVar1);
      return in_stack_00000004;
    }
    *(undefined4 *)in_stack_00000004 = 0;
    if (((byte)*(uint *)(in_stack_00000004 + 4) & 0xf) == 3) {
      return in_stack_00000004;
    }
    *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffffff1 | 1;
    return in_stack_00000004;
  }
LAB_007057ac:
  DAT_0297cb78 = DAT_0297cb78 + 1;
  return in_stack_00000004;
}

