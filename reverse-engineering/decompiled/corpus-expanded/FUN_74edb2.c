/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74edb2; label: thunk_FUN_006e85b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void thunk_FUN_006e85b0(LPVOID param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  if (param_1 != (LPVOID)0x0) {
    if (DAT_029a9b28 == 3) {
      __lock(4);
      iVar1 = thunk_FUN_006f19ca(param_1);
      if (iVar1 != 0) {
        ___sbh_free_block(iVar1,param_1);
      }
      FUN_006e7689();
      if (iVar1 != 0) {
        return;
      }
    }
    BVar2 = HeapFree(DAT_0297c974,0,param_1);
    if (BVar2 == 0) {
      puVar3 = (undefined4 *)FUN_006ead5f();
      DVar4 = GetLastError();
      uVar5 = FUN_006ead24(DVar4);
      *puVar3 = uVar5;
    }
  }
  return;
}

