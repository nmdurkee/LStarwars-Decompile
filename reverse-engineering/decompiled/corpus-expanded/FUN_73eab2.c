/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73eab2; label: FID_conflict:_StringCbPrintfA
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    _StringCbPrintfA
    _StringCchPrintfA
   
   Library: Visual Studio 2005 Release */

HRESULT FID_conflict__StringCbPrintfA
                  (STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,...)

{
  HRESULT HVar1;
  
  if (0x7fffffff < cbDest) {
    return -0x7ff8ffa9;
  }
  HVar1 = _StringVPrintfWorkerA_16(pszDest,cbDest,pszFormat,&stack0x00000010);
  return HVar1;
}

