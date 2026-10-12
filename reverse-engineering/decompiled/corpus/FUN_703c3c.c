/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703c3c; label: DName::operator=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator=(char)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator=(DName *this,char param_1)

{
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff70f;
  doPchar(this,&param_1,1);
  return this;
}

