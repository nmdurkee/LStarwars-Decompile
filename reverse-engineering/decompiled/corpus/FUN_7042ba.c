/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x7042ba; label: UnDecorator::getArgumentTypes
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getArgumentTypes(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getArgumentTypes(void)

{
  char cVar1;
  DName *pDVar2;
  char *pcVar3;
  DName *in_stack_00000004;
  char local_14 [8];
  DName local_c [4];
  byte local_8;
  
  if (*DAT_0297cb78 == 'X') {
    pcVar3 = "void";
LAB_00704371:
    DAT_0297cb78 = DAT_0297cb78 + 1;
    DName::DName(in_stack_00000004,pcVar3);
    return in_stack_00000004;
  }
  if (*DAT_0297cb78 == 'Z') {
    pcVar3 = "...";
    if ((~(DAT_0297cb88 >> 0x12) & 1) == 0) {
      pcVar3 = "<ellipsis>";
    }
    goto LAB_00704371;
  }
  getArgumentList();
  if (((local_8 & 0xf) == 0) && (cVar1 = *DAT_0297cb78, cVar1 != '\0')) {
    if (cVar1 != '@') {
      if (cVar1 != 'Z') {
        DName::DName(in_stack_00000004,1);
        return in_stack_00000004;
      }
      DAT_0297cb78 = DAT_0297cb78 + 1;
      pDVar2 = (DName *)DName::operator+(local_c,local_14);
      goto LAB_0070432f;
    }
    DAT_0297cb78 = DAT_0297cb78 + 1;
  }
  pDVar2 = local_c;
LAB_0070432f:
  DName::DName(in_stack_00000004,pDVar2);
  return in_stack_00000004;
}

