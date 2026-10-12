/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4c80; label: FUN_005e4c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort * FUN_005e4c80(void)

{
  int *in_ECX;
  ushort *_Dst;
  int unaff_EDI;
  
  _Dst = (ushort *)(*in_ECX + 0xfU & 0xfffffff0);
  *in_ECX = (*in_ECX + 0xfU & 0xfffffff0) + 0x2c4;
  _memset(_Dst,0,0x2c4);
  _Dst[0x2a] = 0;
  _Dst[0x2b] = 0x3f80;
  *(uint *)(_Dst + 0x22) = *(uint *)(_Dst + 0x22) | 0x10;
  _Dst[0x2c] = 0;
  _Dst[0x2d] = 0x3f80;
  *_Dst = *_Dst & 0xfffb;
  _Dst[0x2e] = 0;
  _Dst[0x2f] = 0x3f80;
  _Dst[0x38] = 0;
  _Dst[0x39] = 0x3f80;
  *(uint *)(_Dst + 0x20) = *(uint *)(_Dst + 0x20) & 0xbf9e2fd0 | 0x3f962010;
  if (unaff_EDI != 0) {
    FUN_005de1c0(_Dst);
    FUN_00600f20(_Dst);
    return _Dst;
  }
  *(uint *)(_Dst + 0x22) = *(uint *)(_Dst + 0x22) | 0x800000;
  FUN_00600f20(_Dst);
  return _Dst;
}

