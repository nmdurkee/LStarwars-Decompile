/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x624f20; label: FUN_00624f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00624f20(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x6c,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xce1
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x6c);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0xc;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_0061bd30;
    *(code **)((int)_Dst + 0x40) = FUN_0061c030;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    FUN_00619430(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x4c) = 0x3ecccccd;
    *(undefined4 *)((int)_Dst + 0x54) = 0x3ecccccd;
    *(undefined4 *)((int)_Dst + 0x5c) = param_3;
    *(undefined4 *)((int)_Dst + 0x50) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 100) = 0;
    *(undefined4 *)((int)_Dst + 0x58) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x68) = 0x3f800000;
    return _Dst;
  }
  return (void *)0x0;
}

