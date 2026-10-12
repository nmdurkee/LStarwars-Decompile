/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e9bac; label: _memmove_s
 */

/* Library Function - Single Match
    _memmove_s
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

errno_t __cdecl _memmove_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  undefined4 *puVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_006e9c01:
    eVar2 = 0;
  }
  else {
    if ((_Dst == (void *)0x0) || (_Src == (void *)0x0)) {
      puVar1 = (undefined4 *)FUN_006ead5f();
      eVar2 = 0x16;
      *puVar1 = 0x16;
    }
    else {
      if (_MaxCount <= _DstSize) {
        _memmove(_Dst,_Src,_MaxCount);
        goto LAB_006e9c01;
      }
      puVar1 = (undefined4 *)FUN_006ead5f();
      eVar2 = 0x22;
      *puVar1 = 0x22;
    }
    FUN_006e9fc2(0,0,0,0,0);
  }
  return eVar2;
}

