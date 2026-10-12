/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x626a80; label: FUN_00626a80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_00626a80(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x8c,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x151a);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x8c);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0x14;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(byte *)((int)_Dst + 0x11) = *(byte *)((int)_Dst + 0x11) & 0xfe;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(undefined1 **)((int)_Dst + 0x3c) = &LAB_00626890;
    *(undefined **)((int)_Dst + 0x40) = &DAT_00626a70;
    *(code **)((int)_Dst + 0x44) = FUN_0061eee0;
    *(undefined **)((int)_Dst + 0x48) = &DAT_0061eed0;
    FUN_00619430(_Dst,param_3);
    FUN_0061e530(_Dst,param_4);
    *(undefined4 *)((int)_Dst + 0x54) = _DAT_0080f7a8;
    return _Dst;
  }
  return (void *)0x0;
}

