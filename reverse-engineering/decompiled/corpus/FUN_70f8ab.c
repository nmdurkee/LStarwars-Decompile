/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x70f8ab; label: _iswctype
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

