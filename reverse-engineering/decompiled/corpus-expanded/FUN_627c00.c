/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627c00; label: FUN_00627c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_00627c00(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x168,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x63d);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x168);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 1;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    *(undefined4 *)((int)_Dst + 0x34) = param_2[3];
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    *(code **)((int)_Dst + 0x3c) = FUN_006280a0;
    *(undefined1 **)((int)_Dst + 0x40) = &LAB_00624840;
    *(code **)((int)_Dst + 0x44) = FUN_006245f0;
    FUN_00619430(_Dst,param_4);
    *(undefined2 *)((int)_Dst + 0x15a) = 0xff;
    *(undefined4 *)((int)_Dst + 0x15c) = param_3;
    *(undefined4 *)((int)_Dst + 0x160) = 0;
    *(undefined4 *)((int)_Dst + 0x154) = 0;
    FUN_00619c50(_Dst,&DAT_007608a4);
    DAT_02912118 = PTR_s_1234567890_0080f568;
    DAT_0291211c = PTR_s_QWERTYUIOP_0080f56c;
    _DAT_02912120 = PTR_s_ASDFGHJKL__0080f570;
    _DAT_02912124 = PTR_s_ZXCVBNM<>__0080f574;
    return _Dst;
  }
  return (void *)0x0;
}

