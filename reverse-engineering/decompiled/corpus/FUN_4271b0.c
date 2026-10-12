/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4271b0; label: FUN_004271b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004271b0(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  byte bVar10;
  undefined4 *puVar8;
  undefined4 uVar9;
  float10 fVar11;
  float10 extraout_ST0;
  undefined8 uVar12;
  
  if ((*(char *)(param_1 + 0x7b5) == 'I') || (*(char *)(param_1 + 0x7b5) == 'H')) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x8000;
    *(undefined4 *)(param_1 + 0xde0) = 0;
    pfVar6 = (float *)0x0;
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) != 0)
       && (pfVar6 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
          pfVar6 == (float *)0x0)) {
      return;
    }
    fVar3 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar3;
    if (fVar3 < 0.0 == (fVar3 == 0.0)) {
      if (*(char *)(param_1 + 0x7b3) != '\0') {
        return;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
      {
        bVar10 = fVar3 < 0.5 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8);
      }
      else {
        fVar11 = (float10)FUN_0062f1f0(*(int *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),
                                       -(*(char *)(param_1 + 0x7b5) != 'I') & 2);
        if (pfVar6 == (float *)0x0) {
          return;
        }
        if (*pfVar6 <= 0.0) {
          return;
        }
        bVar10 = (float)fVar11 < *pfVar6 |
                 (byte)((ushort)((ushort)((float)fVar11 == *pfVar6) << 0xe) >> 8);
      }
      if ((POPCOUNT(bVar10) & 1U) == 0) {
        return;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if (*(char *)(param_1 + 0x7b3) != '\0') {
        return;
      }
    }
    *(undefined1 *)(param_1 + 0x7b3) = 1;
    if (*(char *)(param_1 + 0x7b5) != 'I') {
      puVar8 = (undefined4 *)FUN_00426b50();
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = *(undefined4 *)(param_1 + 0x754);
        puVar8[1] = *(undefined4 *)(param_1 + 0x758);
        uVar9 = *(undefined4 *)(param_1 + 0x75c);
        puVar8[9] = param_1;
        puVar8[2] = uVar9;
        *(undefined1 *)(puVar8 + 10) = 1;
        *(undefined2 *)((int)puVar8 + 0x2a) = *(undefined2 *)(param_1 + 0x7a4);
        *(short *)(puVar8 + 0xb) = *(short *)(param_1 + 0x7a6) + *(short *)(param_1 + 0x27a);
        uVar4 = *(undefined2 *)(param_1 + 0x7a8);
        puVar8[5] = (float)extraout_ST0;
        puVar8[3] = (float)extraout_ST0;
        puVar1 = puVar8 + 3;
        puVar8[4] = 0x3d9eb852;
        *(undefined2 *)((int)puVar8 + 0x2e) = uVar4;
        FUN_005b3690(puVar1,puVar1,uVar4);
        FUN_005b35a0(puVar1,puVar1,*(undefined2 *)((int)puVar8 + 0x2a));
        FUN_005b37d0(puVar1,puVar1,puVar8);
        puVar8[0xc] = 0;
        uVar9 = FUN_0059afc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),puVar1,0x3f800000,0x3f800000
                             ,0x3f800000,0,0,0);
        puVar8[0xd] = uVar9;
        FUN_00681f40("imp_thermalDet_attach",puVar8);
        return;
      }
      FUN_00547930(0x32,0,0,0);
      return;
    }
    if (*(int *)(param_1 + 0x798) != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x798) + 0x28) = 0;
      iVar5 = *(int *)(*(int *)(param_1 + 0x798) + 0x34);
      if (iVar5 != 0) {
        FUN_0059a6b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),iVar5);
        *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x34) = 0;
        return;
      }
    }
    return;
  }
  if ((((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xece) == '\0') ||
       ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) ||
      ((*(char *)(param_1 + 0x281) == '\0' && (*(char *)(param_1 + 0xe32) != '\x01')))) ||
     ((iVar5 = FUN_005620f0(param_1), iVar5 == 0 &&
      ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x2000) == 0)))) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x8000;
    *(undefined4 *)(param_1 + 0xde0) = 0;
    return;
  }
  bVar2 = *(float *)(param_1 + 0xde0) <= 0.0;
  if ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802280) != 0) {
    if ((bVar2) && ((*(uint *)(param_1 + 0xe20) & 0x8000) != 0)) {
      return;
    }
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x8000;
    fVar3 = *(float *)(param_1 + 0xde0) + _DAT_00925018;
    *(float *)(param_1 + 0xde0) = fVar3;
    if (NAN(fVar3) || 0.3 < fVar3 == (fVar3 == 0.3)) {
      return;
    }
    if (NAN(fVar3) || 1.0 < fVar3 == (fVar3 == 1.0)) {
      return;
    }
    uVar12 = FUN_00426c50();
    if ((int)uVar12 != 0) {
      FUN_00426f60((int)uVar12);
      *(undefined4 *)(param_1 + 0xde0) = 0x3f333333;
      return;
    }
    *(undefined4 *)(param_1 + 0xde0) = 0;
    *(uint *)(param_1 + 0xe20) = (uint)((ulonglong)uVar12 >> 0x20) | 0x8000;
    return;
  }
  if ((bVar2) || (0.3 <= *(float *)(param_1 + 0xde0))) goto LAB_0042753a;
  pfVar6 = (float *)FUN_00426bb0((undefined4 *)(param_1 + 0x19c),
                                 *(float *)(param_1 + 0x1dc) + 0.0775,param_1);
  if (pfVar6 == (float *)0x0) {
    iVar5 = FUN_00426b50();
    if (((iVar5 != 0) && (*(float *)(param_1 + 0x21c) != 2e+06)) &&
       (*(float *)(param_1 + 0x1a0) - *(float *)(param_1 + 0x21c) < 0.155)) {
      *(undefined4 *)(param_1 + 0x754) = *(undefined4 *)(param_1 + 0x19c);
      *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x21c);
      *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 0x1a4);
      iVar5 = FUN_00426bb0((undefined4 *)(param_1 + 0x754),0x3e1eb852,0);
      if (iVar5 == 0) {
        *(undefined1 *)(param_1 + 0x7b3) = 0;
        *(undefined1 *)(param_1 + 0x7b5) = 0x48;
        FUN_0058d930(param_1);
        *(undefined2 *)(param_1 + 0x7aa) = 0x8d;
        *(undefined2 *)(param_1 + 0x7a4) = *(undefined2 *)(param_1 + 0x1056);
        uVar4 = FUN_0054fa60();
        *(undefined2 *)(param_1 + 0x7a6) = uVar4;
        *(undefined2 *)(param_1 + 0x7a8) = *(undefined2 *)(param_1 + 0x1058);
        goto LAB_004274c0;
      }
    }
    FUN_00547930(0x32,0,0,0);
  }
  else {
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0x49;
    FUN_0058d930(param_1,0);
    *(undefined2 *)(param_1 + 0x7aa) = 0x66;
    *(float **)(param_1 + 0x798) = pfVar6;
    uVar7 = FUN_005be2d0(*pfVar6 - *(float *)(param_1 + 0x5c),pfVar6[2] - *(float *)(param_1 + 100))
    ;
    pfVar6 = *(float **)(param_1 + 0x798);
    *(short *)(param_1 + 0x5a) = (short)uVar7;
    *(float *)(param_1 + 0x754) = *pfVar6 - (float)(&DAT_029899a0)[(uVar7 & 0xffff) >> 1] * 0.1684;
    *(float *)(param_1 + 0x75c) =
         pfVar6[2] - (float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff] * 0.1684
    ;
    uVar4 = FUN_00550040(uVar7,*(undefined2 *)(pfVar6 + 0xb));
    *(undefined2 *)(param_1 + 0x7a6) = uVar4;
  }
LAB_004274c0:
  if ((*(char *)(param_1 + 0x7b5) == 'H') || (*(char *)(param_1 + 0x7b5) == 'I')) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    iVar5 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,1);
    if (iVar5 != 0) {
      FUN_0062e650(param_1 + 8,0xffffffff);
    }
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0) {
      fVar11 = (float10)1;
    }
    else {
      fVar11 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                     (int)*(short *)(param_1 + 0x7aa),0,0,1);
    }
    *(float *)(param_1 + 0x77c) = (float)fVar11;
  }
LAB_0042753a:
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xffff7fff;
  *(undefined4 *)(param_1 + 0xde0) = 0;
  return;
}

