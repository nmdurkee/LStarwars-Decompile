/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f41f0; label: FUN_004f41f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004f41f0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)
         FUN_004eef40(0x8a4,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nupad.cpp",0xb4);
  if (_Dst != (undefined4 *)0x0) {
    _memset(_Dst,0,0xa4);
    *_Dst = param_1;
    _Dst[1] = param_2;
    _Dst[2] = 0;
    *(undefined1 *)((int)_Dst + 0x93) = 0x80;
    *(undefined1 *)((int)_Dst + 0x92) = 0x80;
    *(undefined1 *)((int)_Dst + 0x91) = 0x80;
    *(undefined1 *)(_Dst + 0x24) = 0x80;
  }
  FUN_006d60b0(_Dst);
  return _Dst;
}

