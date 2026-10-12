/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703b21; label: DName::operator+
 */

/* Library Function - Single Match
    public: class DName __thiscall DName::operator+(enum DNameStatus)const 
   
   Library: Visual Studio 2005 Release */

DNameStatus __thiscall DName::operator+(DName *this,DNameStatus param_1)

{
  int iVar1;
  DName *this_00;
  DNameStatus in_stack_00000008;
  
  DName((DName *)param_1,this);
  iVar1 = isEmpty((DName *)param_1);
  if (iVar1 == 0) {
    operator+=(this_00,in_stack_00000008);
  }
  else {
    operator=(this_00,in_stack_00000008);
  }
  return param_1;
}

