/* Ghidra analysis pseudocode, not original source.
 * ev_2f277248dc33480f063e4f0d474d621052bdb6108e7bcd5536ed18fa967ce013
 * Entry: 0x6f8503; label: _strcpy_s
 */

/* Library Function - Single Match
    _strcpy_s
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl _strcpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  errno_t eVar4;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    pcVar3 = _Dst;
    if (_Src != (char *)0x0) {
      do {
        cVar1 = *_Src;
        *pcVar3 = cVar1;
        _Src = _Src + 1;
        if (cVar1 == '\0') break;
        _SizeInBytes = _SizeInBytes - 1;
        pcVar3 = pcVar3 + 1;
      } while (_SizeInBytes != 0);
      if (_SizeInBytes != 0) {
        return 0;
      }
      *_Dst = '\0';
      puVar2 = (undefined4 *)FUN_006ead5f();
      eVar4 = 0x22;
      *puVar2 = 0x22;
      goto LAB_006f8522;
    }
    *_Dst = '\0';
  }
  puVar2 = (undefined4 *)FUN_006ead5f();
  eVar4 = 0x16;
  *puVar2 = 0x16;
LAB_006f8522:
  FUN_006e9fc2(0,0,0,0,0);
  return eVar4;
}

