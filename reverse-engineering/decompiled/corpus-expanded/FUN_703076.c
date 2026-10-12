/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x703076; label: Replicator::operator[]
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: class DName const & __thiscall Replicator::operator[](int)const 
   
   Library: Visual Studio 2005 Release */

DName * __thiscall Replicator::operator[](Replicator *this,int param_1)

{
  DName *pDVar1;
  
  if ((uint)param_1 < 10) {
    if ((*(int *)this == -1) || (*(int *)this < param_1)) {
      pDVar1 = (DName *)(this + 0x34);
    }
    else {
      pDVar1 = *(DName **)(this + param_1 * 4 + 4);
    }
  }
  else {
    pDVar1 = (DName *)(this + 0x2c);
  }
  return pDVar1;
}

