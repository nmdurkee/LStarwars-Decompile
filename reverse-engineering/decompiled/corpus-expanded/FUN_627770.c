/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627770; label: FUN_00627770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00627770(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(100,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\fileselect.c",
                              0x54a);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,100);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0x10;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_00623850;
    *(code **)((int)_Dst + 0x40) = FUN_00623890;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x4c) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x50) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x60) = param_3;
    *(undefined4 *)((int)_Dst + 0x54) = 0x43340000;
    *(undefined4 *)((int)_Dst + 0x5c) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x58) = 0x3f800000;
    return _Dst;
  }
  return (void *)0x0;
}

