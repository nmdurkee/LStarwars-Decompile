/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x626290; label: FUN_00626290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00626290(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x4c,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x1362);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x4c);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0x12;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(byte *)((int)_Dst + 0x11) = *(byte *)((int)_Dst + 0x11) & 0xfe;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_0061ea40;
    *(code **)((int)_Dst + 0x40) = FUN_0061ea50;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    *(undefined4 *)((int)_Dst + 0x48) = 0;
    return _Dst;
  }
  return (void *)0x0;
}

