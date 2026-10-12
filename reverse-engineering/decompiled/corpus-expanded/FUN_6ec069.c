/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec069; label: FUN_006ec069
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x006ec13c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ec069(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  
  __lock(8);
  if (DAT_0297c1f4 != 1) {
    _DAT_0297c1f0 = 1;
    DAT_0297c1ec = (undefined1)param_3;
    if (param_2 == 0) {
      piVar2 = (int *)FUN_006f01bc(DAT_029a9c54);
      piVar3 = (int *)FUN_006f01bc(DAT_029a9c50);
      if (piVar2 != (int *)0x0) {
        while (piVar3 = piVar3 + -1, piVar2 <= piVar3) {
          if (*piVar3 != 0) {
            iVar1 = *piVar3;
            iVar4 = __encoded_null();
            if (iVar1 != iVar4) {
              pcVar5 = (code *)FUN_006f01bc(iVar1);
              (*pcVar5)();
            }
          }
        }
      }
      FUN_006ebe0a(&DAT_00751440);
    }
    FUN_006ebe0a(&DAT_00751448);
  }
  FUN_006ec136();
  if (param_3 != 0) {
    return;
  }
  DAT_0297c1f4 = 1;
  FUN_006f179a(8);
  ___crtExitProcess(param_1);
  return;
}

