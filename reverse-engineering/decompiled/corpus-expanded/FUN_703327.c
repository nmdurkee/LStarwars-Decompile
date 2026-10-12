/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x703327; label: DName::isUDC
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: int __thiscall DName::isUDC(void)const 
   
   Library: Visual Studio 2005 Release */

int __thiscall DName::isUDC(DName *this)

{
  int iVar1;
  int extraout_ECX;
  
  iVar1 = isEmpty(this);
  if ((iVar1 == 0) && ((*(byte *)(extraout_ECX + 4) & 0x20) != 0)) {
    return 1;
  }
  return 0;
}

