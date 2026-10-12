/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c0c6; label: __strftime_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __strftime_l
   
   Library: Visual Studio 2005 Release */

size_t __cdecl __strftime_l(char *_Buf,size_t _Max_size,char *_Format,tm *_Tm,_locale_t _Locale)

{
  size_t sVar1;
  
  sVar1 = __Strftime_l(_Buf,_Max_size,_Format,_Tm,0,_Locale);
  return sVar1;
}

