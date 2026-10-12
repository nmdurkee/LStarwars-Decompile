/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x73eadb; label: _StringCchPrintfW
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

