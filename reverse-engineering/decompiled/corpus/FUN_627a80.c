/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627a80; label: FUN_00627a80
 */

void * FUN_00627a80(undefined4 param_1,undefined4 *param_2,byte param_3,undefined4 param_4,
                   undefined4 param_5,char *param_6)

{
  undefined4 uVar1;
  void *_Dst;
  
  _Dst = (void *)FUN_004eef40(0x54,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x53b
                             );
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,0x54);
    *(undefined4 *)((int)_Dst + 0xc) = param_1;
    *(undefined4 *)((int)_Dst + 8) = 0;
    *(undefined4 *)((int)_Dst + 0x28) = *param_2;
    *(undefined4 *)((int)_Dst + 0x2c) = param_2[1];
    *(undefined4 *)((int)_Dst + 0x30) = param_2[2];
    uVar1 = param_2[3];
    *(byte *)((int)_Dst + 0x11) =
         *(byte *)((int)_Dst + 0x11) ^ (*(byte *)((int)_Dst + 0x11) ^ param_3) & 1;
    *(undefined4 *)((int)_Dst + 0x18) = param_4;
    *(undefined4 *)((int)_Dst + 0x34) = uVar1;
    *(undefined1 *)((int)_Dst + 0x12) = 0x40;
    *(code **)((int)_Dst + 0x3c) = FUN_00624590;
    *(code **)((int)_Dst + 0x40) = FUN_006196a0;
    *(code **)((int)_Dst + 0x44) = FUN_00624180;
    *(undefined1 **)((int)_Dst + 0x48) = &LAB_006194c0;
    *(undefined4 *)((int)_Dst + 0x24) = 0;
    if (param_6 == (char *)0x0) {
      param_6 = "<no name>";
    }
    FUN_00619430(_Dst,param_6);
    *(undefined4 *)((int)_Dst + 0x4c) = param_5;
    *(undefined4 *)((int)_Dst + 0x50) = 0;
    return _Dst;
  }
  return (void *)0x0;
}

