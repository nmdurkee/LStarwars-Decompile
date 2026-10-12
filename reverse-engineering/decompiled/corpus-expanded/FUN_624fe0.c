/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x624fe0; label: FUN_00624fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00624fe0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4,
                   undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0xc0,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xd9f
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0xc0);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0xf;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(undefined4 *)((int)_Dst + 0x74) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x78) = 0x3f000000;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined4 *)((int)_Dst + 0x84) = 0x3f800000;
    *(undefined4 *)((int)_Dst + 0x88) = 0x3f800000;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_0061c640;
    *(code **)((int)_Dst + 0x40) = FUN_0061cd60;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    *(undefined4 *)((int)_Dst + 0x70) = param_3;
    *(int *)((int)_Dst + 0x4c) = param_4;
    *(undefined4 *)((int)_Dst + 0x7c) = param_5;
    *(undefined4 *)((int)_Dst + 0x80) = param_6;
    *(undefined4 *)((int)_Dst + 0x8c) = 0xffffffff;
    *(undefined4 *)((int)_Dst + 0x50) = 0;
    *(undefined4 *)((int)_Dst + 0x54) = 0;
    *(undefined4 *)((int)_Dst + 0x58) = 0;
    *(undefined4 *)((int)_Dst + 0x5c) = 0;
    *(undefined4 *)((int)_Dst + 0x60) = 0;
    *(undefined4 *)((int)_Dst + 100) = 0;
    *(undefined4 *)((int)_Dst + 0x68) = 0;
    *(undefined4 *)((int)_Dst + 0x6c) = 0;
    if (*(char *)(param_4 + 1) < '\x02') {
      FUN_005bc370(param_4);
    }
    FUN_005bcf50(param_4,100);
    return _Dst;
  }
  return (void *)0x0;
}

