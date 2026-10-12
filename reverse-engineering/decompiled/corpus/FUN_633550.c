/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x633550; label: FUN_00633550
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00633550(int param_1)

{
  uint _Size;
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *_Dst;
  
  *in_ECX = &PTR_LAB_00763f18;
  _Size = param_1 * 4;
  _Dst = (void *)0x0;
  if (_Size < *DAT_0291325c - *DAT_02913258) {
    *DAT_02913258 = *DAT_02913258 + 0xf & 0xfffffff0;
    _Dst = (void *)*DAT_02913258;
    *DAT_02913258 = *DAT_02913258 + _Size;
    _memset(_Dst,0,_Size);
    _DAT_02913264 = _DAT_02913264 + _Size;
    _DAT_02913268 = _DAT_02913268 + param_1 * -4;
    _DAT_02913260 = *DAT_02913258;
  }
  in_ECX[1] = _Dst;
  in_ECX[2] = param_1;
  uVar1 = FUN_005d8270(0);
  in_ECX[6] = uVar1;
  _DAT_02913234 = in_ECX;
  return;
}

