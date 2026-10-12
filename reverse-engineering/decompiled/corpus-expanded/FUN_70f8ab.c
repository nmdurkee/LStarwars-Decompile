/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x70f8ab; label: _iswctype
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _iswctype
   
   Library: Visual Studio 2005 Release */

int __cdecl _iswctype(wint_t _C,wctype_t _Type)

{
  int iVar1;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  undefined1 local_8 [4];
  
  if (_C == 0xffff) {
    return 0;
  }
  if (_C < 0x100) {
    return (uint)(*(ushort *)(PTR_DAT_0082a944 + (uint)_C * 2) & _Type);
  }
  if (DAT_0297cb10 == 0) {
    ___crtGetStringTypeW(&PTR_DAT_0082a680,1,&_C,1,local_8,DAT_0082a5a4,DAT_0082a5b4);
  }
  iVar1 = __iswctype_l((wint_t)__C,(wctype_t)__Type,(_locale_t)0x0);
  return iVar1;
}

