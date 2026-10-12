/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e1f70; label: FUN_004e1f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e1f70(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_4;
  
  if ((DAT_00889018 != 0) && (*(float *)(DAT_00889018 + 0x28) == 1.0)) {
    FUN_004e1550();
    *(undefined4 *)(DAT_00889018 + 0x28) = 0;
  }
  if (DAT_00951b50 == 0) {
    iVar4 = FUN_0055ce20((int)DAT_007f19e0,1,1,1,0);
    iVar5 = FUN_0055ce20((int)DAT_007f19e0,4,1,1,0);
    iVar7 = iVar4;
    if ((iVar4 == 0) && (iVar7 = 0, iVar5 != 0)) {
      iVar7 = iVar5;
    }
    local_4 = 0;
    if ((iVar4 != 0) && (*(char *)(iVar4 + 0x107f) < '\x01')) {
      if (DAT_0093b2a4 == 0) {
        FUN_00489820((int)DAT_007f19e0,0,0,(int)*(short *)(DAT_0087b118 + 0x62));
      }
      else {
        FUN_004897f0((int)DAT_007f19e0,0,0);
      }
    }
    if ((((*(float *)(DAT_00889010 + 0x28) == 0.0) && (DAT_0093b2a4 == 0)) && (DAT_00889024 != 0))
       && (iVar4 = FUN_00500210(*(undefined4 *)(DAT_00889024 + 4)), iVar4 != 0)) {
      *(undefined4 *)(DAT_00889010 + 0x28) = 0x3f800000;
    }
    FUN_004e15c0(param_1);
    iVar4 = FUN_0051adf0(*(int *)(param_1 + 0x2ae8),
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8),
                         "Bridge1_a","Bridge1_b",&local_4);
    iVar5 = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"Fight");
    if (((((iVar7 != 0) && (iVar4 != 0)) &&
         ((iVar5 != 0 &&
          (((*(uint *)(iVar4 + local_4 * 4) & 0x80000000) != 0 ||
           ((*(uint *)(iVar4 + (uint)(local_4 == 0) * 4) & 0x80000000) != 0)))))) &&
        (uVar6 = 1 << ((byte)(iVar5 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6) & 0x1f),
        (uVar6 & *(uint *)(iVar7 + 0x2b0)) == 0 &&
        ((int)uVar6 >> 0x1f & *(uint *)(iVar7 + 0x2b4)) == 0)) &&
       (iVar4 = FUN_0051ac10(*(int *)(param_1 + 0x2ae8),&DAT_0075dc98), iVar4 != 0)) {
      *(undefined4 *)(iVar7 + 0x5c) = *(undefined4 *)(iVar4 + 0x10);
      *(undefined4 *)(iVar7 + 0x60) = *(undefined4 *)(iVar4 + 0x14);
      *(undefined4 *)(iVar7 + 100) = *(undefined4 *)(iVar4 + 0x18);
      *(undefined2 *)(iVar7 + 0x27a) = *(undefined2 *)(iVar4 + 0x1c);
      *(undefined2 *)(iVar7 + 0x58) = *(undefined2 *)(iVar4 + 0x1c);
      *(undefined2 *)(iVar7 + 0x5a) = *(undefined2 *)(iVar4 + 0x1c);
      *(undefined4 *)(iVar7 + 0x420) = *(undefined4 *)(iVar4 + 0x20);
      *(undefined4 *)(iVar7 + 0x424) = *(undefined4 *)(iVar4 + 0x24);
      *(undefined4 *)(iVar7 + 0x428) = *(undefined4 *)(iVar4 + 0x28);
      *(undefined4 *)(iVar7 + 0x42c) = *(undefined4 *)(iVar4 + 0x2c);
      *(undefined4 *)(iVar7 + 0x430) = *(undefined4 *)(iVar4 + 0x30);
      uVar1 = *(undefined4 *)(iVar4 + 0x34);
      *(undefined4 *)(iVar7 + 0x80) = *(undefined4 *)(iVar7 + 0x5c);
      *(undefined4 *)(iVar7 + 0x84) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x434) = uVar1;
      *(undefined4 *)(iVar7 + 0x88) = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(iVar7 + 0x98) = *(undefined4 *)(iVar7 + 0x5c);
      _DAT_0093d620 = *(undefined4 *)(iVar7 + 0x80);
      *(undefined4 *)(iVar7 + 0x9c) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0xa0) = *(undefined4 *)(iVar7 + 100);
      DAT_0093d624 = *(undefined4 *)(iVar7 + 0x84);
      DAT_0093d628 = *(undefined4 *)(iVar7 + 0x88);
      *(undefined4 *)(iVar7 + 0x8c) = *(undefined4 *)(iVar7 + 0x80);
      uVar1 = *(undefined4 *)(iVar7 + 0x5c);
      *(undefined4 *)(iVar7 + 0x90) = *(undefined4 *)(iVar7 + 0x84);
      uVar2 = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x88);
      uVar3 = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(iVar7 + 0x1cc) = uVar1;
      *(undefined4 *)(iVar7 + 0x1b4) = uVar1;
      *(undefined4 *)(iVar7 + 0x10bc) = uVar1;
      *(undefined4 *)(iVar7 + 0x1d0) = uVar2;
      *(undefined4 *)(iVar7 + 0x1b8) = uVar2;
      *(undefined4 *)(iVar7 + 0x10c0) = uVar2;
      *(undefined4 *)(iVar7 + 0x1d4) = uVar3;
      *(undefined4 *)(iVar7 + 0x1bc) = uVar3;
      *(undefined4 *)(iVar7 + 0x10c4) = uVar3;
      *(undefined4 *)(iVar7 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)(iVar7 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)(iVar7 + 0x70) = DAT_0093b0d4;
      FUN_005728a0(iVar7);
    }
  }
  return;
}

