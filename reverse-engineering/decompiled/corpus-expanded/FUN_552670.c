/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x552670; label: FUN_00552670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00552670(int *param_1,uint *param_2,size_t param_3)

{
  uint uVar1;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (((param_1 != (int *)0x0) && (param_2 != (uint *)0x0)) && (*param_1 + param_3 < *param_2)) {
    uVar1 = *param_1 + 3;
    _Dst = (void *)(uVar1 & 0xfffffffc);
    *param_1 = (uVar1 & 0xfffffffc) + param_3;
    if (_Dst != (void *)0x0) {
      _memset(_Dst,0,param_3);
    }
  }
  return _Dst;
}

