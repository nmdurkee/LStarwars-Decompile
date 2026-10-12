/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e9b28; label: __flushall
 */

/* Library Function - Single Match
    __flushall
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl __flushall(void)

{
  int iVar1;
  
  iVar1 = flsall(1);
  return iVar1;
}

