/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x674490; label: FUN_00674490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00674490(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  float local_c;
  float local_8;
  
  iVar4 = (int)param_5;
  iVar9 = DAT_0292186c;
  pfVar1 = (float *)((int)param_5 + 0x48);
  iVar8 = 0;
  local_c = (*(float *)(DAT_0292186c + 0x70) -
            *(float *)(DAT_0292186c + 0x50) * *(float *)((int)param_5 + 0x48)) -
            *(float *)((int)param_5 + 0x18);
  local_8 = (*(float *)(DAT_0292186c + 0x74) -
            *(float *)((int)param_5 + 0x4c) * *(float *)(DAT_0292186c + 0x50)) -
            *(float *)((int)param_5 + 0x1c);
  fVar2 = (*(float *)(DAT_0292186c + 0x78) -
          *(float *)((int)param_5 + 0x50) * *(float *)(DAT_0292186c + 0x50)) -
          *(float *)((int)param_5 + 0x20);
  if ((param_1 <= 0.0) || (0.0 <= param_2)) {
    if ((param_1 < 0.0 != (param_1 == 0.0)) &&
       (((!NAN(param_2) && param_2 < 0.0 != (param_2 == 0.0) &&
         (fVar3 = -*(float *)(DAT_0292186c + 0x50), fVar3 < param_1 != (fVar3 == param_1))) &&
        (fVar3 < param_2 != (fVar3 == param_2))))) {
      param_5 = param_1;
      local_c = local_c - param_1 * *pfVar1;
      local_8 = local_8 - *(float *)(iVar4 + 0x4c) * param_1;
      fVar2 = fVar2 - *(float *)(iVar4 + 0x50) * param_1;
      goto LAB_006745a2;
    }
  }
  else {
    param_5 = param_1 / (param_1 - param_2);
    local_c = local_c + param_5 * *(float *)(DAT_0292186c + 0x28);
    local_8 = *(float *)(DAT_0292186c + 0x2c) * param_5 + local_8;
    fVar2 = param_5 * *(float *)(DAT_0292186c + 0x30) + fVar2;
LAB_006745a2:
    sVar5 = FUN_0066fff0(local_c,local_8,fVar2,*(float *)(iVar4 + 0x24) - *(float *)(iVar4 + 0x18),
                         *(float *)(iVar4 + 0x28) - *(float *)(iVar4 + 0x1c),
                         *(float *)(iVar4 + 0x2c) - *(float *)(iVar4 + 0x20),
                         *(float *)(iVar4 + 0x30) - *(float *)(iVar4 + 0x18),
                         *(float *)(iVar4 + 0x34) - *(float *)(iVar4 + 0x1c),
                         *(float *)(iVar4 + 0x38) - *(float *)(iVar4 + 0x20),pfVar1);
    if ((sVar5 != 0) && (param_5 <= *(float *)(iVar9 + 0x98))) {
      if (param_1 <= 0.0) {
        *(undefined1 *)(iVar9 + 0x88) = 0x11;
      }
      else {
        *(undefined1 *)(iVar9 + 0x88) = 1;
      }
      iVar8 = 1;
      *(float *)(iVar9 + 0x98) = param_5;
      *(float *)(iVar9 + 0xa8) = *pfVar1;
      *(undefined4 *)(iVar9 + 0xac) = *(undefined4 *)(iVar4 + 0x4c);
      *(undefined4 *)(iVar9 + 0xb0) = *(undefined4 *)(iVar4 + 0x50);
      *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) & 1;
    }
  }
  if (*(float *)(iVar4 + 0x58) < 65536.0) {
    pfVar1 = (float *)(iVar4 + 0x54);
    local_c = (*(float *)(iVar9 + 0x70) - *pfVar1 * *(float *)(iVar9 + 0x50)) -
              *(float *)(iVar4 + 0x3c);
    local_8 = (*(float *)(iVar9 + 0x74) - *(float *)(iVar4 + 0x58) * *(float *)(iVar9 + 0x50)) -
              *(float *)(iVar4 + 0x40);
    fVar2 = (*(float *)(iVar9 + 0x78) - *(float *)(iVar4 + 0x5c) * *(float *)(iVar9 + 0x50)) -
            *(float *)(iVar4 + 0x44);
    if ((param_3 <= 0.0) || (0.0 <= param_4)) {
      if ((param_3 < 0.0 == (param_3 == 0.0)) ||
         (((NAN(param_4) || param_4 < 0.0 == (param_4 == 0.0) ||
           (fVar3 = -*(float *)(iVar9 + 0x50), fVar3 < param_3 == (fVar3 == param_3))) ||
          (fVar3 < param_4 == (fVar3 == param_4))))) goto LAB_006748c7;
      param_5 = param_3;
      local_c = local_c - *pfVar1 * param_3;
      local_8 = local_8 - *(float *)(iVar4 + 0x58) * param_3;
      fVar2 = fVar2 - *(float *)(iVar4 + 0x5c) * param_3;
    }
    else {
      param_5 = param_3 / (param_3 - param_4);
      local_c = local_c + param_5 * *(float *)(iVar9 + 0x28);
      local_8 = *(float *)(iVar9 + 0x2c) * param_5 + local_8;
      fVar2 = param_5 * *(float *)(iVar9 + 0x30) + fVar2;
    }
    sVar5 = FUN_0066fff0(local_c,local_8,fVar2,*(float *)(iVar4 + 0x30) - *(float *)(iVar4 + 0x3c),
                         *(float *)(iVar4 + 0x34) - *(float *)(iVar4 + 0x40),
                         *(float *)(iVar4 + 0x38) - *(float *)(iVar4 + 0x44),
                         *(float *)(iVar4 + 0x24) - *(float *)(iVar4 + 0x3c),
                         *(float *)(iVar4 + 0x28) - *(float *)(iVar4 + 0x40),
                         *(float *)(iVar4 + 0x2c) - *(float *)(iVar4 + 0x44),pfVar1);
    if ((sVar5 != 0) && (param_5 < *(float *)(iVar9 + 0x98))) {
      *(float *)(iVar9 + 0x98) = param_5;
      if (param_3 <= 0.0) {
        *(undefined1 *)(iVar9 + 0x88) = 0x11;
      }
      else {
        *(undefined1 *)(iVar9 + 0x88) = 1;
      }
      iVar8 = 1;
      *(float *)(iVar9 + 0xa8) = *pfVar1;
      *(undefined4 *)(iVar9 + 0xac) = *(undefined4 *)(iVar4 + 0x58);
      *(undefined4 *)(iVar9 + 0xb0) = *(undefined4 *)(iVar4 + 0x5c);
      *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) >> 1 & 1;
    }
  }
