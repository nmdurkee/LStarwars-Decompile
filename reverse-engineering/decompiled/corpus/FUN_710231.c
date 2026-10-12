/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x710231; label: _wcstombs_s
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

