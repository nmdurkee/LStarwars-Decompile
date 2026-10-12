/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee940; label: FUN_005ee940
 */

void FUN_005ee940(int param_1,undefined4 param_2,undefined4 param_3,short param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  uint local_8;
  
  iVar6 = param_5;
  uVar5 = param_3;
  iVar2 = param_1;
  sVar4 = (short)param_3;
  iVar1 = *(int *)(param_1 + 0x78) + sVar4 * 0x18;
  iVar3 = 0;
  if (0 < param_5 + -1) {
    do {
      if ((&DAT_00963f54)[iVar3] == sVar4) {
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5 + -1);
  }
  if (param_5 < 0x10) {
    bVar7 = sVar4 == DAT_00971abc;
    (&DAT_00963f54)[param_5] = sVar4;
    if (bVar7) {
      FUN_00600be0(iVar1,param_1);
    }
    else {
      FUN_00600d00(param_1,iVar1,param_2);
    }
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 4;
    if ((iVar6 < *(int *)(iVar2 + 0xe4)) && (local_8 = 0, *(char *)(iVar1 + 0xf) != '\0')) {
      do {
        iVar6 = *(short *)(*(int *)(iVar1 + 8) + local_8 * 2) * 0x20 + *(int *)(iVar2 + 0x70);
        sVar4 = *(short *)(iVar6 + 0x16);
        if (sVar4 == (short)uVar5) {
          sVar4 = *(short *)(iVar6 + 0x18);
        }
        if (sVar4 != param_4) {
          if ((*(byte *)(iVar6 + 0x1c) & 1) == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_005d9ce0(iVar6,param_2,sVar4);
          }
          if (iVar3 != 0) {
            if (iVar3 == 1) {
              FUN_005edf10(iVar6,*(int *)(iVar2 + 0x78) + sVar4 * 0x18);
              param_1 = FUN_005da100((int)sVar4);
              FUN_005ee940(iVar2,param_1,sVar4,param_3,param_5 + 1);
              uVar5 = param_3;
            }
            else if (iVar3 == 2) {
              iVar6 = FUN_005ee750(iVar6,*(int *)(iVar2 + 0x78) + sVar4 * 0x18,(int)sVar4,param_2,
                                   &param_1);
              if (iVar6 == 1) {
                FUN_005ee940(iVar2,param_1,sVar4,uVar5,param_5 + 1);
              }
              else if (iVar6 == 4) {
                param_1 = FUN_005d91b0(param_2);
                *(short *)(param_1 + 0x9e) = sVar4;
                FUN_005ee940(iVar2,param_1,sVar4,uVar5,param_5 + 1);
              }
            }
            else {
              FUN_005ee940(iVar2,param_2,sVar4,uVar5,param_5 + 1);
            }
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(byte *)(iVar1 + 0xf));
    }
  }
  return;
}

