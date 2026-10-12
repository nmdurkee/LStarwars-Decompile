/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703d5f; label: DName::operator+
 */

/* Library Function - Single Match
    public: class DName __thiscall DName::operator+(class DName const &)const 
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator+(DName *this,DName *param_1)

{
  int iVar1;
  DName *this_00;
  DName *extraout_ECX;
  DName *in_stack_00000008;
  
  DName(param_1,this);
  iVar1 = isEmpty(param_1);
  if (iVar1 == 0) {
    iVar1 = isEmpty(in_stack_00000008);
    if (iVar1 == 0) {
      operator+=(param_1,extraout_ECX);
    }
    else {
      operator+=(param_1,(*(int *)(extraout_ECX + 4) << 0x1c) >> 0x1c);
    }
  }
  else {
    operator=(this_00,in_stack_00000008);
  }
  return param_1;
}

