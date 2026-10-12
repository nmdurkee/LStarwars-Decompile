/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53c7c0; label: FUN_0053c7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0053c7c0(int param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int local_14;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = *(uint *)(param_1 + 0x78);
  if ((char)uVar1 < '\0') {
    uVar3 = FUN_0053c690();
    return uVar3;
  }
  if (*(int *)(DAT_009238e4 + 0x4868) == 0) {
    return 0;
  }
  if ((uVar1 & 0x1000) == 0) {
    if ((uVar1 & 0x4000) != 0) {
      iVar4 = *(int *)(DAT_009238e4 + 0x4868);
      if (*(int *)(iVar4 + 0x28) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(iVar4 + 0x28) - iVar4) + -0x40 >> 5;
      }
      iVar5 = 0;
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 0) {
          iVar4 = 0xf;
        }
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
             (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
        if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
        iVar4 = iVar4 + -1;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
        if (iVar4 < 0) {
          iVar4 = 0xf;
        }
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
             (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
        if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
        iVar4 = iVar4 + -1;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
        if (iVar4 < 0) {
          iVar4 = 0xf;
        }
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
             (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
        if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
        iVar4 = iVar4 + -1;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
        if (iVar4 < 0) {
          iVar4 = 0xf;
        }
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
             (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
        if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
        iVar5 = iVar5 + 4;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
      } while (iVar5 < 0x10);
    }
  }
  else {
    iVar4 = *(int *)(DAT_009238e4 + 0x4868);
    if (*(int *)(iVar4 + 0x28) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(iVar4 + 0x28) - iVar4) + -0x40 >> 5;
    }
    iVar5 = 0;
    do {
      iVar4 = iVar4 + 1;
      if (0xf < iVar4) {
        iVar4 = 0;
      }
      *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
           (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
      if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
      if (0xf < iVar4) {
        iVar4 = 0;
      }
      *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
           (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
      if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
      if (0xf < iVar4) {
        iVar4 = 0;
      }
      *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
           (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
      if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
      if (0xf < iVar4) {
        iVar4 = 0;
      }
      *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
           (iVar4 + 2) * 0x20 + *(int *)(DAT_009238e4 + 0x4868);
      if ((*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0) break;
      iVar5 = iVar5 + 4;
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
    } while (iVar5 < 0x10);
  }
  iVar4 = *(int *)(DAT_009238e4 + 0x4868);
  if (*(int *)(iVar4 + 0x28) == 0) {
    return 0;
  }
  if ((((*(byte *)(param_1 + 0x70) & 0x40) != 0) && (*(int *)(iVar4 + 0x24) != 0)) &&
     ((*(byte *)(param_1 + 0x78) & 0x40) != 0)) {
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x24);
    iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (iVar4 != 0) {
      local_c = *(undefined4 *)(iVar4 + 0x18);
      local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
      local_4 = *(undefined4 *)(iVar4 + 0x20);
      FUN_00620f10(&local_c);
    }
  }
  if ((*(byte *)(param_1 + 0x78) & 0x20) != 0) {
    iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (((iVar4 != 0) && (iVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24), iVar5 != 0)) &&
       (iVar5 != iVar4)) {
      iVar4 = FUN_005266b0(iVar4,iVar5);
      FUN_005266b0(iVar5,*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
      if (iVar4 == 1) {
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = iVar5;
        iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        local_c = *(undefined4 *)(iVar4 + 0x18);
        local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
        local_4 = *(undefined4 *)(iVar4 + 0x20);
      }
      else {
        if (iVar4 != -1) goto LAB_0053cb7a;
        *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = iVar5;
        iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        local_c = *(undefined4 *)(iVar4 + 0x18);
        local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
        local_4 = *(undefined4 *)(iVar4 + 0x20);
      }
      FUN_00620f10(&local_c);
    }
  }
LAB_0053cb7a:
  iVar4 = DAT_009238e4;
  if (((*(byte *)(param_1 + 0x78) & 0x10) != 0) &&
     (iVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24), iVar5 != 0)) {
    local_14 = 0;
    puVar6 = (ushort *)(iVar5 + 0x38);
    do {
      if ((*(int *)(puVar6 + -4) != 0) && (uVar2 = __allshl(), (uVar2 & *puVar6) != 0)) {
        uVar2 = __allshl();
        if ((*(ushort *)(iVar5 + 0x96) & uVar2) == 0) {
          puVar6 = (ushort *)(*(int *)(*(int *)(iVar4 + 0x4868) + 0x24) + 0x96);
          *puVar6 = *puVar6 | uVar2;
        }
        else {
          puVar6 = (ushort *)(*(int *)(*(int *)(iVar4 + 0x4868) + 0x24) + 0x96);
          *puVar6 = *puVar6 & ~uVar2;
        }
        break;
      }
      local_14 = local_14 + 1;
      puVar6 = puVar6 + 6;
    } while (local_14 < 8);
  }
  if ((*(uint *)(param_1 + 0x78) & 0x100) != 0) {
    uVar3 = FUN_00522a00(0);
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar3;
    iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (iVar4 != 0) {
      FUN_00620f10(iVar4 + 0x18);
    }
  }
  uVar3 = FUN_00522a00(1);
  *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24) = uVar3;
  *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) & 0xfffffffe;
  iVar4 = *(int *)(DAT_009238e4 + 0x4868);
  if ((*(int *)(iVar4 + 0x20) != 0) && (*(int *)(iVar4 + 0x20) == *(int *)(iVar4 + 0x24))) {
    *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 1;
  }
  return 0;
}

