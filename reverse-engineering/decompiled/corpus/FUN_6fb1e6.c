/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fb1e6; label: ___lc_lctostr
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

