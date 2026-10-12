/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e99fb; label: flsall
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2005 Release */

int __cdecl flsall(int param_1)

{
  int *piVar1;
  FILE *_File;
  int iVar2;
  int iVar3;
  int local_28;
  int local_20;
  
  local_20 = 0;
  local_28 = 0;
  __lock(1);
  for (iVar3 = 0; iVar3 < DAT_029aac80; iVar3 = iVar3 + 1) {
    piVar1 = (int *)(DAT_029a9c60 + iVar3 * 4);
    if ((*piVar1 != 0) && (iVar2 = *piVar1, (*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
      FUN_006e82ea(iVar3,iVar2);
      _File = *(FILE **)(DAT_029a9c60 + iVar3 * 4);
      if ((_File->_flag & 0x83U) != 0) {
        if (param_1 == 1) {
          iVar2 = __fflush_nolock(_File);
          if (iVar2 != -1) {
            local_20 = local_20 + 1;
          }
        }
        else if ((param_1 == 0) && ((_File->_flag & 2U) != 0)) {
          iVar2 = __fflush_nolock(_File);
          if (iVar2 == -1) {
            local_28 = -1;
          }
        }
      }
      FUN_006e9a9d();
    }
  }
  FUN_006e9acc();
  if (param_1 != 1) {
    local_20 = local_28;
  }
  return local_20;
}

