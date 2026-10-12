/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b650; label: FUN_0054b650
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054b650(int param_1,uint *param_2)

{
  undefined4 *_Dst;
  size_t _Size;
  
  _Dst = (undefined4 *)*param_2;
  _DAT_00926c1c = _Dst;
  *param_2 = (int)_Dst + param_1 * 4 + 7 & 0xfffffffc;
  _memset(_Dst,0,param_1 * 4 + 4);
  *_Dst = PTR_s_Err____00802334;
  DAT_00926c20 = _Dst + 1;
  DAT_00926c3c = (void *)*param_2;
  _Size = ((int)(param_1 + 0x1f + (param_1 + 0x1f >> 0x1f & 0x1fU)) >> 5) * 4;
  DAT_00926c38 = param_1;
  _memset(DAT_00926c3c,0,_Size);
  *param_2 = *param_2 + _Size;
  return;
}

