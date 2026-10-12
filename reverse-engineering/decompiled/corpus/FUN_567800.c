/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x567800; label: FUN_00567800
 */

undefined4
FUN_00567800(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6)

{
  float fVar1;
  short sVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  
  bVar7 = false;
  if ((param_1 == 0) || ((*(uint *)(param_1 + 0x94) & 0x800000) == 0)) {
    return 0;
  }
  if (((*(byte *)(param_1 + 0x98) & 0x20) != 0) && (DAT_0087baf0 == 0)) {
    return 0;
  }
  iVar9 = FUN_005d0420(*(int *)(param_1 + 0xa4) + 0x30);
  if ((iVar9 != 0) &&
     (iVar10 = *(int *)(param_1 + 0xa4), *(float *)(iVar10 + 0x8c) != *(float *)(iVar10 + 0x88))) {
    if (((*(uint *)(iVar10 + 0x7c) & 0x2000) == 0) &&
       (uVar3 = *(uint *)(param_1 + 0x94), (uVar3 & 0x400000) == 0)) {
      if ((*(uint *)(param_1 + 0x98) & 0x208) == 0) {
        if (*(float *)(param_1 + 0xbc) < *(float *)(iVar10 + 0x8c)) {
          *(uint *)(param_1 + 0x94) = uVar3 | 0x80000;
          return 0;
        }
        *(uint *)(param_1 + 0x94) = uVar3 & 0xfff7ffff;
      }
    }
    else {
      if ((*(uint *)(param_1 + 0x98) & 0x800000) == 0) {
        if (*(float *)(param_1 + 0xbc) < *(float *)(iVar10 + 0x88)) {
          return 0;
        }
        fVar1 = *(float *)(param_1 + 0xbc);
      }
      else {
        if (*(float *)(iVar9 + 0x4c) < *(float *)(iVar10 + 0x88)) {
          return 0;
        }
        fVar1 = *(float *)(iVar9 + 0x4c);
      }
      if (*(float *)(iVar10 + 0x8c) < fVar1) {
        return 0;
      }
    }
  }
  iVar9 = *(int *)(param_1 + 0xa4);
  switch(param_3) {
  case 1:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;
    break;
  case 2:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
    break;
  case 3:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 8;
    break;
  case 4:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x20;
    break;
  case 5:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;
    break;
  case 6:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x40;
    break;
  case 7:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x80;
    break;
  case 8:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x100;
    break;
  case 9:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x200;
    break;
  case 10:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x400;
    break;
  case 0xb:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x800;
    break;
  case 0xc:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x1000;
    break;
  case 0xd:
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x2000;
  }
  iVar10 = FUN_005cfac0(iVar9 + 0x54);
  if ((iVar10 != 0) && (iVar11 = FUN_005d0420(iVar9 + 0x54), iVar11 != 0)) {
    *(uint *)(iVar11 + 0x50) = *(uint *)(iVar11 + 0x50) | 1;
  }
  if ((param_4 == -1) ||
     (*(char *)(param_1 + 0x110) = *(char *)(param_1 + 0x110) - (char)param_4,
     *(char *)(param_1 + 0x110) < '\x01')) {
    *(undefined1 *)(param_1 + 0x110) = 0;
    bVar7 = true;
    if (((*(uint *)(*(int *)(param_1 + 0xa4) + 0x7c) & 0x2000) != 0) &&
       ((*(uint *)(param_1 + 0x98) & 0x800000) != 0)) {
      FUN_005cfc00(iVar9 + 0x30,0);
    }
    *(undefined4 *)(param_1 + 0xbc) = 0x3f800000;
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfe733fff | 1;
    if (param_5 == 0) {
      if (((((*(uint *)(param_1 + 0x98) & 8) != 0) || ((*(uint *)(param_1 + 0x98) & 0x200) != 0)) &&
          (*(char *)(param_1 + 0x10e) != '\0')) &&
         ((0.0 < *(float *)(param_1 + 0xac) || (*(float *)(param_1 + 0xb0) <= 0.0)))) {
        fVar1 = *(float *)(param_1 + 0xac);
        piVar12 = &DAT_0093d7f0;
        do {
          iVar11 = *piVar12;
          if (((iVar11 != 0) && ((*(uint *)(iVar11 + 0x1fc) & 1) != 0)) &&
             (((*(uint *)(iVar11 + 0x1fc) & 0x1000) != 0 &&
              (((*(char *)(iVar11 + 0x28b) == '\0' && (*(float *)(iVar11 + 0x1010) <= 0.0)) &&
               (fVar4 = *(float *)(param_1 + 0x4c) - *(float *)(iVar11 + 0x80),
               fVar5 = *(float *)(param_1 + 0x50) - *(float *)(iVar11 + 0x84),
               fVar6 = *(float *)(param_1 + 0x54) - *(float *)(iVar11 + 0x88),
               fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5 < fVar1 * fVar1)))))) {
            FUN_00438230(0,iVar11,*(undefined1 *)(param_1 + 0x10e),1,0,param_6);
          }
          piVar12 = piVar12 + 1;
        } while ((int)piVar12 < 0x93d810);
      }
    }
    else if (*(char *)(param_1 + 0x10e) != '\0') {
      FUN_00438230(0,param_5,*(char *)(param_1 + 0x10e),1,0,param_6);
    }
    sVar2 = *(short *)(param_1 + 0x102);
    if (sVar2 != -1) {
      uVar13 = 0;
      if (iVar10 == 0) {
LAB_00567c12:
        FUN_0067c8e0((int)sVar2,uVar13);
      }
      else {
        FUN_0067c8e0((int)sVar2,0);
        sVar2 = *(short *)(param_1 + 0x104);
        if (sVar2 != -1) {
          uVar13 = 1;
          goto LAB_00567c12;
        }
      }
      if ((*(uint *)(iVar9 + 0x7c) & 0x2000) != 0) {
        FUN_005cfc00(iVar9 + 0x30,0);
      }
    }
    if (((*(uint *)(param_1 + 0x98) & 0x400) == 0) &&
       (iVar9 = FUN_005cfac0(*(int *)(param_1 + 0xa4) + 0x3c), iVar9 != 0)) {
      *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x20000;
      *(undefined4 *)(param_1 + 0xbc) = 0x3dcccccd;
    }
    if ((*(uint *)(param_1 + 0x98) & 0x800) != 0) {
      FUN_0042d2a0(param_1);
    }
    if (DAT_00950bb8 != (code *)0x0) {
      (*DAT_00950bb8)(param_1);
    }
    if (((*(byte *)(param_1 + 0x94) & 1) != 0) && (DAT_0093b2b0 != (code *)0x0)) {
      (*DAT_0093b2b0)(param_1);
    }
    if (0.0 < *(float *)(param_1 + 0xd0)) {
      *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xd0);
    }
    bVar8 = 3;
    if ((*(uint *)(param_1 + 0x98) & 0x40000) != 0) {
      bVar8 = 0x13;
    }
    if (*(int *)(param_1 + 0xd8) != 0) {
      FUN_0059a6b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),*(int *)(param_1 + 0xd8));
      *(undefined4 *)(param_1 + 0xd8) = 0;
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x94) >> 0x15 & 1) == 0) {
      bVar8 = 1;
      goto LAB_00567d21;
    }
    bVar8 = 0;
  }
  bVar8 = bVar8 | 4;
LAB_00567d21:
  if ((0.0 < *(float *)(param_1 + 0xb0)) && (bVar7)) {
    bVar8 = bVar8 | 8;
  }
  if (param_2 != 0) {
    FUN_005672d0(param_1 + 0x4c,param_1,1,bVar8,param_5);
  }
  return 1;
}

