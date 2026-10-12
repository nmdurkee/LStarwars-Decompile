/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619250; label: FUN_00619250
 */

void * FUN_00619250(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,int param_7)

{
  void *pvVar1;
  int iVar2;
  void *_Dst;
  size_t _Size;
  
  if (param_7 == 0) {
    _Size = 0x45;
  }
  else {
    iVar2 = FUN_004f1ff0(param_7);
    _Size = iVar2 + 0x45;
  }
  _Dst = (void *)FUN_004eef40(_Size,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",
                              0x3dd);
  pvVar1 = DAT_02912eac;
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,_Size);
    *(uint *)((int)_Dst + 0x38) = *(uint *)((int)_Dst + 0x38) & 0xfffffff8;
    *(undefined4 *)((int)_Dst + 0x14) = param_1;
    *(undefined4 *)((int)_Dst + 0x18) = param_2;
    *(undefined4 *)((int)_Dst + 0x1c) = param_3;
    *(undefined4 *)((int)_Dst + 0x20) = param_4;
    *(undefined4 *)((int)_Dst + 0x24) = 0xffffffff;
    *(undefined4 *)((int)_Dst + 0x28) = 0xffffffff;
    *(undefined4 *)((int)_Dst + 0x2c) = param_5;
    *(undefined4 *)((int)_Dst + 0x30) = param_6;
    pvVar1 = _Dst;
    if (param_7 != 0) {
      *(int *)((int)_Dst + 0x34) = (int)_Dst + 0x44;
      FUN_004f1f10((int)_Dst + 0x44,param_7);
    }
  }
  DAT_02912eac = pvVar1;
  DAT_02900c84 = 0;
  return _Dst;
}

