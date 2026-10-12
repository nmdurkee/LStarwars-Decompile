/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7048d7; label: UnDecorator::getSignedDimension
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

