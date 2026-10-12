/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68b3b0; label: FUN_0068b3b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0068b3b0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar5 = 0;
  if (DAT_029629e0 != DAT_02962a08) {
    if ((DAT_00810a90 == -1) && (DAT_00810a88 == 3)) {
      if ((DAT_029629d8 != 0x3000) && (DAT_02962a20 != DAT_02962a0c)) {
LAB_0068b40c:
        piVar4 = (int *)(DAT_02962a14 + 4);
        iVar6 = *(int *)(DAT_02962a14 + 4);
        while (iVar6 != 0) {
          piVar4 = piVar4 + 0x14;
          iVar7 = iVar7 + 1;
          iVar6 = *piVar4;
        }
        iVar6 = iVar7 * 0x50;
        if (DAT_00810a90 == -1) {
          *(undefined4 *)(iVar6 + DAT_02962a14) = DAT_029211ec;
          if (DAT_00810a88 == 3) {
            *(undefined4 *)(iVar6 + 4 + DAT_02962a14) = 1;
          }
          else {
            *(int *)(iVar6 + 4 + DAT_02962a14) = DAT_0292318c;
          }
          *(undefined4 *)(iVar6 + 0x18 + DAT_02962a14) = 0x3e4ccccd;
          *(undefined4 *)(iVar6 + 0x1c + DAT_02962a14) = 1;
          *(undefined4 *)(iVar6 + 0x20 + DAT_02962a14) = 0x3f800000;
          *(undefined1 *)(iVar6 + 0x24 + DAT_02962a14) = DAT_029629e8;
          uVar3 = FUN_005b9e90(0);
          *(undefined4 *)(iVar6 + 0x28 + DAT_02962a14) = uVar3;
          *(undefined1 *)(iVar6 + 0x25 + DAT_02962a14) = 1;
          *(undefined1 *)(iVar6 + 0x26 + DAT_02962a14) = 1;
          *(undefined1 *)(iVar6 + 0x27 + DAT_02962a14) = (undefined1)DAT_00810a88;
          *(undefined4 *)(iVar6 + 0x2c + DAT_02962a14) = 0;
          *(undefined4 *)(iVar6 + 0x30 + DAT_02962a14) = 0x3f800000;
          *(undefined4 *)(iVar6 + 0x38 + DAT_02962a14) = _DAT_00810a98;
          *(undefined4 *)(iVar6 + 0x3c + DAT_02962a14) = _DAT_00810a9c;
          *(undefined1 *)(iVar6 + 0x42 + DAT_02962a14) = 1;
          *(undefined4 *)(iVar6 + 0x44 + DAT_02962a14) = 0;
          *(undefined1 *)(iVar6 + 0x43 + DAT_02962a14) = 1;
        }
        else {
          *(undefined4 *)(iVar6 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + DAT_02962a14);
          *(int *)(iVar6 + 4 + DAT_02962a14) = DAT_0292318c;
          *(undefined4 *)(iVar6 + 0x18 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x18 + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x1c + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x1c + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x20 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x20 + DAT_02962a14);
          *(undefined1 *)(iVar6 + 0x24 + DAT_02962a14) = DAT_029629e8;
          uVar3 = FUN_005b9e90(0);
          *(undefined4 *)(iVar6 + 0x28 + DAT_02962a14) = uVar3;
          *(undefined1 *)(iVar6 + 0x25 + DAT_02962a14) =
               *(undefined1 *)(DAT_00810a90 * 0x50 + 0x25 + DAT_02962a14);
          *(undefined1 *)(iVar6 + 0x26 + DAT_02962a14) =
               *(undefined1 *)(DAT_00810a90 * 0x50 + 0x26 + DAT_02962a14);
          *(undefined1 *)(iVar6 + 0x27 + DAT_02962a14) =
               *(undefined1 *)(DAT_00810a90 * 0x50 + 0x27 + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x2c + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x2c + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x30 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x30 + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x38 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x38 + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x3c + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x3c + DAT_02962a14);
          *(undefined1 *)(iVar6 + 0x42 + DAT_02962a14) =
               *(undefined1 *)(DAT_00810a90 * 0x50 + 0x42 + DAT_02962a14);
          *(undefined4 *)(iVar6 + 0x44 + DAT_02962a14) =
               *(undefined4 *)(DAT_00810a90 * 0x50 + 0x44 + DAT_02962a14);
          *(undefined1 *)(iVar6 + 0x43 + DAT_02962a14) =
               *(undefined1 *)(DAT_00810a90 * 0x50 + 0x43 + DAT_02962a14);
        }
        if (*(char *)(iVar6 + 0x27 + DAT_02962a14) == '\x03') {
          iVar1 = *DAT_02962a1c;
          while (iVar1 != 0) {
            iVar5 = iVar5 + 1;
            iVar1 = DAT_02962a1c[iVar5];
          }
          *(short *)(iVar6 + 0x40 + DAT_02962a14) = (short)iVar5;
          DAT_02962a1c[iVar5] = 1;
          *(undefined4 *)(DAT_02962a10 * iVar5 * 0x20 + DAT_02962a18) = 0;
          *(undefined4 *)(DAT_02962a10 * iVar5 * 0x20 + 4 + DAT_02962a18) = 0;
          *(undefined4 *)(DAT_02962a10 * iVar5 * 0x20 + 8 + DAT_02962a18) = 0;
          *(undefined4 *)(DAT_02962a10 * iVar5 * 0x20 + 0xc + DAT_02962a18) = 0x3f800000;
          *(undefined2 *)(DAT_02962a10 * iVar5 * 0x20 + 0x10 + DAT_02962a18) =
               (undefined2)DAT_029629ec;
          *(undefined2 *)(DAT_02962a10 * iVar5 * 0x20 + 0x12 + DAT_02962a18) =
               (undefined2)DAT_029629f0;
          DAT_02962a20 = DAT_02962a20 + 1;
        }
        else {
          *(undefined2 *)(iVar6 + 0x40 + DAT_02962a14) = 0xffff;
        }
        iVar5 = _DAT_029629e8;
        uVar3 = DAT_0296291c;
        DAT_029629e0 = DAT_029629e0 + 1;
        if ((&DAT_02920acc)[_DAT_029629e8] == 0) {
          *(undefined4 *)(&DAT_02961f54 + _DAT_029629e8 * 4) = DAT_02962114;
          uVar2 = DAT_02962a00;
          (&DAT_02920acc)[iVar5] = 1;
          *(undefined4 *)(&DAT_02921844 + iVar5 * 4) = uVar3;
          *(undefined4 *)(&DAT_0292fce8 + iVar5 * 4) = uVar2;
        }
        *(undefined4 *)(iVar6 + 0x4c + DAT_02962a14) = DAT_029629fc;
        DAT_00810a8c = iVar7;
        FUN_0068b170(iVar7,param_1);
        return iVar7;
      }
    }
    else if (DAT_0292318c + DAT_029629d8 < 0x3001) goto LAB_0068b40c;
  }
  return -1;
}

