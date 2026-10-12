/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703921; label: DName::DName
 */

/* Library Function - Single Match
    public: __thiscall DName::DName(char const *)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::DName(DName *this,char *param_1)

{
  char cVar1;
  int iVar2;
  
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff000;
  *(undefined4 *)this = 0;
  if (param_1 != (char *)0x0) {
    iVar2 = 0;
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      iVar2 = iVar2 + 1;
      cVar1 = param_1[iVar2];
    }
    doPchar(this,param_1,iVar2);
  }
  return this;
}

