/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41cb50; label: FUN_0041cb50
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041cb50(short *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5,int param_6,int param_7,undefined4 param_8)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  float *pfVar8;
  undefined4 uVar9;
  int iVar10;
  undefined1 uVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  float *pfVar15;
  undefined4 *puVar16;
  float *pfVar17;
  float10 fVar18;
  undefined4 uStack_40cc;
  float local_40c8;
  undefined4 local_40c4;
  undefined4 local_40c0 [16];
  undefined4 auStack_4080 [16];
  undefined4 local_4040 [16];
  undefined1 auStack_4000 [16380];
  undefined4 uStack_4;
  
  uStack_4 = 0x41cb5a;
  bVar6 = false;
  if ((((param_7 != 0) && (*(short *)(param_7 + 0x1064) == DAT_007f191c)) &&
      (iVar7 = FUN_0056e160(5), iVar7 != 0)) &&
     (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x135e) != '\0')) {
    thunk_FUN_005d05b0();
    puVar14 = param_3;
    puVar16 = local_40c0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar16 = *puVar14;
      puVar14 = puVar14 + 1;
      puVar16 = puVar16 + 1;
    }
    bVar6 = true;
    FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1350,local_40c0);
    if (param_5 != (undefined4 *)0x0) {
      puVar14 = param_5;
      puVar16 = local_40c0;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      FUN_005d4690(1);
      FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1350,local_40c0);
      FUN_005d46b0();
    }
    local_40c4 = 0x3f000000;
    local_40c8 = 0.5;
    puVar14 = local_4040;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar14 = *param_3;
      param_3 = param_3 + 1;
      puVar14 = puVar14 + 1;
    }
    uStack_40cc = 0x3f000000;
    param_3 = local_4040;
    FUN_005b4c30(param_3,&uStack_40cc);
    if (param_5 != (undefined4 *)0x0) {
      puVar14 = auStack_4080;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar14 = *param_5;
        param_5 = param_5 + 1;
        puVar14 = puVar14 + 1;
      }
      param_5 = auStack_4080;
      FUN_005b4c30(param_5,&uStack_40cc);
    }
  }
  bVar5 = false;
  if (((param_7 == 0) || ((*(uint *)(*(int *)(param_7 + 0x54) + 4) & 0x10000) == 0)) ||
     ((*(int *)(PTR_DAT_00802c54 + 300) != 0 && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af84)))
     ) {
    *(undefined1 *)(*(int *)(param_1 + 2) + 0x1a0) = 1;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 2) + 0x1a0) = 0;
    if (param_5 != (undefined4 *)0x0) {
      FUN_00419e00(param_7);
      bVar5 = true;
    }
  }
  DAT_02913104 = DAT_00855f88;
  PTR_FUN_0080fb94 = *(undefined **)(*param_1 * 0x120 + DAT_0093b284);
  if ((param_7 == 0) || (DAT_00804d2c == 0)) {
    uVar11 = 0;
  }
  else {
    uVar11 = *(undefined1 *)(param_7 + 0x107d);
  }
  if ((param_7 == 0) || (DAT_00804d2c == 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = param_7 + 0xf3c;
  }
  if (param_7 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *(undefined4 *)(param_7 + 0x54);
  }
  iVar7 = FUN_0062fbf0(param_1,uVar9,param_2,param_3,param_4,param_5,0,param_6,param_7,param_8,iVar7
                       ,uVar11,DAT_0093b328,_DAT_00925018,auStack_4000,0,
                       *(undefined4 *)(PTR_DAT_00802c54 + 0x134));
  if (iVar7 == 0) {
    if ((param_7 != 0) && (param_6 != 0)) {
      piVar12 = (int *)(param_1 + 0xc);
      pfVar8 = (float *)(param_6 + 0x34);
      iVar13 = 2;
      do {
        if (piVar12[-1] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + -0xd;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[-1] = *(float *)(param_7 + 0x80);
          *pfVar8 = *(float *)(param_7 + 0x84);
          pfVar8[1] = *(float *)(param_7 + 0x88);
          *pfVar8 = *pfVar8 - (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                              *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (*piVar12 != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 3;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0xf] = *(float *)(param_7 + 0x80);
          pfVar8[0x10] = *(float *)(param_7 + 0x84);
          pfVar8[0x11] = *(float *)(param_7 + 0x88);
          pfVar8[0x10] = pfVar8[0x10] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[1] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 0x13;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x1f] = *(float *)(param_7 + 0x80);
          pfVar8[0x20] = *(float *)(param_7 + 0x84);
          pfVar8[0x21] = *(float *)(param_7 + 0x88);
          pfVar8[0x20] = pfVar8[0x20] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[2] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 0x23;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x2f] = *(float *)(param_7 + 0x80);
          pfVar8[0x30] = *(float *)(param_7 + 0x84);
          pfVar8[0x31] = *(float *)(param_7 + 0x88);
          pfVar8[0x30] = pfVar8[0x30] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[3] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 0x33;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x3f] = *(float *)(param_7 + 0x80);
          pfVar8[0x40] = *(float *)(param_7 + 0x84);
          pfVar8[0x41] = *(float *)(param_7 + 0x88);
          pfVar8[0x40] = pfVar8[0x40] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[4] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 0x43;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x4f] = *(float *)(param_7 + 0x80);
          pfVar8[0x50] = *(float *)(param_7 + 0x84);
          pfVar8[0x51] = *(float *)(param_7 + 0x88);
          pfVar8[0x50] = pfVar8[0x50] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[5] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 0x53;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x5f] = *(float *)(param_7 + 0x80);
          pfVar8[0x60] = *(float *)(param_7 + 0x84);
          pfVar8[0x61] = *(float *)(param_7 + 0x88);
          pfVar8[0x60] = pfVar8[0x60] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        if (piVar12[6] != 0) {
          pfVar15 = (float *)(param_7 + 0xb8);
          pfVar17 = pfVar8 + 99;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *pfVar17 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar17 = pfVar17 + 1;
          }
          pfVar8[0x6f] = *(float *)(param_7 + 0x80);
          pfVar8[0x70] = *(float *)(param_7 + 0x84);
          pfVar8[0x71] = *(float *)(param_7 + 0x88);
          pfVar8[0x70] = pfVar8[0x70] -
                         (*(float *)(param_7 + 0xff4) + *(float *)(param_7 + 0xff0)) *
                         *(float *)(param_7 + 0xa8) * 0.5;
        }
        piVar12 = piVar12 + 8;
        pfVar8 = pfVar8 + 0x80;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  else if ((param_7 == 0) ||
          (((*(uint *)(param_7 + 0xef0) & 0x4000000) == 0 &&
           ((*(uint *)(*(int *)(param_7 + 0x54) + 4) & 0x10000) == 0)))) {
    bVar4 = true;
    goto LAB_0041d0d4;
  }
  bVar4 = false;
