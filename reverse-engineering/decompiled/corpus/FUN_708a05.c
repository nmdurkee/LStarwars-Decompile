/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x708a05; label: __mbsicmp
 */

/* Library Function - Single Match
    __mbsicmp
   
   Library: Visual Studio 2005 Release */

int __cdecl __mbsicmp(uchar *_Str1,uchar *_Str2)

{
  int iVar1;
  
  iVar1 = __mbsicmp_l(_Str1,_Str2,(_locale_t)0x0);
  return iVar1;
}

