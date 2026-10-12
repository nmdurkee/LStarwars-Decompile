/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f08ae; label: __msize
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __msize
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

size_t __cdecl __msize(void *_Memory)

{
  undefined4 *puVar1;
  size_t sVar2;
  int iVar3;
  size_t local_20;
  
  if (_Memory == (void *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    sVar2 = 0xffffffff;
  }
  else {
    if (DAT_029a9b28 == 3) {
      __lock(4);
      iVar3 = thunk_FUN_006f19ca(_Memory);
      if (iVar3 != 0) {
        local_20 = *(int *)((int)_Memory + -4) - 9;
      }
      FUN_006f0948();
      if (iVar3 != 0) {
        return local_20;
      }
    }
    sVar2 = HeapSize(DAT_0297c974,0,_Memory);
  }
  return sVar2;
}

