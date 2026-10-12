/* Ghidra pseudocode, not original source.
 * ev_8ae20aee9003ac5b707eda996059b97c5ee653d1eec48e1211714341787544ca
 * Entry: 0x700f70; label: _isdigit
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2005 Release */

int __cdecl _isdigit(int _C)

{
  int iVar1;
  
  if (DAT_0297cb10 == 0) {
    return (byte)PTR_DAT_0082a668[_C * 2] & 4;
  }
  iVar1 = __isdigit_l(_C,(_locale_t)0x0);
  return iVar1;
}

