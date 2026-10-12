/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ebda0; label: FUN_004ebda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ebda0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  int *local_4;
  
  if (DAT_00951b50 == 0) {
    if (DAT_0093b2a4 == 0) {
      FUN_00489820((int)DAT_007f19ec,0,0x3e99999a,(int)*(short *)(DAT_0087b290 + 0x62));
    }
    else {
      FUN_004897f0((int)DAT_007f19ec,0,0x3e99999a);
    }
  }
  if (DAT_0087a7f0 != 0) {
    *(undefined4 *)(DAT_0087a7f0 + 0xeb8) = 0;
    *(undefined4 *)(DAT_0087a7f0 + 0xebc) = 0;
    iVar1 = DAT_0087a7f0;
    if (DAT_00876848 == '\0') {
      local_4 = &DAT_0093d7f4;
      do {
        iVar2 = DAT_0087a7f0;
        iVar1 = local_4[-1];
        if ((iVar1 != 0) &&
           ((((DAT_0087a95c != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a95c - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)) ||
             ((DAT_0087a960 != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a960 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))) ||
            ((DAT_0087a964 != 0 &&
             (uVar3 = 1 << ((byte)(DAT_0087a964 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                           & 0x1f),
             (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
             ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
          puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
          uVar5 = __allshl();
          *puVar4 = *puVar4 | (uint)uVar5;
          *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
        }
        iVar2 = DAT_0087a7f0;
        iVar1 = *local_4;
        if ((iVar1 != 0) &&
           ((((DAT_0087a95c != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a95c - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)) ||
             ((DAT_0087a960 != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a960 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))) ||
            ((DAT_0087a964 != 0 &&
             (uVar3 = 1 << ((byte)(DAT_0087a964 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                           & 0x1f),
             (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
             ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
          puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
          uVar5 = __allshl();
          *puVar4 = *puVar4 | (uint)uVar5;
          *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
        }
        iVar2 = DAT_0087a7f0;
        iVar1 = local_4[1];
        if ((iVar1 != 0) &&
           ((((DAT_0087a95c != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a95c - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)) ||
             ((DAT_0087a960 != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a960 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))) ||
            ((DAT_0087a964 != 0 &&
             (uVar3 = 1 << ((byte)(DAT_0087a964 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                           & 0x1f),
             (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
             ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
          puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
          uVar5 = __allshl();
          *puVar4 = *puVar4 | (uint)uVar5;
          *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
        }
        iVar2 = DAT_0087a7f0;
        iVar1 = local_4[2];
        if ((iVar1 != 0) &&
           ((((DAT_0087a95c != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a95c - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)) ||
             ((DAT_0087a960 != 0 &&
              (uVar3 = 1 << ((byte)(DAT_0087a960 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                            & 0x1f),
              (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
              ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))) ||
            ((DAT_0087a964 != 0 &&
             (uVar3 = 1 << ((byte)(DAT_0087a964 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6)
                           & 0x1f),
             (uVar3 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
             ((int)uVar3 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
          puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
          uVar5 = __allshl();
          *puVar4 = *puVar4 | (uint)uVar5;
          *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
        }
        local_4 = local_4 + 4;
      } while ((int)local_4 < 0x93d814);
    }
    else {
      if (DAT_0093d7f0 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d7f4 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d7f8 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d7fc != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d800 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d804 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d808 != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
      iVar1 = DAT_0087a7f0;
      if (DAT_0093d80c != 0) {
        puVar4 = (uint *)(DAT_0087a7f0 + 0xeb8);
        uVar5 = __allshl();
        *puVar4 = *puVar4 | (uint)uVar5;
        *(uint *)(iVar1 + 0xebc) = *(uint *)(iVar1 + 0xebc) | (uint)((ulonglong)uVar5 >> 0x20);
      }
    }
  }
  if (((DAT_0087a96c == (int *)0x0) || (iVar1 = *DAT_0087a96c, iVar1 == 0)) ||
     ((*(byte *)(iVar1 + 0x94) & 1) == 0)) {
    DAT_0087aa26 = '\0';
  }
  else if (DAT_0087aa26 == '\0') {
    FUN_00681f40("exp_minecart",iVar1 + 0x30);
    DAT_0087aa26 = '\x01';
  }
  if (((DAT_0087a970 == (int *)0x0) || (iVar1 = *DAT_0087a970, iVar1 == 0)) ||
     ((*(byte *)(iVar1 + 0x94) & 1) == 0)) {
    DAT_0087aa27 = '\0';
  }
  else if (DAT_0087aa27 == '\0') {
    FUN_00681f40("exp_minecart",iVar1 + 0x30);
    DAT_0087aa27 = 1;
    return;
  }
  return;
}

