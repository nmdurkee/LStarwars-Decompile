/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b26b0; label: FUN_005b26b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b26b0(int param_1)

{
  uint uVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 uVar9;
  int iVar10;
  float10 fVar11;
  undefined4 uVar12;
  
  if (_DAT_008028ac == -1) {
    return;
  }
  if (*(char *)(param_1 + 0x7b5) != _DAT_008028ac) {
    if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280) == 0) {
      return;
    }
    if (*(char *)(param_1 + 0x281) == '\0') {
      return;
    }
    iVar7 = FUN_005620f0(param_1);
    if (iVar7 == 0) {
      return;
    }
    if (DAT_00804d10 == -1) {
      return;
    }
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d10 * 4) == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x7ba) = 0xff;
    iVar7 = 0;
    if ((((DAT_00804d18 == -1) ||
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d18 * 4) == 0)) ||
        (iVar10 = FUN_00598560(param_1,0), iVar10 == 0)) ||
       (iVar7 = FUN_00569980(param_1,0x40000000,0x3f400000,0x3e800000,5,0,0,1), iVar7 == 0)) {
      if ((DAT_00804d1c != -1) &&
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d1c * 4) != 0)) {
        iVar7 = FUN_00569980(param_1,0x40000000,0x3f400000,0x3e800000,5,0xc080,0,0);
        uVar5 = 2;
        if (iVar7 != 0) goto LAB_005b2c21;
      }
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
    }
LAB_005b2c21:
    *(undefined1 *)(param_1 + 0x7b5) = DAT_008028ac;
    sVar3 = DAT_00804d10;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffffeff;
    *(undefined1 *)(param_1 + 0x7ba) = uVar5;
    *(short *)(param_1 + 0x7aa) = sVar3;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    fVar11 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar3,0,0,0);
    *(float *)(param_1 + 0x784) = (float)fVar11;
    uVar9 = FUN_00547820(param_1,0);
    FUN_00547930(0x4c,param_1 + 0x80,uVar9);
    FUN_0058d8e0(param_1);
    *(int *)(param_1 + 0x798) = iVar7;
    *(undefined4 *)(param_1 + 0x790) = 0;
    if (iVar7 == 0) {
      return;
    }
    uVar6 = FUN_005be2d0(*(float *)(iVar7 + 0x30) - *(float *)(param_1 + 0x5c),
                         *(float *)(iVar7 + 0x38) - *(float *)(param_1 + 100));
    *(undefined2 *)(param_1 + 0x5a) = uVar6;
    return;
  }
  if (*(char *)(param_1 + 0x7b3) == '\0') {
    iVar7 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0);
    if (iVar7 == 0) {
      return;
    }
    fVar2 = _DAT_00925018 + *(float *)(param_1 + 0x77c);
    *(float *)(param_1 + 0x77c) = fVar2;
    sVar4 = DAT_00804d1c;
    sVar3 = DAT_00804d18;
    if (*(float *)(param_1 + 0x784) < fVar2 == (*(float *)(param_1 + 0x784) == fVar2)) {
      return;
    }
    if (*(char *)(param_1 + 0x7ba) == '\x02') {
      if (((*(int *)(param_1 + 0x798) != 0) &&
          (uVar1 = *(uint *)(*(int *)(param_1 + 0x798) + 0x94), (uVar1 & 0x4000) != 0)) &&
         ((uVar1 & 0x800000) != 0)) {
        *(undefined4 *)(param_1 + 0x77c) = 0;
        *(short *)(param_1 + 0x7aa) = sVar4;
        *(undefined1 *)(param_1 + 0x7b3) = 2;
        fVar11 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar4,0,0,1);
        *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
        *(float *)(param_1 + 0x784) = (float)fVar11;
        uVar6 = FUN_005be2d0(*(float *)(*(int *)(param_1 + 0x798) + 0x30) -
                             *(float *)(param_1 + 0x5c),
                             *(float *)(*(int *)(param_1 + 0x798) + 0x38) -
                             *(float *)(param_1 + 100));
        *(undefined2 *)(param_1 + 0x5a) = uVar6;
        return;
      }
    }
    else if ((((*(char *)(param_1 + 0x7ba) == '\x03') && (*(int *)(param_1 + 0x798) != 0)) &&
             (uVar1 = *(uint *)(*(int *)(param_1 + 0x798) + 0x94), (uVar1 & 0x4000) != 0)) &&
            ((uVar1 & 0x800000) != 0)) {
      *(undefined4 *)(param_1 + 0x77c) = 0;
      *(short *)(param_1 + 0x7aa) = sVar3;
      *(undefined1 *)(param_1 + 0x7b3) = 3;
      fVar11 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar3,0,0,1);
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
      *(float *)(param_1 + 0x784) = (float)fVar11;
      uVar6 = FUN_005be2d0(*(float *)(*(int *)(param_1 + 0x798) + 0x30) - *(float *)(param_1 + 0x5c)
                           ,*(float *)(*(int *)(param_1 + 0x798) + 0x38) - *(float *)(param_1 + 100)
                          );
      *(undefined2 *)(param_1 + 0x5a) = uVar6;
      return;
    }
    *(undefined1 *)(param_1 + 0x7ba) = 1;
    sVar3 = DAT_00804d14;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(short *)(param_1 + 0x7aa) = sVar3;
    *(undefined1 *)(param_1 + 0x7b3) = 1;
    fVar11 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar3,0,0,1);
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
    *(float *)(param_1 + 0x784) = (float)fVar11;
    return;
  }
  if ((*(uint *)(param_1 + 0x7bc) & 0x100) != 0) {
    if (*(int *)(param_1 + 0x798) == 0) {
      if (*(int *)(param_1 + 0x790) == 0) goto LAB_005b2955;
      pfVar8 = (float *)(*(int *)(param_1 + 0x790) + 0x80);
    }
    else {
      pfVar8 = (float *)(*(int *)(param_1 + 0x798) + 0x30);
    }
    if (pfVar8 != (float *)0x0) {
      uVar6 = FUN_005be2d0(*pfVar8 - *(float *)(param_1 + 0x5c),
                           pfVar8[2] - *(float *)(param_1 + 100));
      *(undefined2 *)(param_1 + 0x5a) = uVar6;
    }
  }
