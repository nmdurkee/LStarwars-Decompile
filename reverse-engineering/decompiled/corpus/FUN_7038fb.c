/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x7038fb; label: DName::DName
 */

/* Library Function - Single Match
    public: __thiscall DName::DName(char)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::DName(DName *this,char param_1)

{
  *(undefined4 *)this = 0;
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff000;
  if (param_1 != '\0') {
    doPchar(this,&param_1,1);
  }
  return this;
}

