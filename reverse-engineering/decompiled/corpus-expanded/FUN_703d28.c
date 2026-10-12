/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703d28; label: UnDecorator::getVCallThunkType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

