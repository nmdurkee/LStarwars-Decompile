/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eb8e4; label: __get_sys_err_msg
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_sys_err_msg
   
   Library: Visual Studio 2005 Release */

char * __cdecl __get_sys_err_msg(int m)

{
  int *piVar1;
  int iVar2;
  
  if (-1 < m) {
    piVar1 = (int *)FUN_006fc43a();
    if (m < *piVar1) goto LAB_006eb8fd;
  }
  piVar1 = (int *)FUN_006fc43a();
  m = *piVar1;
LAB_006eb8fd:
  iVar2 = FUN_006fc440();
  return *(char **)(iVar2 + m * 4);
}

