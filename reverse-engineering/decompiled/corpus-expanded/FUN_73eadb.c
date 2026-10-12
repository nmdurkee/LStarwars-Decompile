/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73eadb; label: _StringCchPrintfW
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _StringCchPrintfW
   
   Library: Visual Studio 2005 Release */

HRESULT _StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...)

{
  HRESULT HVar1;
  
  if (0x7fffffff < cchDest) {
    return -0x7ff8ffa9;
  }
  HVar1 = _StringVPrintfWorkerW_16(pszDest,cchDest,pszFormat,&stack0x00000010);
  return HVar1;
}

