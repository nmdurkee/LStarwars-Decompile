/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627670; label: FUN_00627670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00627670(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,float param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10,undefined4 param_11)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x70,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x1a53);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x70);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0xd;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = param_3;
    *(code **)((int)_Dst + 0x3c) = FUN_0061fa90;
    *(code **)((int)_Dst + 0x40) = FUN_0061fd70;
    *(code **)((int)_Dst + 0x44) = FUN_006250e0;
    FUN_00619430(_Dst,param_11);
    *(undefined4 *)((int)_Dst + 0x58) = param_5;
    *(undefined4 *)((int)_Dst + 0x5c) = param_6;
    *(undefined4 *)((int)_Dst + 0x4c) = param_4;
    *(undefined4 *)((int)_Dst + 0x68) = 0x3f800000;
    *(undefined4 *)((int)_Dst + 100) = 0;
    *(undefined1 *)((int)_Dst + 0x6c) = param_8;
    *(undefined1 *)((int)_Dst + 0x6d) = param_9;
    *(undefined1 *)((int)_Dst + 0x6e) = param_10;
    FUN_0061d880(_Dst,&DAT_0076af68);
    *(undefined4 *)((int)_Dst + 0x60) = 0x3c;
    *(float *)((int)_Dst + 0x50) =
         (param_7 - *(float *)((int)_Dst + 0x58)) / *(float *)((int)_Dst + 0x5c);
    *(float *)((int)_Dst + 0x54) = param_7;
    if (*(code **)((int)_Dst + 0x4c) != (code *)0x0) {
      (**(code **)((int)_Dst + 0x4c))(0,_Dst,0);
    }
    return _Dst;
  }
  return (void *)0x0;
}

