/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5185e0; label: FUN_005185e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005185e0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)&DAT_00922268;
  do {
    if (*(char *)(_Dst + 0x12) == '\0') {
      _memset(_Dst,0,0x58);
      *(byte *)((int)_Dst + 0x49) = *(byte *)((int)_Dst + 0x49) | 5;
      *(undefined1 *)(_Dst + 0x12) = 1;
      *_Dst = *param_1;
      _Dst[1] = param_1[1];
      uVar1 = param_1[2];
      _Dst[3] = param_2;
      _Dst[2] = uVar1;
      fVar2 = _DAT_00801c58;
      _Dst[4] = (float)_Dst[1] - _DAT_00801c58;
      _Dst[6] = fVar2 + (float)_Dst[1];
      return _Dst;
    }
    _Dst = _Dst + 0x16;
  } while ((int)_Dst < 0x923868);
  return (undefined4 *)0x0;
}

