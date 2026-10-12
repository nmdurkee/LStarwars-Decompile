/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x714875; label: __getenv_s_helper
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __getenv_s_helper
   
   Library: Visual Studio 2005 Release */

undefined4 __getenv_s_helper(char *param_1,uint param_2,char *param_3)

{
  uint *in_EAX;
  undefined4 *puVar1;
  char *_Str;
  size_t sVar2;
  errno_t eVar3;
  
  if (in_EAX != (uint *)0x0) {
    *in_EAX = 0;
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) goto LAB_007148b2;
    }
    else if (param_2 != 0) {
LAB_007148b2:
      if (param_1 != (char *)0x0) {
        *param_1 = '\0';
      }
      _Str = __getenv_helper_nolock(param_3);
      if (_Str != (char *)0x0) {
        sVar2 = _strlen(_Str);
        *in_EAX = sVar2 + 1;
        if (param_2 != 0) {
          if (param_2 < sVar2 + 1) {
            return 0x22;
          }
          eVar3 = _strcpy_s(param_1,param_2,_Str);
          if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
        }
      }
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return 0x16;
}

