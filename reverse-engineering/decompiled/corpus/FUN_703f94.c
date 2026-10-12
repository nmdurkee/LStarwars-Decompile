/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703f94; label: UnDecorator::getVdispMapType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getVdispMapType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getVdispMapType(DName *param_1)

{
  DName *pDVar1;
  DName *in_stack_00000008;
  
  DName::DName(param_1,in_stack_00000008);
  DName::operator+=(param_1,"{for ");
  pDVar1 = (DName *)getScope();
  DName::operator+=(param_1,pDVar1);
  DName::operator+=(param_1,'}');
  if (*DAT_0297cb78 == '@') {
    DAT_0297cb78 = DAT_0297cb78 + 1;
  }
  return param_1;
}

