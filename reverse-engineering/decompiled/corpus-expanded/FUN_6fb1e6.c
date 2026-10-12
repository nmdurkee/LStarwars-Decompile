/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fb1e6; label: ___lc_lctostr
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___lc_lctostr
   
   Library: Visual Studio 2005 Release */

void ___lc_lctostr(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = _strcpy_s(param_1,param_2,param_3);
  if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (param_3[0x40] != '\0') {
    __strcats(param_1,param_2,2,&DAT_0075cff4,param_3 + 0x40);
  }
  if (param_3[0x80] != '\0') {
    __strcats(param_1,param_2,2,&DAT_0075ebb0,param_3 + 0x80);
  }
  return;
}

