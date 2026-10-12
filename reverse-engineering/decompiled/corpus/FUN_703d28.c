/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703d28; label: UnDecorator::getVCallThunkType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getVCallThunkType(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getVCallThunkType(void)

{
  DName *in_stack_00000004;
  DNameStatus DVar1;
  
  if (*DAT_0297cb78 == '\0') {
    DVar1 = 2;
  }
  else {
    if (*DAT_0297cb78 == 'A') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      DName::DName(in_stack_00000004,"{flat}");
      return in_stack_00000004;
    }
    DVar1 = 1;
  }
  DName::DName(in_stack_00000004,DVar1);
  return in_stack_00000004;
}

