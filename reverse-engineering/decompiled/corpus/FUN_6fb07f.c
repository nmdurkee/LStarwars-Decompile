/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fb07f; label: __strcats
 */

/* Library Function - Single Match
    __strcats
   
   Library: Visual Studio 2005 Release */

void __strcats(char *param_1,rsize_t param_2,int param_3)

{
  errno_t eVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (0 < param_3) {
    puVar2 = &param_3;
    iVar3 = param_3;
    do {
      puVar2 = puVar2 + 1;
      eVar1 = _strcat_s(param_1,param_2,(char *)*puVar2);
      if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

