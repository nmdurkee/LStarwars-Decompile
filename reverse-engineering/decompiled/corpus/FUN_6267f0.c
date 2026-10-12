/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x6267f0; label: FUN_006267f0
 */

void * FUN_006267f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x6c,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x1473);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x6c);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0x13;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(byte *)((int)_Dst + 0x11) = *(byte *)((int)_Dst + 0x11) & 0xfe;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(undefined1 **)((int)_Dst + 0x3c) = &LAB_0061ecc0;
    *(code **)((int)_Dst + 0x40) = FUN_00626320;
    *(code **)((int)_Dst + 0x44) = FUN_0061ed70;
    *(undefined1 **)((int)_Dst + 0x48) = &LAB_0061ed10;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x68) = param_3;
    return _Dst;
  }
  return (void *)0x0;
}

