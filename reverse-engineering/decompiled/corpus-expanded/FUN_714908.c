/* Ghidra pseudocode, not original source.
 * ev_c09651ace20024f11839ee456cac4ec8121322dc556372c49fd0131b1bfe5fb3
 * Entry: 0x714908; label: __dupenv_s_helper
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __dupenv_s_helper
   
   Library: Visual Studio 2005 Release */

undefined4 __dupenv_s_helper(size_t *param_1,char *param_2)

{
  undefined4 *puVar1;
  char *_Str;
  size_t sVar2;
  char *_Dst;
  errno_t eVar3;
  undefined4 *unaff_EBX;
  
  if (unaff_EBX != (undefined4 *)0x0) {
    *unaff_EBX = 0;
    if (param_1 != (size_t *)0x0) {
      *param_1 = 0;
    }
    if (param_2 != (char *)0x0) {
      _Str = __getenv_helper_nolock(param_2);
      if (_Str != (char *)0x0) {
        sVar2 = _strlen(_Str);
        sVar2 = sVar2 + 1;
        _Dst = _calloc(sVar2,1);
        *unaff_EBX = _Dst;
        if (_Dst == (char *)0x0) {
          puVar1 = (undefined4 *)FUN_006ead5f();
          *puVar1 = 0xc;
          puVar1 = (undefined4 *)FUN_006ead5f();
          return *puVar1;
        }
        eVar3 = _strcpy_s(_Dst,sVar2,_Str);
        if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        if (param_1 != (size_t *)0x0) {
          *param_1 = sVar2;
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

