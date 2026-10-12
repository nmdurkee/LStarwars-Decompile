/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ed540; label: FUN_005ed540
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed540(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool bVar7;
  float10 fVar8;
  float fVar9;
  undefined1 local_c0 [20];
  undefined4 local_ac;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  puVar5 = param_1;
  puVar6 = &DAT_009736e8;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar1 = FUN_005be2d0(-DAT_00973708,-DAT_00973710);
  FUN_005ff830(uVar1);
  if (param_2 == 0) {
    FUN_005ff390();
  }
  if (DAT_00973944 == 0) {
    FUN_005c0940(&DAT_0080b708,&DAT_009736e8);
    thunk_FUN_005b4a50(&DAT_0080b708,&DAT_00973754);
  }
  else {
    FUN_005c19d0();
    local_ac = 0xbf800000;
    FUN_005b5a40(local_40,&DAT_009736e8);
    FUN_005b5a40(local_80,&DAT_009730bc);
    bVar7 = DAT_00973944 == 1;
    puVar5 = local_80;
    puVar6 = &DAT_0080b708;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    if (bVar7) {
      FUN_005b5430(&DAT_0080b708,&DAT_0080b708,local_c0);
    }
    FUN_005b5430(&DAT_0080b708,&DAT_0080b708,&DAT_009730bc);
    FUN_005b5430(&DAT_0080b708,&DAT_0080b708,local_40);
  }
  if (param_2 == 0) {
    if (DAT_00973958 == 0) {
      FUN_00604a80(&DAT_0080b748,DAT_00973728,DAT_0097372c,DAT_00973730,DAT_00973734);
      _DAT_0080b748 = _DAT_0080b748 * _DAT_00973740;
      _DAT_0080b75c = _DAT_0080b75c * _DAT_00973744;
      _DAT_0080b768 = _DAT_0080b768 + _DAT_00973738;
      _DAT_0080b76c = _DAT_0080b76c + _DAT_0097373c;
    }
    else {
      fVar9 = DAT_0097372c;
      _memset(&DAT_0080b748,0,0x40);
      _DAT_0080b748 = _DAT_0080b9cc * fVar9;
      _DAT_0080b75c = _DAT_0080b9cc;
      _DAT_0080b770 = 0x3f800000;
      _DAT_0080b784 = 0x3f800000;
    }
  }
  FUN_005ed300(&DAT_0080b888,&DAT_0080b708,&DAT_009736e8,param_2);
  if (DAT_00973950 != DAT_00973954) {
    param_2 = 0;
    DAT_00973954 = DAT_00973950;
  }
  if (DAT_00973950 == 0) {
    FUN_005ed420(&DAT_0080b848,&DAT_0080b708,&DAT_009736e8,param_2);
  }
  else {
    FUN_005ed300();
  }
  puVar5 = &DAT_00971620;
  puVar6 = &DAT_0080b7c8;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_005c1240(&DAT_0080b808,&DAT_0080b708,&DAT_0080b748);
  FUN_005c1240(&DAT_0080b908,&DAT_0080b808,&DAT_0080b7c8);
  FUN_005c1240(&DAT_0080b948,&DAT_0080b748,&DAT_0080b7c8);
  if (param_2 == 0) {
    iVar3 = FUN_006e6b90(DAT_00973728 * 0.5);
    uVar4 = iVar3 >> 1 & 0x7fff;
    uVar2 = iVar3 + 0x4000 >> 1 & 0x7fff;
    DAT_0097313c = (float)(&DAT_029899a0)[uVar4] / (float)(&DAT_029899a0)[uVar2];
    DAT_00966378 = DAT_0097313c / DAT_0097372c;
    _DAT_00966270 = ((float)_DAT_0080e69c * DAT_00966378) / (float)DAT_00973900;
    _DAT_0096dce4 = (DAT_0097313c * (float)_DAT_0080e6a0) / (float)DAT_00973904;
    _DAT_0080b990 = 0;
    _DAT_0080b9a0 = (float)(&DAT_029899a0)[uVar2];
    _DAT_0080b9b0 = (float)(&DAT_029899a0)[uVar4];
    _DAT_0080b9c0 = 0;
    _DAT_0080b994 = 0;
    _DAT_0080b9a4 = -_DAT_0080b9a0;
    _DAT_0080b9c4 = 0;
    fVar9 = (_DAT_0080b9b0 / _DAT_0080b9a0) / (float)param_1[0x11];
    _DAT_0080b9b4 = _DAT_0080b9b0;
    fVar8 = (float10)FUN_005c0240(fVar9 * fVar9 + 1.0);
    _DAT_0080b98c = (float)((float10)1 / fVar8);
    _DAT_0080b988 = -_DAT_0080b98c;
    _DAT_0080b998 = 0;
    _DAT_0080b9a8 = _DAT_0080b98c * fVar9;
    _DAT_0080b9b8 = 0;
    _DAT_0080b99c = 0;
    _DAT_0080b9bc = 0;
    _DAT_0080b9ac = _DAT_0080b9a8;
    FUN_005d5500();
  }
  FUN_005ff820(&DAT_0080b908,&DAT_0080b888,&DAT_0080b848);
  _DAT_00971748 = 1;
  _DAT_0097175c = 0;
  FUN_005ff840(0,0);
  FUN_005fcc80();
  if ((DAT_0080bbe0 != '\0') && (DAT_0080bbe1 != '\0')) {
    *(undefined1 *)(DAT_0080bd34 + 0x10) = 0;
  }
  return;
}

