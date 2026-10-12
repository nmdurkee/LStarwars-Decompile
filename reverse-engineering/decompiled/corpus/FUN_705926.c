/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x705926; label: UnDecorator::getSymbolName
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getSymbolName(void)
   
   Library: Visual Studio 2005 Release */

undefined4 __cdecl UnDecorator::getSymbolName(void)

{
  undefined4 in_stack_00000004;
  bool bVar1;
  
  bVar1 = SUB41(in_stack_00000004,0);
  if (*DAT_0297cb78 == '?') {
    if (DAT_0297cb78[1] == '$') {
      getTemplateName(bVar1);
    }
    else {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      getOperatorName(bVar1,(bool *)0x0);
    }
  }
  else {
    getZName(bVar1);
  }
  return in_stack_00000004;
}

