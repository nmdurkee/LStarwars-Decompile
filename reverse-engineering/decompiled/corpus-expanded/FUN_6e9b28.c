/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e9b28; label: __flushall
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

