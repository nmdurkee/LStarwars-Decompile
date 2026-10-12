/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x626170; label: FUN_00626170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_00626170(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
                   undefined4 param_9)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x80,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x1327);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x80);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0x11;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(byte *)((int)_Dst + 0x11) = *(byte *)((int)_Dst + 0x11) & 0xfe;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_00625670;
    *(code **)((int)_Dst + 0x40) = FUN_006256a0;
    *(code **)((int)_Dst + 0x44) = FUN_0061e9d0;
    *(code **)((int)_Dst + 0x48) = FUN_0061e8b0;
    FUN_00619430(_Dst,param_7);
    FUN_0061e530(_Dst,param_8);
    *(undefined4 *)((int)_Dst + 0x54) = _DAT_0080f7a8;
    *(undefined4 *)((int)_Dst + 0x70) = param_3;
    *(uint *)((int)_Dst + 0x4c) =
         *(uint *)((int)_Dst + 0x4c) ^ (param_6 << 6 ^ *(uint *)((int)_Dst + 0x4c)) & 0x1c0;
    *(undefined4 *)((int)_Dst + 0x7c) = param_9;
    *(undefined4 *)((int)_Dst + 0x78) = param_4;
    *(undefined4 *)((int)_Dst + 0x74) = param_5;
    return _Dst;
  }
  return (void *)0x0;
}

