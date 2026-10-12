/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x712b78; label: _atol
 */

/* Library Function - Single Match
    _atol
   
   Library: Visual Studio 2005 Release */

long __cdecl _atol(char *_Str)

{
  long lVar1;
  
  lVar1 = _strtol(_Str,(char **)0x0,10);
  return lVar1;
}

