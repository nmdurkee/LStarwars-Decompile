/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f08ae; label: __msize
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

