/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4b20; label: FUN_005e4b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort * FUN_005e4b20(int param_1)

{
  ushort in_AX;
  int iVar1;
  int in_ECX;
  byte *pbVar2;
  ushort *_Dst;
  int iVar3;
  ushort *local_8;
  ushort *local_4;
  
  local_8 = (ushort *)0x0;
  if (in_ECX < 1) {
    FUN_00600f20();
    return local_4;
  }
  iVar3 = DAT_00971590;
  local_4 = (ushort *)in_ECX;
  do {
    _Dst = (ushort *)0x0;
    iVar1 = 0;
    pbVar2 = DAT_0096e560;
    if (0 < iVar3) {
      do {
        if (((*pbVar2 & 1) == 0) && (*(int *)(pbVar2 + 0x3c) == 0)) {
          _Dst = (ushort *)(DAT_0096e560 + iVar1 * 0x2c4);
          if (_Dst != (ushort *)0x0) goto LAB_005e4b8b;
          break;
        }
        iVar1 = iVar1 + 1;
        pbVar2 = pbVar2 + 0x2c4;
      } while (iVar1 < iVar3);
    }
    FUN_005c12e0();
LAB_005e4b8b:
    _memset(_Dst,0,0x2c4);
    _Dst[0x2a] = 0;
    _Dst[0x2b] = 0x3f80;
    _Dst[0x2c] = 0;
    _Dst[0x2d] = 0x3f80;
    *(uint *)(_Dst + 0x22) = *(uint *)(_Dst + 0x22) | 0x10;
    _Dst[0x2e] = 0;
    _Dst[0x2f] = 0x3f80;
    _Dst[0x38] = 0;
    _Dst[0x39] = 0x3f80;
    *(uint *)(_Dst + 0x20) = *(uint *)(_Dst + 0x20) & 0xbf9e2fd0 | 0x3f962010;
    *_Dst = *_Dst & 0xf00f | (in_AX & 0xff) << 4 | 5;
    if (param_1 == 0) {
      *(uint *)(_Dst + 0x22) = *(uint *)(_Dst + 0x22) | 0x800000;
    }
    else {
      FUN_004ffaa0(DAT_00973fa4);
      if (DAT_00973e4c == 600) {
        FUN_004ffac0(DAT_00973fa4);
        FUN_005c12e0();
        iVar3 = DAT_00971590;
      }
      else {
        *(ushort **)(DAT_00973e50 + DAT_00973e4c * 4) = _Dst;
        DAT_00973e4c = DAT_00973e4c + 1;
        FUN_004ffac0(DAT_00973fa4);
        iVar3 = DAT_00971590;
      }
    }
    local_4 = (ushort *)((int)local_4 + -1);
    *(ushort **)(_Dst + 0x18) = local_8;
    local_8 = _Dst;
    if (local_4 == (ushort *)0x0) {
      FUN_00600f20(_Dst,param_1);
      return _Dst;
    }
  } while( true );
}

