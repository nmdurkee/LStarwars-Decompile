/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x495310; label: FUN_00495310
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495310(undefined4 *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  iVar5 = FUN_00574e20();
  if ((param_2 != 0) && (PTR_DAT_00802c54 != (undefined *)0x0)) {
    FUN_00493de0();
  }
  iVar6 = FUN_00574e20();
  bVar13 = iVar6 != -1;
  if ((PTR_DAT_00802c54 != (undefined *)0x0) &&
     ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x400) != 0)) {
    bVar13 = true;
  }
  iVar6 = FUN_0047a8d0();
  if (iVar6 != 0) {
    bVar13 = false;
  }
  if (((DAT_00921d48 != 0) || (DAT_00921d4c != 0)) || (bVar13)) {
    if (DAT_0087b78c == '\0') {
      uVar11 = 0;
      uVar7 = FUN_006d6350();
      uVar7 = FUN_004f48e0(uVar7);
      if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
        uVar11 = 1;
      }
      if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
        uVar11 = uVar11 + 1;
      }
      if ((uVar11 < 2) || (iVar6 = FUN_006d67a0(uVar7), iVar6 != 0)) {
        FUN_006d6170(1);
      }
      DAT_0087b78c = '\x01';
    }
  }
  else if (DAT_0087b78c != '\0') {
    FUN_006d6340(0xffffffff);
    FUN_006d6170(0);
    DAT_0087b78c = '\0';
    _DAT_0087b718 = 0;
  }
  iVar6 = DAT_00800944 * 0xe0;
  sVar1 = (&DAT_00921454)[DAT_00800944 * 0x70];
  bVar13 = false;
  if (((DAT_0093b328 != 0) || (DAT_0093b32c != 0)) && (DAT_00802af8 != -1)) {
    param_1 = &DAT_009253b0 + DAT_00802af8 * 0x18;
    goto LAB_004955b7;
  }
  if (PTR_DAT_00802c54 == (undefined *)0x0) {
    bVar13 = true;
    goto LAB_004955b7;
  }
  if ((iVar5 != -1) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88)) {
    bVar13 = false;
    goto LAB_004955b7;
  }
  if ((((iVar5 == 0x12) && (DAT_0093d516 != 0)) && (DAT_0093d526 != 0)) ||
     ((((DAT_0093d7f0 != 0 && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
       (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)))) {
    bVar13 = true;
    goto LAB_004955b7;
  }
  if (param_1 != &DAT_009253b0) goto LAB_004955b7;
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b9c) {
    uVar11 = (uint)DAT_0093d526;
    uVar9 = (uint)DAT_0093d516;
    if (DAT_0093d526 == 0) {
LAB_0049555f:
      if (uVar9 == 0) goto LAB_00495563;
    }
    else if (uVar9 == 0) {
      param_1 = &DAT_00925410;
LAB_00495563:
      if (uVar11 == 0) goto LAB_00495567;
    }
  }
  else {
    if ((DAT_0093d7f0 != 0) && (DAT_0093d7f4 != 0)) {
      uVar9 = *(uint *)(DAT_0093d7f0 + 0x1fc) >> 7 & 1;
      uVar11 = *(uint *)(DAT_0093d7f4 + 0x1fc) >> 7 & 1;
      if ((*(uint *)(DAT_0093d7f0 + 0x1f8) & 0x40000) != 0) {
        uVar9 = 0;
      }
      if ((*(uint *)(DAT_0093d7f4 + 0x1f8) & 0x40000) == 0) {
        if (uVar11 != 0) {
          if (uVar9 == 0) {
            param_1 = *(undefined4 **)(DAT_0093d7f4 + 0xca4);
            goto LAB_00495563;
          }
          goto LAB_00495575;
        }
      }
      else {
        uVar11 = 0;
      }
      goto LAB_0049555f;
    }
    uVar9 = 0;
LAB_00495567:
    bVar13 = true;
    DAT_00926bd0 = 1;
  }
LAB_00495575:
  if (DAT_00800944 == 0) goto LAB_004955b7;
  if (bVar13) {
    if (DAT_0093d516 == 0) {
LAB_004955ad:
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    if (uVar9 == 0) goto LAB_004955ad;
    uVar7 = 0;
  }
  FUN_006d6340(uVar7);
LAB_004955b7:
  uVar4 = DAT_008668d4._3_1_;
  if (DAT_0087b4d8 == 0) {
    FUN_005114a0();
  }
  DAT_008668d4._3_1_ = uVar4;
  if (((_DAT_00950780 <= 0.0) && (DAT_0087658c == 0)) &&
     ((DAT_00951b80 == 0 && (DAT_0087b4d8 == 0)))) {
    if ((iVar5 != 1) || (4.0 <= _DAT_0092505c)) {
      if (bVar13) {
        uVar11 = DAT_00925414 | DAT_009253b4;
        uVar9 = DAT_00925418 | DAT_009253b8;
        uVar10 = DAT_0092541c | DAT_009253bc;
        uVar12 = DAT_00925420 | DAT_009253c0;
      }
      else {
        uVar11 = param_1[1];
        uVar9 = param_1[2];
        uVar10 = param_1[3];
        uVar12 = param_1[4];
      }
    }
    else {
      uVar9 = 0;
      uVar11 = 0;
      uVar12 = 0;
      uVar10 = 0;
    }
    iVar2 = *(int *)(iVar6 + 0x921478);
    iVar3 = *(int *)(iVar6 + 0x921474);
    iVar8 = FUN_00509d00(uVar11,uVar9,uVar10,uVar12,_DAT_00925018,DAT_008022c4,DAT_008022c8,
                         DAT_00802274,DAT_008022a4);
    if (((((DAT_00800940 == -1) && (*(int *)(iVar6 + 0x921474) != -1)) &&
         (*(int *)(iVar6 + 0x921478) != -1)) &&
        (((iVar3 != -1 && (iVar2 != -1)) &&
         ((*(int *)(iVar6 + 0x921474) != iVar3 || (*(int *)(iVar6 + 0x921478) != iVar2)))))) &&
       (iVar6 = FUN_00574e20(), iVar6 == iVar5)) {
      FUN_00547930(0x2f,0,0,0);
    }
    if ((iVar8 == 1) && (DAT_0093b328 != 0)) {
      FUN_0055c560(1);
    }
  }
  if (((sVar1 != -1) && (DAT_00951b80 != 0)) && (DAT_00951388 == 0)) {
    DAT_00951368 = 1;
  }
  return;
}

