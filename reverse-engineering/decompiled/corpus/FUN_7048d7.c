/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x7048d7; label: UnDecorator::getSignedDimension
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getSignedDimension(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getSignedDimension(void)

{
  DName *in_stack_00000004;
  
  if (*DAT_0297cb78 == '\0') {
    DName::DName(in_stack_00000004,2);
  }
  else if (*DAT_0297cb78 == '?') {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    getDimension(true);
    operator+(SUB41(in_stack_00000004,0),(DName *)0x2d);
  }
  else {
    getDimension(SUB41(in_stack_00000004,0));
  }
  return in_stack_00000004;
}

