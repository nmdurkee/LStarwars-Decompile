/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x7032fb; label: DName::isValid
 */

/* Library Function - Single Match
    public: int __thiscall DName::isValid(void)const 
   
   Library: Visual Studio 2005 Release */

int __thiscall DName::isValid(DName *this)

{
  int iVar1;
  
  iVar1 = (*(int *)(this + 4) << 0x1c) >> 0x1c;
  if ((iVar1 != 0) && (iVar1 != 2)) {
    return 0;
  }
  return 1;
}

