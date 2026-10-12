/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x703312; label: DName::isEmpty
 */

/* Library Function - Single Match
    public: int __thiscall DName::isEmpty(void)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

int __thiscall DName::isEmpty(DName *this)

{
  int iVar1;
  
  if (*(int *)this != 0) {
    iVar1 = isValid(this);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}

