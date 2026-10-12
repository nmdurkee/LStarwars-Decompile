/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x598880; label: FUN_00598880
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00598880(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  float fVar4;
  bool bVar5;
  undefined2 uVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  undefined4 uVar10;
  float *pfVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined **ppuVar15;
  float10 fVar16;
  float local_74;
  int local_70;
  undefined1 uStack_6c;
  float local_68 [2];
  float local_60;
  float local_5c [2];
  float fStack_54;
  undefined *puStack_50;
  int iStack_4c;
  undefined4 uStack_44;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined4 uStack_38;
  byte bStack_1;
  
  if (DAT_00802878 == -1) {
    return;
  }
  if (*(char *)(param_2 + 0x7b5) != DAT_00802878) {
    if (DAT_00955fb0 == (code *)0x0) {
      return;
    }
    iVar7 = (*DAT_00955fb0)(param_2);
    if (iVar7 == 0) {
      return;
    }
    if ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) {
      return;
    }
    if (*(char *)(param_2 + 0x281) == '\0') {
      return;
    }
    iVar7 = FUN_005620f0(param_2);
    if (iVar7 == 0) {
      return;
    }
    local_74 = 100000.0;
    FUN_005b3620(local_68,&DAT_0080250c,*(undefined2 *)(param_2 + 0x5a));
    iVar7 = *(int *)(param_1 + 0x50c8);
    local_70 = 0;
    if (iVar7 == 0) {
      return;
    }
    iVar14 = 0;
    if (*(int *)(param_1 + 0x50c0) < 1) {
      return;
    }
    do {
      uVar9 = *(uint *)(iVar7 + 0x94);
      if ((((((uVar9 & 1) == 0) && ((uVar9 & 0x800000) != 0)) && ((uVar9 & 0x4000) != 0)) &&
          ((((uVar9 & 0x8000) != 0 && ((*(byte *)(iVar7 + 0x9c) & 1) != 0)) &&
           (((*(byte *)(iVar7 + 0x98) & 0x20) == 0 || (DAT_0087baf0 != 0)))))) &&
         ((*(short *)(iVar7 + 0x102) == -1 ||
          (*(short *)(param_2 + 0x106c) != *(short *)(iVar7 + 0x102))))) {
        fVar16 = (float10)FUN_005b3c50(iVar7 + 0x4c,param_2 + 0x80,local_5c);
        fVar1 = (float)fVar16;
        if ((fVar1 < local_74) &&
           ((fVar4 = *(float *)(iVar7 + 0xa8) + *(float *)(param_2 + 0x1dc) + 0.2,
            fVar1 < fVar4 * fVar4 && (0.0 < local_68[0] * local_5c[0] + local_60 * fStack_54)))) {
          local_74 = fVar1;
          local_70 = iVar7;
        }
      }
      iVar14 = iVar14 + 1;
      iVar7 = iVar7 + 0x114;
    } while (iVar14 < *(int *)(param_1 + 0x50c0));
    if (local_70 == 0) {
      return;
    }
    cVar2 = *(char *)(param_2 + 0x280);
    if ((cVar2 == '\0') || (cVar2 == '\x01')) {
      puVar13 = &DAT_00802cd8;
      ppuVar15 = &puStack_50;
      for (iVar7 = 0x14; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppuVar15 = (undefined *)*puVar13;
        puVar13 = puVar13 + 1;
        ppuVar15 = ppuVar15 + 1;
      }
      puStack_50 = DAT_00926c28;
      if (DAT_00926c28 == (undefined *)0x0) {
        puStack_50 = PTR_DAT_0080233c;
      }
      uStack_44 = 0x40000000;
      iStack_4c = local_70 + 0x4c;
      uStack_38 = 0x87;
      bStack_1 = 4;
      if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
          (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
        bStack_1 = (-(cVar2 != '\0') & 0xfaU) + 8 | 4;
      }
      iVar7 = (int)cVar2;
      uStack_3c = (&DAT_00802be0)[iVar7 * 3];
      uStack_3b = (&DAT_00802be1)[iVar7 * 3];
      uStack_3a = (&DAT_00802be2)[iVar7 * 3];
      fVar16 = (float10)FUN_005b7d30(_DAT_00925064,0x3f000000);
      uStack_6c = (undefined1)
                  (int)ROUND((float)(&DAT_029899a0)
                                    [(uint)(int)ROUND((fVar16 + fVar16) * (float10)65536.0) >> 1 &
                                     0x7fff] * 48.0 + 80.0);
      uStack_39 = uStack_6c;
      FUN_00560b60(&puStack_50);
    }
    if ((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) == 0) {
      return;
    }
    FUN_005985b0(param_2,local_70,0);
    return;
  }
  pfVar11 = (float *)0x0;
  uVar9 = 1;
  if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) != 0) &&
     (pfVar11 = (float *)FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0),
     pfVar11 == (float *)0x0)) {
    return;
  }
  switch(*(undefined1 *)(param_2 + 0x7b3)) {
  case 0:
    bVar5 = false;
    if ((*(byte *)(param_2 + 0x7bc) & 0x40) == 0) {
      uVar6 = FUN_005be2d0(*(float *)(*(int *)(param_2 + 0x798) + 0x4c) - *(float *)(param_2 + 0x80)
                           ,*(float *)(*(int *)(param_2 + 0x798) + 0x54) -
                            *(float *)(param_2 + 0x88));
      *(undefined2 *)(param_2 + 0x5a) = uVar6;
      if (pfVar11 != (float *)0x0) {
        fVar16 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),
                                       (int)*(short *)(param_2 + 0x7aa),0);
        if ((1.0 <= (float)fVar16) && ((float)fVar16 <= *pfVar11)) {
          bVar5 = true;
        }
      }
    }
    fVar1 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined1 *)(param_2 + 0x7b3) = 2;
      *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca0;
      if ((*(byte *)(param_2 + 0x7bc) & 0x40) == 0) goto LAB_005989c9;
    }
    if (bVar5) {
LAB_005989c9:
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
      FUN_00567800(*(undefined4 *)(param_2 + 0x798),0,7,0xffffffff,0,1);
      FUN_0054a8d0(**(undefined4 **)(param_2 + 0xca4),1,0);
      return;
    }
    break;
  case 1:
    bVar5 = false;
    if ((*(byte *)(param_2 + 0x7bc) & 0x40) == 0) {
      if (pfVar11 == (float *)0x0) {
        if (DAT_008051d4 != 0) {
          bVar5 = true;
        }
      }
      else {
        fVar16 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),
                                       (int)*(short *)(param_2 + 0x7aa),0);
        if ((1.0 <= (float)fVar16) && ((float)fVar16 <= *pfVar11)) {
          bVar5 = true;
        }
      }
    }
    fVar1 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if (((fVar1 <= 0.0) &&
        (*(undefined1 *)(param_2 + 0x7b5) = 0xff, (*(byte *)(param_2 + 0x7bc) & 0x40) == 0)) ||
       (bVar5)) {
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
      FUN_0054a8d0(**(undefined4 **)(param_2 + 0xca4),1,0);
      sVar8 = *(short *)(param_2 + 0x7a6) + *(short *)(param_2 + 0x5a);
      if (DAT_008051d4 == 0) {
        FUN_00597c20(*(undefined4 *)(param_2 + 0x798),param_2 + 0x76c,sVar8,0);
        return;
      }
      iVar7 = FUN_00597c20(*(undefined4 *)(param_2 + 0x798),param_2 + 0x76c,sVar8,1);
      if (iVar7 == 0) {
        FUN_005980c0(param_2,2);
        return;
      }
    }
    break;
  case 2:
  case 3:
    uVar12 = 0;
    *(float *)(param_2 + 0x77c) = *(float *)(param_2 + 0x77c) + _DAT_00925018;
    if (*(char *)(param_2 + 0x281) == '\0') goto LAB_00598e32;
    if (DAT_00955fb4 != 0) {
      uVar3 = *(uint *)(*(int *)(param_2 + 0xca4) + 8);
      uVar12 = uVar9;
      uVar9 = 0;
      if ((DAT_0080227c & uVar3) != 0) goto LAB_00598b86;
      uVar9 = DAT_00802280 & uVar3;
LAB_00598cfc:
      if ((((uVar9 != 0) && ((*(byte *)(*(int *)(param_2 + 0x798) + 0x9c) & 4) != 0)) &&
          ((DAT_00804cac != -1 &&
           ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + DAT_00804cac * 4) != 0 &&
            (*(float *)(param_2 + 0x21c) != 2e+06)))))) &&
         (*(float *)(param_2 + 0x1a0) - *(float *)(param_2 + 0x21c) < 0.1)) {
        *(undefined1 *)(param_2 + 0x7b3) = 1;
        sVar8 = DAT_00804cac;
        *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffffffbf;
        *(short *)(param_2 + 0x7aa) = sVar8;
        fVar16 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),(int)sVar8,0,0,1);
        *(float *)(param_2 + 0x77c) = (float)fVar16;
        if ((float)fVar16 <= 0.0) {
          *(undefined4 *)(param_2 + 0x77c) = 0x3f000000;
        }
        *(undefined4 *)(param_2 + 0x76c) = *(undefined4 *)(param_2 + 0x19c);
        *(undefined4 *)(param_2 + 0x770) = *(undefined4 *)(param_2 + 0x21c);
        *(undefined4 *)(param_2 + 0x774) = *(undefined4 *)(param_2 + 0x1a4);
        FUN_005b3620(local_68,param_2 + 0x748,*(undefined2 *)(param_2 + 0x27a));
        *(float *)(param_2 + 0x76c) = *(float *)(param_2 + 0x76c) + local_68[0];
        *(float *)(param_2 + 0x774) = local_60 + *(float *)(param_2 + 0x774);
        return;
      }
