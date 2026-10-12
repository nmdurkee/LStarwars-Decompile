/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703736; label: UnDecorator::getReturnType
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

