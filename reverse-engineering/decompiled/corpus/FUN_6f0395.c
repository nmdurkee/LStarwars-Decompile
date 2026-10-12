/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f0395; label: FUN_006f0395
 */

DWORD * FUN_006f0395(void)

{
  DWORD dwErrCode;
  code *pcVar1;
  DWORD *_Memory;
  int iVar2;
  DWORD DVar3;
  
  dwErrCode = GetLastError();
  pcVar1 = (code *)FUN_006f024e(DAT_00829ab4);
  _Memory = (DWORD *)(*pcVar1)();
  if (_Memory == (DWORD *)0x0) {
    _Memory = __calloc_crt(1,0x214);
    if (_Memory != (DWORD *)0x0) {
      pcVar1 = (code *)FUN_006f01bc(DAT_0297c540,DAT_00829ab4,_Memory);
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        _free(_Memory);
        _Memory = (DWORD *)0x0;
      }
      else {
        FUN_006f02d6(_Memory,0);
        DVar3 = GetCurrentThreadId();
        _Memory[1] = 0xffffffff;
        *_Memory = DVar3;
      }
    }
  }
  SetLastError(dwErrCode);
  return _Memory;
}

