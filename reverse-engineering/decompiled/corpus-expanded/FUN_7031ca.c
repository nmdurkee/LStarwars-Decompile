/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x7031ca; label: UnDecorator::getDataIndirectType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getDataIndirectType(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getDataIndirectType(void)

{
  DName *in_stack_00000004;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = local_8 & 0xfffff000;
  local_10 = local_10 & 0xfffff000;
  local_c = 0;
  local_14 = 0;
  getDataIndirectType(in_stack_00000004,(char)&local_14,(DName *)0x0,(int)&local_c);
  return in_stack_00000004;
}

