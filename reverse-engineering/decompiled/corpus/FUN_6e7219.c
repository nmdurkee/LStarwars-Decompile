/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e7219; label: _atexit
 */

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2005 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

