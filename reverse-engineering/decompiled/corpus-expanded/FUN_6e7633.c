/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7633; label: _free
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _free
   
   Library: Visual Studio 2005 Release */

void __cdecl _free(void *_Memory)

{
  int iVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  if (_Memory != (void *)0x0) {
    if (DAT_029a9b28 == 3) {
      __lock(4);
      iVar1 = thunk_FUN_006f19ca(_Memory);
      if (iVar1 != 0) {
        ___sbh_free_block(iVar1,_Memory);
      }
      FUN_006e7689();
      if (iVar1 != 0) {
        return;
      }
    }
    BVar2 = HeapFree(DAT_0297c974,0,_Memory);
    if (BVar2 == 0) {
      puVar3 = (undefined4 *)FUN_006ead5f();
      DVar4 = GetLastError();
      uVar5 = FUN_006ead24(DVar4);
      *puVar3 = uVar5;
    }
  }
  return;
}

