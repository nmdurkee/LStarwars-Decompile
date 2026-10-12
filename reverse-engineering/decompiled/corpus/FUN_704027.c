/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704027; label: operator+
 */

/* Library Function - Single Match
    class DName __cdecl operator+(char const *,class DName const &)
   
   Library: Visual Studio 2005 Release */

char * __cdecl operator+(char *param_1,DName *param_2)

{
  DName *this;
  DName *pDVar1;
  DName local_c [8];
  
  pDVar1 = (DName *)param_1;
  this = (DName *)DName::DName(local_c,(char *)param_2);
  DName::operator+(this,pDVar1);
  return param_1;
}

