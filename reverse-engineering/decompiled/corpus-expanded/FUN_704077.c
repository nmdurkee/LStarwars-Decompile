/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x704077; label: DName::operator+
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

