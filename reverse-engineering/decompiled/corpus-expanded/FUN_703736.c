/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703736; label: UnDecorator::getReturnType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getReturnType(class DName *)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getReturnType(DName *param_1)

{
  DName *in_stack_00000008;
  
  if (*DAT_0297cb78 == '@') {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    DName::DName(param_1,in_stack_00000008);
  }
  else {
    getDataType(param_1);
  }
  return param_1;
}

