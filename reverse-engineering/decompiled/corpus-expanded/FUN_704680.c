/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x704680; label: UnDecorator::getLexicalFrame
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getLexicalFrame(void)
   
   Library: Visual Studio 2005 Release */

undefined4 __cdecl UnDecorator::getLexicalFrame(void)

{
  DName *this;
  undefined4 in_stack_00000004;
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = in_stack_00000004;
  getDimension(true);
  cVar1 = (char)uVar2;
  this = (DName *)operator+(-0x14,(DName *)0x60);
  DName::operator+(this,cVar1);
  return in_stack_00000004;
}

