/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x602a90; label: FUN_00602a90
 */

int * FUN_00602a90(int *param_1)

{
  undefined4 *puVar1;
  int *_Dst;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  _Dst = (int *)FUN_004eef40(0x98,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0xac);
  _memset(_Dst,0,0x98);
  piVar7 = param_1;
  piVar8 = _Dst;
  for (iVar6 = 0x26; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  iVar6 = 0;
  if (*param_1 != 0) {
    iVar2 = FUN_00602a90(*param_1);
    *_Dst = iVar2;
  }
  if (_Dst[1] != 0) {
    param_1[1] = 0;
    param_1[2] = -1;
  }
  if (_Dst[0xb] != 0) {
    iVar2 = FUN_00602a10(param_1[0xb],_Dst[4]);
    _Dst[0xb] = iVar2;
  }
  if (_Dst[0xc] != 0) {
    pvVar3 = (void *)FUN_004eef40(param_1[4] * 0x18,
                                  "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x102)
    ;
    _Dst[0xc] = (int)pvVar3;
    _memcpy(pvVar3,(void *)param_1[0xc],param_1[4] * 0x18);
    iVar2 = 0;
    if (0 < param_1[4]) {
      do {
        uVar4 = FUN_004eef40(*(int *)(iVar6 + 0xc + param_1[0xc]) * 4,
                             "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x106);
        *(undefined4 *)(_Dst[0xc] + 0x10 + iVar6) = uVar4;
        _memcpy(*(void **)(_Dst[0xc] + 0x10 + iVar6),*(void **)(param_1[0xc] + 0x10 + iVar6),
                *(int *)(param_1[0xc] + 0xc + iVar6) * 4);
        uVar4 = FUN_004eef40(*(int *)(iVar6 + 8 + param_1[0xc]) * 4,
                             "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x109);
        *(undefined4 *)(_Dst[0xc] + 0x14 + iVar6) = uVar4;
        _memcpy(*(void **)(_Dst[0xc] + 0x14 + iVar6),*(void **)(iVar6 + param_1[0xc] + 0x14),
                *(int *)(iVar6 + 8 + param_1[0xc]) * 4);
        if (iVar2 < param_1[4] + -1) {
          *(int *)(_Dst[0xc] + iVar6) = (int)((int *)(_Dst[0xc] + iVar6) + 6);
        }
        else {
          *(undefined4 *)(iVar6 + _Dst[0xc]) = 0;
        }
        iVar2 = iVar2 + 1;
        iVar6 = iVar6 + 0x18;
      } while (iVar2 < param_1[4]);
    }
  }
  if (_Dst[0xd] != 0) {
    pvVar3 = (void *)FUN_004eef40(_Dst[4] << 4,
                                  "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x11c)
    ;
    _Dst[0xd] = (int)pvVar3;
    _memcpy(pvVar3,(void *)param_1[0xd],_Dst[4] << 4);
  }
  if (_Dst[0xe] != 0) {
    puVar5 = (undefined4 *)
             FUN_004eef40(0x14,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x124);
    _Dst[0xe] = (int)puVar5;
    puVar1 = (undefined4 *)param_1[0xe];
    *puVar5 = *puVar1;
    puVar5[1] = puVar1[1];
    puVar5[2] = puVar1[2];
    puVar5[3] = puVar1[3];
    puVar5[4] = puVar1[4];
    uVar4 = FUN_004eef40(*(int *)_Dst[0xe] * 4,
                         "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x127);
    *(undefined4 *)(_Dst[0xe] + 8) = uVar4;
    _memcpy((void *)((int *)_Dst[0xe])[2],*(void **)(param_1[0xe] + 8),*(int *)_Dst[0xe] * 4);
    uVar4 = FUN_004eef40(*(int *)_Dst[0xe] * _Dst[4] * 0xc,
                         "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",299);
    *(undefined4 *)(_Dst[0xe] + 0xc) = uVar4;
    _memcpy((void *)((int *)_Dst[0xe])[3],*(void **)(param_1[0xe] + 0xc),
            *(int *)_Dst[0xe] * _Dst[4] * 0xc);
    uVar4 = FUN_004eef40(*(int *)_Dst[0xe] * 4,
                         "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x12e);
    *(undefined4 *)(_Dst[0xe] + 4) = uVar4;
    iVar6 = 0;
    iVar2 = 0;
    if (0 < *(int *)_Dst[0xe]) {
      do {
        *(int *)(*(int *)(_Dst[0xe] + 4) + iVar2 * 4) = *(int *)(_Dst[0xe] + 0xc) + iVar6 * 0xc;
        iVar6 = iVar6 + _Dst[4];
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)_Dst[0xe]);
    }
  }
  param_1[0x12] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return _Dst;
}

