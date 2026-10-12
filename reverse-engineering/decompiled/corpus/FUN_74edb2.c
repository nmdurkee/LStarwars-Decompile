/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74edb2; label: _free
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

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

