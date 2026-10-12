/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f2905; label: __callnewh
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2005 Release */

int __cdecl __callnewh(size_t _Size)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = (code *)FUN_006f01bc(DAT_0297cacc);
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(_Size);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

