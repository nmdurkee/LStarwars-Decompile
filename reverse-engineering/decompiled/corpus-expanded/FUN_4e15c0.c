/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e15c0; label: FUN_004e15c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e15c0(int param_1)

{
  float fVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar11;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar12;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  uint local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  local_80 = 1e+09;
  bVar2 = false;
  iVar8 = 0;
  if ((DAT_00889048 != 0) && ((*(byte *)(DAT_00889048 + 0x13a) & 0x10) != 0)) {
    DAT_00889048 = 0;
  }
  puVar3 = (undefined4 *)FUN_005d0330(&DAT_0088902c);
  local_7c = 0.0;
  local_78 = 0.0;
  local_74 = _DAT_007fffb8;
  FUN_005b35a0(&local_7c,&local_7c,DAT_00889074);
  FUN_005b3620(&local_7c,&local_7c,DAT_00889078);
  FUN_005b37d0(&local_7c,&local_7c,&DAT_007fffac);
  _DAT_00889080 = _DAT_00925018 + _DAT_00889080;
  iVar4 = FUN_006e6b90();
  fVar11 = (float10)1;
  local_78 = (float)(((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + fVar11) * (float10)0.5)
             * _DAT_00800088 + local_78;
  fVar12 = extraout_ST0;
  iVar4 = FUN_006e6b90();
  local_74 = (float)(((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + fVar12) *
                    extraout_ST0_00) * _DAT_00800080 + local_74;
  if ((DAT_00889020 != 0) && (0.0 < *(float *)(DAT_00889020 + 0x28))) {
    FUN_005cfc00(&DAT_0088902c,1);
    fVar11 = (float10)_DAT_00925018;
    fVar12 = (float10)1;
  }
  if (DAT_00889085 != '\0') {
    FUN_00681f40("Slave1_EngineLp",&DAT_0088905c);
    fVar11 = (float10)_DAT_00925018;
    fVar12 = (float10)1;
  }
  switch(DAT_00889085) {
  case '\0':
    if (0.0 < *(float *)(DAT_00889010 + 0x28)) {
      _DAT_0088907c = 0.0;
      DAT_00889085 = '\x01';
      FUN_00558920(*(undefined4 *)(param_1 + 0x46a4),"slave1_debris");
    }
    _DAT_0088905c = DAT_007fffac;
    _DAT_00889060 = _DAT_0080007c;
    _DAT_00889064 = DAT_007fffb4;
    _DAT_00889068 = DAT_00800078;
    _DAT_0088906c = DAT_008894c4;
    DAT_00889074 = DAT_007fffbc;
    DAT_00889078 = DAT_007fffc0;
    break;
  case '\x01':
    _DAT_0088907c = (float)((float10)_DAT_0088907c + fVar11);
    if (_DAT_00800074 <= _DAT_0088907c) {
      DAT_00889085 = '\x02';
      local_84 = 1.0;
      _DAT_0088907c = 0.0;
    }
    else {
      iVar8 = FUN_006e6b90();
      local_84 = (float)(((float10)(float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff] + extraout_ST0_01) *
                        extraout_ST1);
      fVar12 = extraout_ST0_01;
    }
    _DAT_00889060 =
         (float)((float10)local_84 * (float10)local_78 +
                (float10)_DAT_0080007c * (fVar12 - (float10)local_84));
    break;
  case '\x02':
    uVar7 = _DAT_00889068 & 0xffff;
    _DAT_0088907c = (float)(fVar11 + (float10)_DAT_0088907c);
    fVar1 = _DAT_0088907c;
    if (_DAT_00800070 <= _DAT_0088907c) {
      _DAT_00889068 = FUN_00550070(uVar7,DAT_008894c0,_DAT_00800070);
      _DAT_00889068 = _DAT_00889068 & 0xffff;
      _DAT_0088907c = 0.0;
      DAT_00889085 = '\x03';
      break;
    }
    goto LAB_004e19c6;
  case '\x03':
    _DAT_0088907c = (float)(fVar11 + (float10)_DAT_0088907c);
    if (_DAT_0080006c <= _DAT_0088907c) {
      _DAT_0088906c = FUN_00550070(_DAT_0088906c & 0xffff,_DAT_00800068 & 0xffff,_DAT_0080006c);
      _DAT_0088907c = 0.0;
      DAT_00889085 = '\x04';
    }
    else {
      _DAT_0088906c = FUN_00550070(_DAT_0088906c & 0xffff,_DAT_00800068 & 0xffff,_DAT_0088907c);
    }
    _DAT_0088906c = _DAT_0088906c & 0xffff;
    uVar7 = _DAT_00889068 & 0xffff;
    fVar1 = _DAT_00800070;
LAB_004e19c6:
    _DAT_00889068 = FUN_00550070(uVar7,DAT_008894c0,fVar1);
    _DAT_00889068 = _DAT_00889068 & 0xffff;
    break;
  case '\x04':
    _DAT_0088907c = (float)((float10)_DAT_0088907c + fVar11);
    if (_DAT_00800074 <= _DAT_0088907c) {
      DAT_00889085 = '\x05';
      local_84 = 1.0;
      _DAT_0088907c = 0.0;
    }
    else {
      iVar8 = FUN_006e6b90();
      local_84 = (float)(((float10)(float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff] + extraout_ST0_02) *
                        extraout_ST1_00);
      fVar12 = extraout_ST0_02;
    }
    fVar11 = (float10)local_84;
    _DAT_0088905c = (float)((float10)DAT_007fffac * (fVar12 - fVar11) + fVar11 * (float10)local_7c);
    _DAT_00889064 = (float)(fVar11 * (float10)local_74 + (float10)DAT_007fffb4 * (fVar12 - fVar11));
    _DAT_00889068 = FUN_00550070(_DAT_00889068 & 0xffff,_DAT_00800064 & 0xffff,_DAT_00800070);
    _DAT_00889068 = _DAT_00889068 & 0xffff;
    _DAT_0088906c = FUN_00550070(_DAT_0088906c & 0xffff,_DAT_00800068 & 0xffff,_DAT_0080006c);
    _DAT_0088906c = _DAT_0088906c & 0xffff;
    break;
  case '\x05':
    if (DAT_00889048 == 0) {
      if (*(float *)(DAT_00889014 + 0x28) == 1.0) {
        piVar9 = &DAT_0093d7f0;
        do {
          iVar4 = *piVar9;
          if ((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
              ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
             ((*(uint *)(*(int *)(iVar4 + 0x54) + 4) & 0x80000) == 0)) {
            fVar11 = (float10)FUN_005b3c50(iVar4 + 0x80,puVar3 + 0xc,&local_58);
            if ((float)fVar11 < local_80) {
              iVar8 = *piVar9;
              local_80 = (float)fVar11;
            }
          }
          piVar9 = piVar9 + 1;
        } while ((int)piVar9 < 0x93d810);
        if (iVar8 != 0) {
          local_70 = *(undefined4 *)(iVar8 + 0x80);
          local_6c = *(float *)(iVar8 + 0x21c) + 0.1;
          local_68 = *(undefined4 *)(iVar8 + 0x88);
          goto LAB_004e1bde;
        }
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_005cf9e0(*(int *)(DAT_00889048 + 0x1c) + 4);
      local_70 = *puVar5;
      local_6c = _DAT_00800060 + (float)puVar5[1];
      local_68 = puVar5[2];
LAB_004e1bde:
      bVar2 = true;
    }
    DAT_00889074 = DAT_007fffbc;
    if (bVar2) {
      iVar8 = FUN_006e6b90();
      local_64 = 0;
      local_60 = -_DAT_007fffc8;
      DAT_00889078 = DAT_007fffc0 - iVar8;
      local_5c = -_DAT_007fffcc;
      FUN_005b3200(&local_64,&local_64,puVar3);
      FUN_005b37d0(&local_64,&local_64,&local_70);
      FUN_005b3800(&local_58,&local_64,&DAT_0088905c);
      FUN_005bfe00(local_58,local_50);
      local_88 = FUN_006e6b90();
      fVar11 = (float10)FUN_005c0240(local_50 * local_50 + local_58 * local_58);
      local_84 = (float)fVar11;
      FUN_005bfe00(-local_54,local_84);
      local_80 = (float)FUN_006e6b90();
      _DAT_0088907c = _DAT_0088907c + _DAT_00925018;
      if (_DAT_007fffdc < _DAT_0088907c) {
        _DAT_0088907c = 0.0;
        iVar8 = 0;
        do {
          puVar5 = puVar3;
          puVar10 = local_40;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar10 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar10 = puVar10 + 1;
          }
          FUN_005b30a0(local_4c,&DAT_007fffc4 + DAT_00889084 * 0xc,puVar3);
          if (iVar8 == 0) {
            fVar11 = (float10)FUN_005becc0(local_4c,&local_70,0);
            local_84 = (float)fVar11;
          }
          FUN_005bfe00(-*(float *)(&DAT_007fffc4 + DAT_00889084 * 0xc),local_84);
          uVar6 = FUN_006e6b90();
          FUN_005b5060(local_40,uVar6);
          DAT_009543e8 = 1;
          iVar4 = FUN_00582e70(0,local_4c,local_40,0x27,0x800);
          if (iVar4 != 0) {
            *(uint *)(iVar4 + 0xf0) = *(uint *)(iVar4 + 0xf0) | 0x10;
          }
          DAT_00889084 = DAT_00889084 == '\0';
          iVar8 = iVar8 + 1;
        } while (iVar8 < 2);
        FUN_00681f40("Kam_Slave1BlasterFire",local_4c);
      }
    }
    else {
      DAT_00889078 = DAT_007fffc0;
      local_88 = _DAT_00800068;
      local_80 = (float)_DAT_00800064;
    }
    FUN_0054fb80(&DAT_0088905c,&DAT_0088905c,&local_7c,_DAT_00800058);
    _DAT_00889068 = FUN_00550070(_DAT_00889068 & 0xffff,local_80,_DAT_00800058);
    _DAT_00889068 = _DAT_00889068 & 0xffff;
    _DAT_0088906c = FUN_00550070(_DAT_0088906c & 0xffff,local_88,_DAT_00800058);
    _DAT_0088906c = _DAT_0088906c & 0xffff;
  }
  FUN_005b4500(puVar3,&DAT_0088905c);
  FUN_005b5060(puVar3,_DAT_0088906c);
  FUN_005b4dd0(puVar3,_DAT_00889068);
  return;
}

