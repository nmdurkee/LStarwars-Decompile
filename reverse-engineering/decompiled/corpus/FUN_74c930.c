/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c930; label: FUN_0074c930
 */

void * FUN_0074c930(void *param_1,int param_2,int param_3)

{
  int iVar1;
  void *_Dst;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  _Dst = (void *)(param_3 + iVar1 * -4);
  if (0 < iVar1) {
    _memmove_s(_Dst,iVar1 * 4,param_1,iVar1 * 4);
  }
  return _Dst;
}

