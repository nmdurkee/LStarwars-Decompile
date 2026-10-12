/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x625150; label: FUN_00625150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00625150(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,float param_7,undefined4 param_8)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x6c,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xfd4
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x6c);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 6;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = param_3;
    *(code **)((int)_Dst + 0x3c) = FUN_0061d990;
    *(code **)((int)_Dst + 0x40) = FUN_0061dd30;
    *(code **)((int)_Dst + 0x44) = FUN_006250e0;
    *(code **)((int)_Dst + 0x48) = FUN_0061d910;
    FUN_00619430(_Dst,param_8);
    *(undefined4 *)((int)_Dst + 0x58) = param_5;
    *(undefined4 *)((int)_Dst + 0x5c) = param_6;
    *(undefined4 *)((int)_Dst + 0x4c) = param_4;
    *(undefined4 *)((int)_Dst + 0x68) = 0x3a83126f;
    *(undefined4 *)((int)_Dst + 100) = 0;
    FUN_0061d880(_Dst,"(%1.03f)");
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

