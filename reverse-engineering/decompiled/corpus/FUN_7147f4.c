/* Ghidra analysis pseudocode, not original source.
 * ev_184ff99a51593b5727527cffebd3a7fadc537097cd097c26104c250d652dc9a5
 * Entry: 0x7147f4; label: __getenv_helper_nolock
 */

/* Library Function - Single Match
    __getenv_helper_nolock
   
   Library: Visual Studio 2005 Release */

char * __cdecl __getenv_helper_nolock(char *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (DAT_029a9c4c == 0) {
    return (char *)0x0;
  }
  if (((DAT_0297c1d4 != (int *)0x0) ||
      (((DAT_0297c1dc != 0 && (iVar1 = ___wtomb_environ(), iVar1 == 0)) &&
       (DAT_0297c1d4 != (int *)0x0)))) && (piVar3 = DAT_0297c1d4, param_1 != (char *)0x0)) {
    _MaxCount = _strlen(param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,(uchar *)param_1,_MaxCount), iVar1 == 0)) {
        return (char *)(*piVar3 + 1 + _MaxCount);
      }
    }
  }
  return (char *)0x0;
}

