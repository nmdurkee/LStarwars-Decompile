/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee750; label: FUN_005ee750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005ee750(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar5 = (int)*(short *)(param_1 + 0x14);
  iVar6 = 0;
  iVar7 = 0;
  if (3 < iVar5) {
    iVar2 = (iVar5 - 4U >> 2) + 1;
    pfVar4 = (float *)(*(int *)(param_1 + 0x10) + 8);
    pfVar3 = (float *)(*(int *)(param_1 + 0x10) + 0x14);
    iVar7 = iVar2 * 4;
    do {
      if (0.0 < *pfVar4 * _DAT_00963f80 + pfVar4[-2] * _DAT_00963f78 + pfVar4[-1] * _DAT_00963f7c +
                _DAT_00963f84) {
        iVar6 = iVar6 + 1;
      }
      if (0.0 < *pfVar3 * _DAT_00963f80 + pfVar4[1] * _DAT_00963f78 + pfVar3[-1] * _DAT_00963f7c +
                _DAT_00963f84) {
        iVar6 = iVar6 + 1;
      }
      if (0.0 < pfVar3[3] * _DAT_00963f80 + pfVar4[4] * _DAT_00963f78 + pfVar3[2] * _DAT_00963f7c +
                _DAT_00963f84) {
        iVar6 = iVar6 + 1;
      }
      if (0.0 < pfVar3[6] * _DAT_00963f80 + pfVar4[7] * _DAT_00963f78 + pfVar3[5] * _DAT_00963f7c +
                _DAT_00963f84) {
        iVar6 = iVar6 + 1;
      }
      pfVar4 = pfVar4 + 0xc;
      pfVar3 = pfVar3 + 0xc;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (iVar7 < iVar5) {
    pfVar4 = (float *)(*(int *)(param_1 + 0x10) + iVar7 * 0xc);
    iVar7 = iVar5 - iVar7;
    do {
      if (0.0 < pfVar4[2] * _DAT_00963f80 + _DAT_00963f78 * *pfVar4 + pfVar4[1] * _DAT_00963f7c +
                _DAT_00963f84) {
        iVar6 = iVar6 + 1;
      }
      pfVar4 = pfVar4 + 3;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (iVar6 != 0) {
    if (iVar6 != iVar5) {
      return 4;
    }
    FUN_005d9f50(param_1,local_18,local_c);
    uVar8 = FUN_005da040(local_c,local_18);
    if ((int)uVar8 != 0) {
      FUN_005ee440(param_1,param_2,(int)((ulonglong)uVar8 >> 0x20));
      uVar1 = FUN_005d9a00(local_c,local_18,param_3);
      *param_5 = uVar1;
      return 1;
    }
  }
  return 0;
}

