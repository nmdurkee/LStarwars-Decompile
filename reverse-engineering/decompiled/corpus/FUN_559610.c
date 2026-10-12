/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x559610; label: FUN_00559610
 */

void * FUN_00559610(int *param_1,uint *param_2,size_t param_3)

{
  uint uVar1;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (((param_1 != (int *)0x0) && (param_2 != (uint *)0x0)) && (*param_1 + param_3 < *param_2)) {
    uVar1 = *param_1 + 0xf;
    _Dst = (void *)(uVar1 & 0xfffffff0);
    *param_1 = (uVar1 & 0xfffffff0) + param_3;
    _memset(_Dst,0,param_3);
  }
  return _Dst;
}

