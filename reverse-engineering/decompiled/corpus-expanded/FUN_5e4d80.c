/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e4d80; label: FUN_005e4d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort * FUN_005e4d80(undefined4 param_1,int *param_2)

{
  ushort *_Dst;
  
  _Dst = (ushort *)(*param_2 + 0xfU & 0xfffffff0);
  *param_2 = (*param_2 + 0xfU & 0xfffffff0) + 0x2c4;
  _memset(_Dst,0,0x2c4);
  _Dst[0x2a] = 0;
  _Dst[0x2b] = 0x3f80;
  *_Dst = *_Dst & 0xfffb;
  _Dst[0x2c] = 0;
  _Dst[0x2d] = 0x3f80;
  *(uint *)(_Dst + 0x22) = *(uint *)(_Dst + 0x22) | 0x800010;
  _Dst[0x2e] = 0;
  _Dst[0x2f] = 0x3f80;
  _Dst[0x38] = 0;
  _Dst[0x39] = 0x3f80;
  *(uint *)(_Dst + 0x20) = *(uint *)(_Dst + 0x20) & 0xbf9e2fd0 | 0x3f962010;
  FUN_00600f20(_Dst,0);
  return _Dst;
}