LAB_00598e32:
      if ((((DAT_00955fbc != 0) && (DAT_00804cb4 != -1)) &&
          ((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802278) != 0)) &&
         (*(char *)(param_2 + 0x281) != '\0')) {
        *(undefined1 *)(param_2 + 0x7b3) = 6;
        sVar8 = DAT_00804cb4;
        *(undefined4 *)(param_2 + 0x77c) = 0;
        *(short *)(param_2 + 0x7aa) = sVar8;
        *(undefined4 *)(param_2 + 0x6c) = _DAT_008051d8;
        if (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + sVar8 * 4) == 0) {
          fVar16 = -(float10)*(float *)(param_2 + 0x6c) /
                   (float10)*(float *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x24);
          fVar16 = fVar16 + fVar16;
        }
        else {
          fVar16 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),(int)sVar8,0,0,0);
        }
        *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffff7fff;
        *(float *)(param_2 + 0x784) = (float)fVar16;
        *(undefined1 *)(param_2 + 0x281) = 0;
        *(float *)(param_2 + 0x784) = *(float *)(param_2 + 0x784) + 0.1;
        *(undefined2 *)(param_2 + 0x1050) = 0;
        *(undefined4 *)(param_2 + 0x78c) = *(undefined4 *)(param_2 + 0x17c);
        FUN_0062e650(param_2 + 8,0xffffffff);
      }
      if (0.0 < *(float *)(*(int *)(param_2 + 0xca4) + 0x28)) {
        *(undefined1 *)(param_2 + 0x7b3) = 3;
        *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca4;
        return;
      }
      *(undefined1 *)(param_2 + 0x7b3) = 2;
      *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca0;
      return;
    }
    if ((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802280) == 0) goto LAB_00598e32;
    if (0.0 < *(float *)(*(int *)(param_2 + 0xca4) + 0x28)) {
      uVar12 = 1;
      uVar9 = 0;
    }
