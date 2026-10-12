/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629d00; label: FUN_00629d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00629d00(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x70,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xaa2
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x70);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 7;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(undefined1 **)((int)_Dst + 0x3c) = &LAB_00628c10;
    *(code **)((int)_Dst + 0x40) = FUN_0061aa80;
    *(code **)((int)_Dst + 0x44) = FUN_0061aa10;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x54) = param_3;
    *(undefined4 *)((int)_Dst + 0x6c) = 0;
    return _Dst;
  }
  return (void *)0x0;
}

