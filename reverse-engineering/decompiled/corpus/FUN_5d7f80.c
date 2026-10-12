/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d7f80; label: FUN_005d7f80
 */

int FUN_005d7f80(undefined4 param_1,undefined *param_2,int param_3)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  undefined4 uVar3;
  size_t _Size;
  undefined4 *_Dst;
  void *_Dst_00;
  
  if (in_EAX == (int *)0x0) {
    _Dst = (undefined4 *)
           FUN_004eef40(0x2c,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf2);
    _memset(_Dst,0,0x2c);
    iVar2 = param_3 * 4;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf5);
    _Dst[2] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf6);
    _Dst[3] = uVar3;
    uVar3 = FUN_004eef40(param_3 * 8,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf7
                        );
    _Dst[4] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf8);
    _Dst[5] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xf9);
    _Dst[6] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xfa);
    _Dst[7] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xfb);
    _Dst[8] = uVar3;
    uVar3 = FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutimebar.c",0xfc);
    _Dst[9] = uVar3;
    *_Dst = 0;
  }
  else {
    _Dst = (undefined4 *)(*in_EAX + 3U & 0xfffffffc);
    *in_EAX = (*in_EAX + 3U & 0xfffffffc) + 0x2c;
    _memset(_Dst,0,0x2c);
    _Dst[2] = *in_EAX + 3U & 0xfffffffc;
    iVar1 = param_3 * 4;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[3] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[4] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + param_3 * 8;
    *in_EAX = iVar2;
    _Dst[5] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[6] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[7] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[8] = iVar2;
    iVar2 = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *in_EAX = iVar2;
    _Dst[9] = iVar2;
    *in_EAX = (*in_EAX + 3U & 0xfffffffc) + iVar1;
    *_Dst = 1;
  }
  _Size = param_3 * 4;
  _memset((void *)_Dst[2],0,_Size);
  _memset((void *)_Dst[3],0,_Size);
  _memset((void *)_Dst[4],0,_Size);
  _memset((void *)_Dst[5],0,_Size);
  _memset((void *)_Dst[6],0,_Size);
  _memset((void *)_Dst[7],0,_Size);
  _memset((void *)_Dst[8],0,_Size);
  _memset((void *)_Dst[9],0,_Size);
  iVar2 = 0;
  do {
    if ((&DAT_009716a0)[iVar2] == 0) {
      (&DAT_009716a0)[iVar2] = _Dst;
      iVar2 = iVar2 + -1;
      goto LAB_005d81c9;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  FUN_005c12e0();
  iVar2 = 0;
LAB_005d81c9:
  if (param_2 == (undefined *)0x0) {
    if (iVar2 == -1) {
      _Dst_00 = (void *)_Dst[7];
      param_2 = &DAT_0080b9f8;
    }
    else {
      _Dst_00 = (void *)_Dst[7];
      param_2 = &DAT_0080ba18;
    }
  }
  else {
    _Dst_00 = (void *)_Dst[7];
  }
  _memcpy(_Dst_00,param_2,_Size);
  _Dst[1] = param_3;
  _Dst[10] = (uint)(0 < iVar2);
  return iVar2;
}

