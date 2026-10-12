/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6eae5c; label: __calloc_impl
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __calloc_impl
   
   Library: Visual Studio 2005 Release */

void * __calloc_impl(uint param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *_Dst;
  uint dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffe0 / param_1)) {
    param_1 = param_1 * param_2;
    dwBytes = param_1;
    if (param_1 == 0) {
      dwBytes = 1;
    }
    do {
      _Dst = (void *)0x0;
      if (dwBytes < 0xffffffe1) {
        if ((DAT_029a9b28 == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, param_1 <= DAT_029a9b18))
        {
          __lock(4);
          _Dst = (void *)___sbh_alloc_block(param_1);
          FUN_006eaf58();
          if (_Dst != (void *)0x0) {
            _memset(_Dst,0,param_1);
            goto LAB_006eaf0d;
          }
        }
        else {
LAB_006eaf0d:
          if (_Dst != (void *)0x0) {
            return _Dst;
          }
        }
        _Dst = HeapAlloc(DAT_0297c974,8,dwBytes);
      }
      if (_Dst != (void *)0x0) {
        return _Dst;
      }
      if (DAT_0297cad0 == 0) {
        if (param_3 == (undefined4 *)0x0) {
          return (void *)0x0;
        }
        *param_3 = 0xc;
        return (void *)0x0;
      }
      iVar2 = __callnewh(dwBytes);
    } while (iVar2 != 0);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0xc;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0xc;
    FUN_006e9fc2(0,0,0,0,0);
  }
  return (void *)0x0;
}