LAB_006748c7:
  if (*(float *)(iVar9 + 0x50) == 0.0) {
LAB_00674aec:
    if (iVar8 == 0) goto LAB_00674af6;
  }
  else {
    *(int *)(iVar9 + 0x94) = iVar4;
    param_5 = 2.10195e-44;
    FUN_0066fc70(iVar4);
    if (-*(float *)(iVar9 + 0x50) < param_1 != (-*(float *)(iVar9 + 0x50) == param_1)) {
      iVar6 = FUN_00673850(0,1,&param_5,0xc);
      iVar9 = DAT_0292186c;
      if (iVar6 != 0) {
        *(undefined1 *)(DAT_0292186c + 0x89) = 1;
        iVar8 = 1;
        *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) & 1;
      }
      iVar6 = FUN_00673850(2,0,&param_5,10);
      iVar9 = DAT_0292186c;
      if (iVar6 != 0) {
        *(undefined1 *)(DAT_0292186c + 0x89) = 3;
        iVar8 = 1;
        *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) & 1;
      }
    }
    iVar6 = FUN_00673850(1,2,&param_5,9);
    iVar9 = DAT_0292186c;
    if (iVar6 != 0) {
      *(undefined1 *)(DAT_0292186c + 0x89) = 2;
      iVar8 = 1;
      *(byte *)(iVar9 + 0x35) = (*(byte *)(iVar4 + 99) >> 1 | *(byte *)(iVar4 + 99)) & 1;
    }
    if ((65536.0 <= *(float *)(iVar4 + 0x58)) ||
       (-*(float *)(iVar9 + 0x50) < param_3 == (-*(float *)(iVar9 + 0x50) == param_3))) {
      bVar7 = param_5._0_1_;
    }
    else {
      iVar6 = FUN_00673850(1,3,&param_5,5);
      iVar9 = DAT_0292186c;
      if (iVar6 != 0) {
        *(undefined1 *)(DAT_0292186c + 0x89) = 4;
        iVar8 = 1;
        *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) >> 1 & 1;
      }
      iVar6 = FUN_00673850(3,2,&param_5,3);
      iVar9 = DAT_0292186c;
      if (iVar6 != 0) {
        *(undefined1 *)(DAT_0292186c + 0x89) = 5;
        iVar8 = 1;
        *(byte *)(iVar9 + 0x35) = *(byte *)(iVar4 + 99) >> 1 & 1;
      }
      bVar7 = param_5._0_1_;
      if ((((uint)param_5 & 8) != 0) && (iVar6 = FUN_006740c0(3), iVar9 = DAT_0292186c, iVar6 != 0))
      {
        iVar8 = 1;
        *(byte *)(DAT_0292186c + 0x35) = *(byte *)(iVar4 + 99) >> 1 & 1;
      }
    }
    if (-*(float *)(iVar9 + 0x50) < param_1 != (-*(float *)(iVar9 + 0x50) == param_1)) {
      if (((bVar7 & 1) != 0) && (iVar6 = FUN_006740c0(0), iVar9 = DAT_0292186c, iVar6 != 0)) {
        iVar8 = 1;
        *(byte *)(DAT_0292186c + 0x35) = *(byte *)(iVar4 + 99) & 1;
      }
      if (((bVar7 & 2) != 0) && (iVar6 = FUN_006740c0(1), iVar9 = DAT_0292186c, iVar6 != 0)) {
        iVar8 = 1;
        *(byte *)(DAT_0292186c + 0x35) = (*(byte *)(iVar4 + 99) >> 1 | *(byte *)(iVar4 + 99)) & 1;
      }
    }
    if (((bVar7 & 4) == 0) || (iVar6 = FUN_006740c0(2), iVar9 = DAT_0292186c, iVar6 == 0))
    goto LAB_00674aec;
    iVar8 = 1;
    *(byte *)(DAT_0292186c + 0x35) = (*(byte *)(iVar4 + 99) >> 1 | *(byte *)(iVar4 + 99)) & 1;
  }
  *(int *)(iVar9 + 0x90) = iVar4;
LAB_00674af6:
  *(undefined4 *)(iVar9 + 0x9c) = *(undefined4 *)(iVar9 + 0x98);
  if (0.0 <= *(float *)(iVar9 + 0x98)) {
    return iVar8;
  }
  *(undefined4 *)(iVar9 + 0x98) = 0;
  return iVar8;
}

