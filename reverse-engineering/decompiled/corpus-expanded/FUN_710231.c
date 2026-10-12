/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x710231; label: _wcstombs_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _wcstombs_s
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl
_wcstombs_s(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,wchar_t *_Src,
           size_t _MaxCountInBytes)

{
  errno_t eVar1;
  
  eVar1 = __wcstombs_s_l(_PtNumOfCharConverted,_Dst,_DstSizeInBytes,_Src,_MaxCountInBytes,
                         (_locale_t)0x0);
  return eVar1;
}

