/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x628620; label: FUN_00628620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00628620(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x2a4,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x950);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x2a4);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 1;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_006285e0;
    *(code **)((int)_Dst + 0x40) = FUN_0061a320;
    *(code **)((int)_Dst + 0x44) = FUN_00624da0;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x4c) = param_3;
    *(undefined4 *)((int)_Dst + 0x50) = 0;
    *(undefined1 *)((int)_Dst + 0x58) = 0;
    *(undefined1 *)((int)_Dst + 0x98) = 0;
    *(undefined1 *)((int)_Dst + 0x198) = 0;
    *(undefined4 *)((int)_Dst + 0x2a0) = 0;
    FUN_0061a2a0(_Dst,&DAT_007608a4);
    return _Dst;
  }
  return (void *)0x0;
}

