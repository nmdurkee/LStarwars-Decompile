/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x703185; label: und_strncpy
 */

/* Library Function - Single Match
    char * __cdecl und_strncpy(char *,char const *,unsigned int)
   
   Library: Visual Studio 2005 Release */

char * __cdecl und_strncpy(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  char *in_EDX;
  
  pcVar2 = param_1;
  for (; (param_2 != (char *)0x0 && (cVar1 = *in_EDX, *pcVar2 = cVar1, cVar1 != '\0'));
      in_EDX = in_EDX + 1) {
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + -1;
  }
  return param_1;
}

