/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6eb6f0; label: _toupper
 */

/* Library Function - Single Match
    _toupper
   
   Library: Visual Studio 2005 Release */

int __cdecl _toupper(int _C)

{
  if (DAT_0297cb10 == 0) {
    if (_C - 0x61U < 0x1a) {
      return _C + -0x20;
    }
  }
  else {
    _C = __toupper_l(_C,(_locale_t)0x0);
  }
  return _C;
}

