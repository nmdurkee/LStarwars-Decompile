/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eb907; label: _perror
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _perror
   
   Library: Visual Studio 2005 Release */

void __cdecl _perror(char *_ErrMsg)

{
  size_t sVar1;
  int *piVar2;
  char *_Str;
  
  ___lock_fhandle(2);
  if ((_ErrMsg != (char *)0x0) && (*_ErrMsg != '\0')) {
    sVar1 = _strlen(_ErrMsg);
    __write_nolock(2,_ErrMsg,sVar1);
    __write_nolock(2,&DAT_00759700,2);
  }
  piVar2 = (int *)FUN_006ead5f();
  _Str = __get_sys_err_msg(*piVar2);
  sVar1 = _strlen(_Str);
  __write_nolock(2,_Str,sVar1);
  __write_nolock(2,&DAT_0075ec50,1);
  FUN_006eb98b();
  return;
}

