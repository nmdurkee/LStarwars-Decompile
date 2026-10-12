/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x702ff2; label: DName::operator=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator=(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator=(DName *this,DName *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(this + 4);
  iVar1 = (int)(uVar2 << 0x1c) >> 0x1c;
  if ((iVar1 == 0) || (iVar1 == 2)) {
    uVar2 = ((*(int *)(param_1 + 4) << 0x1c) >> 0x1c ^ uVar2) & 0xf ^ uVar2;
    *(uint *)(this + 4) = uVar2;
    uVar2 = (*(uint *)(param_1 + 4) ^ uVar2) & 0x10 ^ uVar2;
    *(uint *)(this + 4) = uVar2;
    uVar2 = (*(uint *)(param_1 + 4) ^ uVar2) & 0x20 ^ uVar2;
    *(uint *)(this + 4) = uVar2;
    uVar2 = (*(uint *)(param_1 + 4) ^ uVar2) & 0x40 ^ uVar2;
    *(uint *)(this + 4) = uVar2;
    uVar2 = (*(uint *)(param_1 + 4) ^ uVar2) & 0x80 ^ uVar2;
    *(uint *)(this + 4) = uVar2;
    *(uint *)(this + 4) = (*(uint *)(param_1 + 4) ^ uVar2) & 0x800 ^ uVar2;
    *(undefined4 *)this = *(undefined4 *)param_1;
  }
  return this;
}

