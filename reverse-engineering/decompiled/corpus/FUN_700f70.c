/* Ghidra analysis pseudocode, not original source.
 * ev_fd7ef47e89ee49e811b9d461fb0d02a426b46bfab1eb980b5176b797a15dd7e8
 * Entry: 0x700f70; label: _isdigit
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

