/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x704005; label: operator+
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    class DName __cdecl operator+(enum DNameStatus,class DName const &)
   
   Library: Visual Studio 2005 Release */

DNameStatus __cdecl operator+(DNameStatus param_1,DName *param_2)

{
  DName *this;
  DName *pDVar1;
  DName local_c [8];
  
  pDVar1 = (DName *)param_1;
  this = (DName *)DName::DName(local_c,(DNameStatus)param_2);
  DName::operator+(this,pDVar1);
  return param_1;
}

