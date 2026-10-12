/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x7038fb; label: DName::DName
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

