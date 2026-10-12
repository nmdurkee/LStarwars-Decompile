/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x70344b; label: DName::operator|=
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator|=(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator|=(DName *this,DName *param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_ECX;
  DName *extraout_EDX;
  
  uVar1 = *(uint *)(this + 4);
  if (((byte)uVar1 & 0xf) != 3) {
    iVar2 = isValid(param_1);
    this = extraout_EDX;
    if (iVar2 == 0) {
      *(uint *)(extraout_EDX + 4) =
           ((*(int *)(extraout_ECX + 4) << 0x1c) >> 0x1c ^ uVar1) & 0xf ^ uVar1;
    }
  }
  return this;
}