LAB_00598b86:
    if (((DAT_00955fb8 == 0) || (DAT_00804cb0 == -1)) ||
       (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + DAT_00804cb0 * 4) == 0)) {
LAB_00598c5e:
      if (uVar12 == 0) goto LAB_00598cfc;
      if ((DAT_00804ca8 == -1) ||
         (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + DAT_00804ca8 * 4) == 0)) {
        *(undefined1 *)(param_2 + 0x7b5) = 0xff;
LAB_00599018:
        *(uint *)(param_2 + 0xe20) = *(uint *)(param_2 + 0xe20) | 0x800000;
        FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f19999a,0);
        return;
      }
      *(undefined1 *)(param_2 + 0x7b3) = 4;
      sVar8 = DAT_00804ca8;
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffffffbf;
      *(short *)(param_2 + 0x7aa) = sVar8;
      fVar16 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),(int)sVar8,0,0,1);
    }
    else {
      DAT_0087b900 = 1;
      iVar7 = FUN_0049ca80(param_2,0x3f800000,_DAT_00804dc4,1,0,1);
      *(int *)(param_2 + 0x790) = iVar7;
      if (iVar7 == 0) {
        DAT_0087b900 = 1;
        uVar10 = FUN_0049ca80(param_2,0x3f800000,_DAT_00804dc4,1,0,2);
        *(undefined4 *)(param_2 + 0x790) = uVar10;
      }
      if (*(int *)(param_2 + 0x790) == 0) goto LAB_00598c5e;
      *(undefined1 *)(param_2 + 0x7b3) = 5;
      sVar8 = DAT_00804cb0;
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffffffbf;
      *(short *)(param_2 + 0x7aa) = sVar8;
      fVar16 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),(int)sVar8,0,0,1);
    }
    *(float *)(param_2 + 0x77c) = (float)fVar16;
    if ((float)fVar16 <= 0.0) {
      *(undefined4 *)(param_2 + 0x77c) = 0x3f000000;
      return;
    }
    break;
  case 4:
    if ((*(float *)(param_2 + 0x77c) <= 0.0) && ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0)) {
LAB_00599063:
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      return;
    }
    bVar5 = false;
    if ((pfVar11 != (float *)0x0) && ((*(byte *)(param_2 + 0x7bc) & 0x40) == 0)) {
      fVar16 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),
                                     (int)*(short *)(param_2 + 0x7aa),0);
      if ((1.0 <= (float)fVar16) && ((float)fVar16 <= *pfVar11)) {
        bVar5 = true;
      }
    }
    fVar1 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if (0.0 < fVar1) {
LAB_0059900a:
      if (!bVar5) {
        return;
      }
    }
    else if ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0) {
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      goto LAB_0059900a;
    }
    *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
    goto LAB_00599018;
  case 5:
    if ((*(float *)(param_2 + 0x77c) <= 0.0) && ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0))
    goto LAB_00599063;
    bVar5 = false;
    if ((pfVar11 != (float *)0x0) && ((*(byte *)(param_2 + 0x7bc) & 0x40) == 0)) {
      fVar16 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),
                                     (int)*(short *)(param_2 + 0x7aa),0);
      if ((1.0 <= (float)fVar16) && ((float)fVar16 <= *pfVar11)) {
        bVar5 = true;
      }
    }
    fVar1 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if (0.0 < fVar1) {
LAB_005990f2:
      if (!bVar5) {
        return;
      }
    }
    else if ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0) {
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      goto LAB_005990f2;
    }
    *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
    iVar7 = FUN_0058d340(param_2,*(undefined4 *)(param_2 + 0x790),_DAT_00804dc4);
    if (iVar7 == 0) {
      if ((*(char *)(param_2 + 0x7b5) != -1) && (0.0 < *(float *)(param_2 + 0x77c))) {
        *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffffffbf;
      }
    }
    else {
      FUN_00438230(param_2,*(undefined4 *)(param_2 + 0x790),1,0x2000,0,1);
    }
    if ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0) {
      FUN_00597f90(param_2,local_5c,0);
      uVar10 = 3;
      if (0.0 < *(float *)(*(int *)(param_2 + 0x798) + 0xb0)) {
        uVar10 = 0xb;
      }
      FUN_005672d0(local_5c,*(int *)(param_2 + 0x798),0,uVar10,0);
      FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f19999a,0);
      FUN_0054a8d0(**(undefined4 **)(param_2 + 0xca4),2,0);
      return;
    }
    break;
  case 6:
    fVar1 = *(float *)(param_2 + 0x77c) + _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if (*(float *)(param_2 + 0x784) < fVar1 != (*(float *)(param_2 + 0x784) == fVar1)) {
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x8000;
    }
    if ((0.1 <= *(float *)(param_2 + 0x77c)) && (*(char *)(param_2 + 0x281) != '\0')) {
      uVar9 = *(uint *)(param_2 + 0x7bc) >> 0xf & 1;
      if ((uVar9 != 0) || (*(float *)(*(int *)(param_2 + 0xca4) + 0x28) == 0.0)) {
        *(undefined1 *)(param_2 + 0x7b3) = 7;
        if (((uVar9 == 0) || (DAT_00804cbc == -1)) ||
           (sVar8 = DAT_00804cbc,
           *(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + DAT_00804cbc * 4) == 0)) {
          sVar8 = DAT_00804cb8;
        }
        *(short *)(param_2 + 0x7aa) = sVar8;
        if (sVar8 != -1) {
          fVar16 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),(int)sVar8,0,0,1);
          *(float *)(param_2 + 0x77c) = (float)fVar16;
          if ((float)fVar16 <= 0.0) {
            *(undefined4 *)(param_2 + 0x77c) = 0x3f000000;
          }
          FUN_0062e650(param_2 + 8,0xffffffff);
          *(undefined4 *)(param_2 + 0x70) = 0;
          *(undefined4 *)(param_2 + 0x68) = 0;
          FUN_0054a8d0(**(undefined4 **)(param_2 + 0xca4),
                       (*(short *)(param_2 + 0x7aa) == DAT_00804cbc) + '\x01',0);
          return;
        }
      }
      if (0.0 < *(float *)(*(int *)(param_2 + 0xca4) + 0x28)) {
        *(undefined1 *)(param_2 + 0x7b3) = 3;
        *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca4;
        return;
      }
      *(undefined1 *)(param_2 + 0x7b3) = 2;
      *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca0;
      return;
    }
    break;
  case 7:
    fVar1 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar1;
    if ((fVar1 <= 0.0) ||
       (((*(uint *)(param_2 + 0x7bc) & 0x8000) == 0 &&
        (0.0 < *(float *)(*(int *)(param_2 + 0xca4) + 0x28))))) {
      if (0.0 < *(float *)(*(int *)(param_2 + 0xca4) + 0x28)) {
        *(undefined1 *)(param_2 + 0x7b3) = 3;
        *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca4;
        return;
      }
      *(undefined1 *)(param_2 + 0x7b3) = 2;
      *(undefined2 *)(param_2 + 0x7aa) = DAT_00804ca0;
      return;
    }
  }
  return;
}

