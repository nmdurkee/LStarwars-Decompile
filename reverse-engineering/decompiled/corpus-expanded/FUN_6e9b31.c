/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e9b31; label: _memcpy_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _memcpy_s
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

errno_t __cdecl _memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  undefined4 *puVar2;
  
  if (_MaxCount == 0) {
LAB_006e9b3f:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_006e9b48:
      puVar2 = (undefined4 *)FUN_006ead5f();
      eVar1 = 0x16;
      *puVar2 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        _memcpy(_Dst,_Src,_MaxCount);
        goto LAB_006e9b3f;
      }
      _memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_006e9b48;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      puVar2 = (undefined4 *)FUN_006ead5f();
      eVar1 = 0x22;
      *puVar2 = 0x22;
    }
    FUN_006e9fc2(0,0,0,0,0);
  }
  return eVar1;
}

