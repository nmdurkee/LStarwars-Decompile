/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552670; label: FUN_00552670
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