LAB_005b2955:
  iVar7 = 0;
  pfVar8 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0);
  if (pfVar8 == (float *)0x0) goto LAB_005b2ac9;
  *(float *)(param_1 + 0x77c) = _DAT_00925018 + *(float *)(param_1 + 0x77c);
  if ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0) {
    fVar11 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),
                                   0);
    if ((1.0 <= (float)fVar11) && ((float)fVar11 <= *pfVar8)) {
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x40;
      iVar7 = 1;
    }
  }
  if ((*(float *)(param_1 + 0x784) < *(float *)(param_1 + 0x77c) ==
       (*(float *)(param_1 + 0x784) == *(float *)(param_1 + 0x77c))) ||
     (*(undefined1 *)(param_1 + 0x7b5) = 0xff, (*(byte *)(param_1 + 0x7bc) & 0x40) != 0)) {
    if (iVar7 == 0) goto LAB_005b2ac9;
  }
  else {
    iVar7 = 1;
  }
  if (*(char *)(param_1 + 0x7b3) == '\x02') {
    iVar7 = FUN_00567800(*(undefined4 *)(param_1 + 0x798),1,1,1,0,1);
    if (iVar7 != 0) {
      FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
    }
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
LAB_005b2a95:
    uVar9 = FUN_00547820(param_1,0);
    uVar12 = 0x4d;
  }
  else {
    if (*(char *)(param_1 + 0x7b3) == '\x03') {
      FUN_00567800(*(undefined4 *)(param_1 + 0x798),0,7,0xffffffff,0,1);
      goto LAB_005b2a95;
    }
    if (iVar7 == 2) goto LAB_005b2a95;
    uVar9 = FUN_00547820(param_1,0);
    uVar12 = 0x4e;
  }
  FUN_00547930(uVar12,param_1 + 0x80,uVar9);
LAB_005b2ac9:
  if (((*(char *)(param_1 + 0x7b5) == -1) && (*(char *)(param_1 + 0x7b3) == '\x03')) &&
     (*(int *)(param_1 + 0x798) != 0)) {
    FUN_005985b0(param_1,*(int *)(param_1 + 0x798),1);
    return;
  }
  return;
}

