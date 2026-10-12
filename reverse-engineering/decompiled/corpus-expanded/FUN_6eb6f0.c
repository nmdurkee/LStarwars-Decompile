/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eb6f0; label: _toupper
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

