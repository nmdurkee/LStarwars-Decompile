/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53bc50; label: FUN_0053bc50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0053bc50(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  iVar8 = DAT_009238e4;
  if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
    uVar6 = FUN_0053b7b0();
    return uVar6;
  }
  if (*(int *)(DAT_009238e4 + 0x4868) == 0) {
    return 0;
  }
  iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
  if ((*(byte *)(*(int *)(DAT_009238e4 + 0x4868) + 0x2c) & 1) == 0) {
    DAT_00921f50 = DAT_00921f50 & 0xfffffffe;
  }
  if ((DAT_00921f50 & 1) != 0) {
    uVar5 = FUN_00522c80(*(undefined4 *)(DAT_009238e4 + 0x31b98));
    *(undefined2 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x34) = uVar5;
    if (((*(byte *)(param_1 + 0x78) & 0x40) != 0) &&
       (iVar8 = *(int *)(DAT_009238e4 + 0x4868), -1 < *(short *)(iVar8 + 0x34))) {
      *(undefined2 *)(iVar8 + 0x30) = *(undefined2 *)(iVar8 + 0x34);
    }
    if (((*(byte *)(param_1 + 0x78) & 0x10) != 0) &&
       (iVar8 = *(int *)(DAT_009238e4 + 0x4868), -1 < *(short *)(iVar8 + 0x34))) {
      *(undefined2 *)(iVar8 + 0x32) = *(undefined2 *)(iVar8 + 0x34);
    }
    if ((*(uint *)(param_1 + 0x78) & 0x100) == 0) {
      return 0;
    }
    iVar8 = *(int *)(DAT_009238e4 + 0x4868);
    if (-1 < *(short *)(iVar8 + 0x34)) {
      *(undefined2 *)(iVar8 + 0x30) = *(undefined2 *)(iVar8 + 0x34);
      FUN_00620f10(*(short *)(*(int *)(DAT_009238e4 + 0x4868) + 0x34) * 0x5c + 4 +
                   *(int *)(*(int *)(DAT_009238e4 + 0x31b98) + 0x7c));
    }
    uVar6 = FUN_00522a00(0);
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
    iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (iVar8 == 0) {
      return 0;
    }
    FUN_00620f10(iVar8 + 0x18);
    return 0;
  }
  if ((*(byte *)(param_1 + 0x70) & 0x40) != 0) {
    iVar1 = *(int *)(DAT_009238e4 + 0x4868);
    iVar2 = *(int *)(iVar1 + 0x24);
    if (iVar2 == 0) {
      if ((*(byte *)(param_1 + 0x78) & 0x40) != 0) {
        uVar6 = FUN_00522970();
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
        if (iVar9 != 0) {
          iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          if (iVar8 != 0) {
            *(undefined4 *)(iVar8 + 0x24) = *(undefined4 *)(iVar9 + 0x24);
            *(undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x2c) =
                 *(undefined4 *)(iVar9 + 0x2c);
            *(undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x28) =
                 *(undefined4 *)(iVar9 + 0x28);
          }
          iVar8 = FUN_00522d50(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
          if (iVar8 == 0) {
            FUN_00532220(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20),
                         *(int *)(DAT_009238e4 + 0x4868));
            *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = iVar9;
          }
        }
      }
    }
    else if ((*(byte *)(param_1 + 0x78) & 0x40) == 0) {
      iVar9 = *(int *)(iVar1 + 0x20);
      if ((iVar9 != 0) && (iVar2 == iVar9)) {
        local_c = *(float *)(iVar9 + 0x18);
        local_8 = *(undefined4 *)(iVar9 + 0x1c);
        local_4 = *(float *)(iVar9 + 0x20);
        *(undefined4 *)(iVar9 + 0x18) = *(undefined4 *)(DAT_009238e4 + 0x28);
        *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar8 + 0x2c);
        *(undefined4 *)(iVar9 + 0x20) = *(undefined4 *)(iVar8 + 0x30);
        FUN_00533810();
        FUN_00522100(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
        if (DAT_009238f0 != (code *)0x0) {
          (*DAT_009238f0)(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
        }
        if ((*(uint *)(param_1 + 0x70) & 0x200) != 0) {
          iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          local_c = *(float *)(iVar8 + 0x18) - local_c;
          local_4 = *(float *)(iVar8 + 0x20) - local_4;
          for (iVar8 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18); iVar8 != 0;
              iVar8 = FUN_004f1460(*(int *)(DAT_009238e4 + 0x4868) + 0x18,iVar8)) {
            if (iVar8 != *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20)) {
              *(float *)(iVar8 + 0x18) = *(float *)(iVar8 + 0x18) + local_c;
              *(float *)(iVar8 + 0x20) = local_4 + *(float *)(iVar8 + 0x20);
              FUN_00522100(iVar8);
              if (DAT_009238f0 != (code *)0x0) {
                (*DAT_009238f0)(iVar8);
              }
            }
          }
        }
      }
    }
    else {
      *(int *)(iVar1 + 0x20) = iVar2;
      iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
      if (iVar8 != 0) {
        local_c = *(float *)(iVar8 + 0x18);
        local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
        local_4 = *(float *)(iVar8 + 0x20);
        FUN_00620f10(&local_c);
      }
    }
  }
  if ((*(byte *)(param_1 + 0x78) & 0x20) != 0) {
    iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
    if (((iVar8 != 0) && (iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24), iVar9 != 0)) &&
       (iVar9 != iVar8)) {
      uVar10 = FUN_00522d20();
      if ((int)uVar10 != 0) {
        uVar6 = FUN_00538cb0();
        return uVar6;
      }
      FUN_00522d50((int)((ulonglong)uVar10 >> 0x20));
      local_c = *(float *)(iVar9 + 0x18);
      local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
      local_4 = *(float *)(iVar9 + 0x20);
      FUN_00620f10(&local_c);
    }
  }
  if ((((*(uint *)(param_1 + 0x78) & 0x10) != 0) &&
      (iVar8 = *(int *)(DAT_009238e4 + 0x4868), *(int *)(iVar8 + 0x20) != 0)) &&
     (*(int *)(iVar8 + 0x20) == *(int *)(iVar8 + 0x24))) {
    uVar6 = FUN_00538c10();
    return uVar6;
  }
  if ((*(uint *)(param_1 + 0x78) & 0x100) != 0) {
    if ((DAT_00921f50 & 2) == 0) {
      uVar6 = FUN_00522a00(0);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
      if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) != 0) {
        if (((_DAT_009242a8 != 0.0) || (_DAT_009242ac != 0.0)) || (_DAT_009242b0 != 0.0)) {
          iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x18;
          FUN_005b37d0(iVar8,iVar8,&DAT_009242a8);
          FUN_00533810();
          FUN_00522100(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
        }
        FUN_00620f10(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x18);
      }
    }
    else {
      FUN_00522c30();
    }
  }
  *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) & 0xfffffffe;
  iVar8 = *(int *)(DAT_009238e4 + 0x4868);
  if ((*(int *)(iVar8 + 0x20) != 0) && (*(int *)(iVar8 + 0x20) == *(int *)(iVar8 + 0x24))) {
    if ((*(uint *)(param_1 + 0x70) & 0x8000) == 0) {
      if ((*(uint *)(param_1 + 0x70) & 0x2000) != 0) {
        iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        fVar3 = *(float *)(iVar8 + 0x24) * 1.01;
        goto LAB_0053c1d3;
      }
    }
    else {
      iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
      fVar3 = *(float *)(iVar8 + 0x24) * 0.99;
LAB_0053c1d3:
      *(float *)(iVar8 + 0x24) = fVar3;
      iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
      if (*(float *)(iVar8 + 0x24) < 0.01) {
        *(undefined4 *)(iVar8 + 0x24) = 0x3c23d70a;
      }
      FUN_00533810();
      FUN_00522100(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
      if (DAT_009238f0 != (code *)0x0) {
        (*DAT_009238f0)(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
      }
    }
    if ((DAT_00921f50 & 0x80) != 0) {
      if ((*(uint *)(param_1 + 0x70) & 0x1000) == 0) {
        if ((*(uint *)(param_1 + 0x70) & 0x4000) == 0) goto LAB_0053c36c;
        *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 4;
        fVar3 = -*(float *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x28) * 0.05;
        if ((*(uint *)(param_1 + 0x70) & 4) == 0) {
          if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
            iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
            fVar3 = *(float *)(iVar8 + 0x28) - fVar3;
            goto LAB_0053c33d;
          }
        }
        else {
          iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          fVar3 = *(float *)(iVar8 + 0x28) + fVar3;
LAB_0053c33d:
          *(float *)(iVar8 + 0x28) = fVar3;
        }
        iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        if (-0.01 < *(float *)(iVar8 + 0x28)) {
          *(undefined4 *)(iVar8 + 0x28) = 0xbc23d70a;
        }
      }
      else {
        *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 4;
        fVar3 = *(float *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x2c) * 0.05;
        if ((*(uint *)(param_1 + 0x70) & 4) == 0) {
          if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
            iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
            fVar3 = *(float *)(iVar8 + 0x2c) - fVar3;
            goto LAB_0053c2b1;
          }
        }
        else {
          iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          fVar3 = *(float *)(iVar8 + 0x2c) + fVar3;
LAB_0053c2b1:
          *(float *)(iVar8 + 0x2c) = fVar3;
        }
        iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        if (*(float *)(iVar8 + 0x2c) < 0.01) {
          *(undefined4 *)(iVar8 + 0x2c) = 0x3c23d70a;
        }
      }
    }
LAB_0053c36c:
    *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 1;
  }
  bVar4 = false;
  uVar7 = *(uint *)(param_1 + 0x70) & 0x100;
  if ((uVar7 == 0) || ((*(byte *)(param_1 + 0x78) & 8) == 0)) {
    if (uVar7 == 0) {
LAB_0053c66d:
      if ((DAT_00921f50 & 0x80) != 0) goto LAB_0053c644;
      if ((*(uint *)(param_1 + 0x78) & 0x1000) != 0) goto LAB_0053c3b3;
      if ((*(uint *)(param_1 + 0x78) & 0x4000) == 0) goto LAB_0053c644;
    }
    else if ((*(byte *)(param_1 + 0x78) & 2) == 0) {
      if (uVar7 != 0) {
        if ((*(byte *)(param_1 + 0x78) & 4) != 0) {
          bVar4 = true;
          goto LAB_0053c3b3;
        }
        if ((uVar7 != 0) && ((*(byte *)(param_1 + 0x78) & 1) != 0)) {
          bVar4 = true;
          goto LAB_0053c4f7;
        }
      }
      goto LAB_0053c66d;
    }
LAB_0053c4f7:
    iVar8 = *(int *)(DAT_009238e4 + 0x4868);
    if (*(int *)(iVar8 + 0x20) != 0) {
      uVar6 = FUN_004f1470(iVar8 + 0x18,*(undefined4 *)(iVar8 + 0x20));
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
    }
    if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) == 0) {
      uVar6 = FUN_004f1450(*(int *)(DAT_009238e4 + 0x4868) + 0x18);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
    }
    if (((bVar4) && (iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20), iVar8 != 0)) &&
       (iVar8 = FUN_004f1ff0(iVar8 + 8), iVar8 == 0)) {
      iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
      do {
        uVar6 = FUN_004f1470(*(int *)(DAT_009238e4 + 0x4868) + 0x18,
                             *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
        iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        if (iVar9 == 0) {
          uVar6 = FUN_004f1450(*(int *)(DAT_009238e4 + 0x4868) + 0x18);
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
          iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          if (iVar9 == 0) break;
        }
        if ((iVar9 == iVar8) || (iVar9 = FUN_004f1ff0(iVar9 + 8), iVar9 != 0)) break;
      } while( true );
    }
  }
  else {
LAB_0053c3b3:
    iVar8 = *(int *)(DAT_009238e4 + 0x4868);
    if (*(int *)(iVar8 + 0x20) != 0) {
      uVar6 = FUN_004f1460(iVar8 + 0x18,*(undefined4 *)(iVar8 + 0x20));
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
    }
    if (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) == 0) {
      uVar6 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
    }
    if (((bVar4) && (iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20), iVar8 != 0)) &&
       (iVar8 = FUN_004f1ff0(iVar8 + 8), iVar8 == 0)) {
      iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
      do {
        uVar6 = FUN_004f1460(*(int *)(DAT_009238e4 + 0x4868) + 0x18,
                             *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
        iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
        if (iVar9 == 0) {
          uVar6 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18);
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) = uVar6;
          iVar9 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
          if (iVar9 == 0) break;
        }
        if ((iVar9 == iVar8) || (iVar9 = FUN_004f1ff0(iVar9 + 8), iVar9 != 0)) break;
      } while( true );
    }
  }
  iVar8 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
  if (iVar8 != 0) {
    FUN_00620f10(iVar8 + 0x18);
  }
LAB_0053c644:
  uVar6 = FUN_00522a00(1);
  *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24) = uVar6;
  return 0;
}

