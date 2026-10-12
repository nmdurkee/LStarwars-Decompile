/* Ghidra analysis pseudocode, not original source.
 * ev_90cdd648c2da38df3e143f8257cf22e5b1942b178da0f5c322cb3d7ec211647f
 * Entry: 0x6ff157; label: __invoke_watson_if_oneof
 */

/* Library Function - Single Match
    __invoke_watson_if_oneof
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2019 Release */

errno_t __cdecl
__invoke_watson_if_oneof
          (errno_t _ExpressionError,errno_t _ErrorValue1,errno_t _ErrorValue2,wchar_t *_Expression,
          wchar_t *_Function,wchar_t *_File,uint _Line,uintptr_t _Reserved)

{
  if ((_ExpressionError != 0) &&
     ((_ExpressionError == _ErrorValue1 || (_ExpressionError == _ErrorValue2)))) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson(_Expression,_Function,_File,_Line,_Reserved);
  }
  return _ExpressionError;
}

