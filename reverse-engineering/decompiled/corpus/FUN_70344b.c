/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x70344b; label: DName::operator|=
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