LAB_0041d0d4:
  if (((((DAT_008264bc == 1) && (bVar4)) && (param_4 != (undefined4 *)0x0)) &&
      (((param_7 != 0 && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa1) != '\0')) &&
       ((0.0 < *(float *)(param_7 + 0x1020) && (0.0 < *(float *)(param_7 + 0xf28))))))) &&
     ((*(float *)(param_7 + 0x220) == -1.0 ||
      (((&DAT_0080364c)[*(char *)(param_7 + 0x283) * 0xc] & 1) == 0)))) {
    if ((*(short *)(param_7 + 0x1064) == DAT_007f18b0) &&
       (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa2e) != '\0')) {
      fVar1 = *(float *)(param_7 + 0x1020);
      fVar2 = *(float *)(param_7 + 0xf28);
      puVar14 = local_40c0;
      for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar14 = *param_4;
        param_4 = param_4 + 1;
        puVar14 = puVar14 + 1;
      }
      FUN_005ff7a0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa20,local_40c0,fVar1 * fVar2);
    }
    else if (DAT_00804934 != 0) {
      iVar13 = *(int *)(*(int *)(param_7 + 0x54) + 0x24);
      cVar3 = *(char *)(iVar13 + 0xf6);
      if (*(char *)(iVar13 + 0xf6) == -1) {
        cVar3 = *(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa1);
      }
      if (cVar3 != '\0') {
        if (99.0 <= *(float *)(iVar13 + 0x8c)) {
          fVar1 = *(float *)(*(int *)(param_7 + 0x54) + 0x30);
        }
        else {
          fVar1 = *(float *)(iVar13 + 0x8c);
        }
        if (0.0 < fVar1) {
          fVar18 = (float10)FUN_00427ad0(param_7);
          uVar9 = FUN_006e6b90(*(undefined2 *)(param_7 + 0x1052),0,*(undefined2 *)(param_7 + 0x1054)
                              );
          FUN_005fee80(param_4 + 0xc,*(float *)(param_7 + 0xa8) * (float)(fVar18 * (float10)fVar1),
                       uVar9);
        }
      }
    }
  }
  if (bVar5) {
    uStack_40cc = 0;
    local_40c8 = -_DAT_007f239c * 0.25;
    local_40c4 = 0;
    if (DAT_00951288 == 0) {
      uVar9 = 0x41f00000;
    }
    else {
      uVar9 = 0x43160000;
    }
    FUN_005f9980(&uStack_40cc,0x17000000,uVar9,uVar9);
  }
  if (bVar6) {
    FUN_00596920(0);
  }
  return iVar7;
}

