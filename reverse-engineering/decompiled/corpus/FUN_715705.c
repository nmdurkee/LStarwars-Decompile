/* Ghidra analysis pseudocode, not original source.
 * ev_184ff99a51593b5727527cffebd3a7fadc537097cd097c26104c250d652dc9a5
 * Entry: 0x715705; label: __mbschr
 */

/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 2005 Release */

uchar * __cdecl __mbschr(uchar *_Str,uint _Ch)

{
  uchar *puVar1;
  
  puVar1 = __mbschr_l(_Str,_Ch,(_locale_t)0x0);
  return puVar1;
}

