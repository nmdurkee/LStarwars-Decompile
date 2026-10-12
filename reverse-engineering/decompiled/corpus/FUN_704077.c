/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704077; label: DName::operator+
 */

/* Library Function - Single Match
    public: class DName __thiscall DName::operator+(char const *)const 
   
   Library: Visual Studio 2005 Release */

char * __thiscall DName::operator+(DName *this,char *param_1)

{
  int iVar1;
  DName *this_00;
  char *in_stack_00000008;
  
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

