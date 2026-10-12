/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a7d0; label: FUN_0062a7d0
 */

int * FUN_0062a7d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *_Dst;
  void *_Dst_00;
  
  _Dst = (int *)FUN_00517160(param_2,param_3,0x218);
  if (_Dst != (int *)0x0) {
    _memset(_Dst,0,0x218);
    if (param_1 == 0) {
      return _Dst;
    }
    _Dst_00 = (void *)FUN_00517160(param_2,param_3,param_1 << 6);
    _Dst[1] = (int)_Dst_00;
    if (_Dst_00 != (void *)0x0) {
      *_Dst = param_1;
      _memset(_Dst_00,0,param_1 << 6);
    }
  }
  return _Dst;
}

