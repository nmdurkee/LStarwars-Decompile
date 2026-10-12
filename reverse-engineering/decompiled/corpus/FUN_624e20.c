/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x624e20; label: FUN_00624e20
 */

void * FUN_00624e20(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x74,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xb6c
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x74);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 10;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(undefined1 **)((int)_Dst + 0x3c) = &LAB_0061adb0;
    *(code **)((int)_Dst + 0x40) = FUN_0061b470;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    *(undefined1 **)((int)_Dst + 0x48) = &LAB_0061b260;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x4c) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x50) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x70) = param_3;
    *(undefined4 *)((int)_Dst + 0x54) = 0x43340000;
    *(undefined4 *)((int)_Dst + 0x5c) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x58) = 0x3f800000;
    return _Dst;
  }
  return (void *)0x0;
}

