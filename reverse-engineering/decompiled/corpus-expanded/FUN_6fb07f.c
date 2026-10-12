/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fb07f; label: __strcats
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

