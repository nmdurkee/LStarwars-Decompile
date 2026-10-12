/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x494300; label: FUN_00494300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494300(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  
  FUN_00547b20(&DAT_0087656c);
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88) {
    if (DAT_00876572 == '\0') {
      FUN_00547a30(0);
    }
    else {
      fVar8 = (float10)FUN_00547a70(&DAT_0087656c);
      FUN_00547a30((float)fVar8);
    }
  }
  else {
    FUN_00547ab0(&DAT_0087656c);
  }
  _DAT_007faccc = _DAT_007faccc - _DAT_00925018;
  if (_DAT_007faccc < 0.0 != (_DAT_007faccc == 0.0)) {
    _DAT_007faccc = _DAT_007faccc + 1.5;
    DAT_0087b730 = DAT_0087b730 + 1;
    if (DAT_0087b730 == 1) {
      DAT_0087b730 = 0;
    }
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_00509ab0();
    DAT_00800940 = FUN_00547990(0x31);
    return;
  }
  iVar6 = 1;
  if (*(int *)(param_1 + 0x34) == 0) {
    *(uint *)(param_1 + 0x38) = _DAT_00876570 >> 8 & 0xff;
    if ((*(int *)(param_1 + 0x5c) == 0) || (DAT_00876571 == 0)) {
      if ((*(int *)(param_1 + 0x60) != 0) && (DAT_00876571 < 10)) {
        _DAT_00876570 = CONCAT11(DAT_00876571 + 1,DAT_00876570);
      }
    }
    else {
      _DAT_00876570 = CONCAT11(DAT_00876571 - 1,DAT_00876570);
    }
  }
  else {
    iVar6 = 2;
    if ((*(int *)(param_1 + 0x34) == 1) && (*(int *)(param_1 + 100) != 0)) {
      bVar7 = DAT_00876572 == '\0';
      _DAT_00876570 = CONCAT12(bVar7,_DAT_00876570);
      DAT_00800940 = FUN_00547990(0x30);
    }
  }
  if (*(int *)(param_1 + 0x34) != iVar6) {
    return;
  }
  if (*(int *)(param_1 + 100) == 0) {
    return;
  }
  uVar1 = 0xd;
  pbVar4 = &DAT_008668cc;
  pbVar5 = (byte *)&DAT_0087656c;
  do {
    if (*(int *)pbVar5 != *(int *)pbVar4) goto LAB_0049448c;
    uVar1 = uVar1 - 4;
    pbVar4 = pbVar4 + 4;
    pbVar5 = pbVar5 + 4;
  } while (3 < uVar1);
  if (uVar1 == 0) {
LAB_004944e9:
    iVar2 = 0;
  }
  else {
LAB_0049448c:
    iVar6 = (uint)*pbVar5 - (uint)*pbVar4;
    if (iVar6 == 0) {
      if (uVar1 == 1) goto LAB_004944e9;
      iVar6 = (uint)pbVar5[1] - (uint)pbVar4[1];
      if (iVar6 == 0) {
        if (uVar1 == 2) goto LAB_004944e9;
        iVar6 = (uint)pbVar5[2] - (uint)pbVar4[2];
        if (iVar6 == 0) {
          if ((uVar1 == 3) || (iVar6 = (uint)pbVar5[3] - (uint)pbVar4[3], iVar6 == 0))
          goto LAB_004944e9;
        }
      }
    }
    iVar2 = 1;
    if (iVar6 < 1) {
      iVar2 = -1;
    }
  }
  uVar3 = FUN_00547990(0x31 - (uint)(iVar2 != 0));
  _DAT_008668d0 = _DAT_00876570;
  _DAT_008668d4 = _DAT_00876574;
  _DAT_008668cc = DAT_0087656c;
  _DAT_00924820 = (uint)(*(char *)((int)&DAT_0087656c + DAT_00802af8) == '\0');
  DAT_008668d8 = DAT_00876578;
  FUN_006daf80(DAT_0087656c >> 0x18);
  FUN_006daf90(_DAT_00876570 & 0xff);
  FUN_006dafa0(_DAT_00876570 >> 8 & 0xff);
  FUN_006dafb0(DAT_00876572 != '\0');
  FUN_006db1c0();
  FUN_00509ab0();
  FUN_00548ef0(&DAT_008668cc);
  DAT_00800940 = uVar3;
  return;
}

