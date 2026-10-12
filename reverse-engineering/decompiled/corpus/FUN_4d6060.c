/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d6060; label: FUN_004d6060
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d6060(float param_1,int param_2)

{
  ushort *puVar1;
  float fVar2;
  char cVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  undefined2 uVar7;
  short sVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  float *pfVar18;
  float *pfVar19;
  float *pfVar20;
  undefined2 in_FPUControlWord;
  float10 fVar21;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  fVar6 = param_1;
  if (*(char *)((int)param_1 + 0x7b5) != 'G') {
    iVar14 = FUN_005620f0(param_1);
    if ((iVar14 == 0) && (iVar14 = FUN_00578790(fVar6,0x47), iVar14 == 0)) {
      return;
    }
    uVar11 = *(uint *)((int)fVar6 + 0x1fc) >> 7 & 1;
    if ((uVar11 == 0) && (*(char *)((int)fVar6 + 0xf00) != '\x04')) {
      return;
    }
    if ((*(uint *)(*(int *)((int)fVar6 + 0x54) + 4) & 0x100000) == 0) {
      if (uVar11 == 0) {
        return;
      }
      iVar14 = FUN_0041aef0(fVar6);
      if (iVar14 == 0) {
        if ((*(byte *)(*(int *)((int)fVar6 + 0x54) + 4) & 8) == 0) {
          return;
        }
        if ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x94) & 0x8000) != 0) {
          return;
        }
        iVar14 = FUN_0056e160(0xd);
        if (iVar14 == 0) {
          return;
        }
      }
    }
    iVar14 = FUN_004d5f00(PTR_DAT_00802c54,(int)fVar6 + 0x19c,*(undefined4 *)((int)fVar6 + 0xac),0,
                          &param_1,fVar6);
    iVar15 = FUN_00578790(fVar6,0x47);
    if ((iVar15 != 0) &&
       (fVar2 = *(float *)((int)fVar6 + 0x77c) - _DAT_00925018,
       *(float *)((int)fVar6 + 0x77c) = fVar2, fVar2 <= 0.0)) {
      *(undefined1 *)((int)fVar6 + 0x7b5) = 0xff;
    }
    if (iVar14 == 0) {
      return;
    }
    if (((param_2 == 0) && (iVar15 = FUN_00578790(fVar6,0x47), iVar15 == 0)) ||
       (((*(ushort *)(iVar14 + 0x68) & 1) != 0 && ((*(ushort *)(iVar14 + 0x68) & 0x100) != 0)))) {
      FUN_0058bee0(fVar6,iVar14 + 0x1c,4,0x40000000,0x3f800000,0x40000000);
      return;
    }
    if ((*(uint *)(*(int *)((int)fVar6 + 0x54) + 4) & 0x100000) == 0) {
      if (param_1 == 0.0) {
        iVar14 = iVar14 + 0x28;
      }
      else {
        iVar14 = iVar14 + 0x10;
      }
      iVar14 = FUN_00561e20(fVar6,iVar14,0,0x3f000000,0x3f800000,0);
      if (iVar14 == 0) {
        return;
      }
      *(uint *)((int)fVar6 + 0x7bc) = *(uint *)((int)fVar6 + 0x7bc) | 0x100;
      return;
    }
    FUN_00576960(0x262);
    *(int *)((int)fVar6 + 0x798) = iVar14;
    *(undefined1 *)((int)fVar6 + 0x7b5) = 0x47;
    *(float *)(iVar14 + 0x5c) = fVar6;
    *(uint *)((int)fVar6 + 0x7bc) = *(uint *)((int)fVar6 + 0x7bc) | 0x20;
    puVar1 = (ushort *)(*(int *)((int)fVar6 + 0x798) + 0x68);
    *puVar1 = *puVar1 | 0x100;
    if ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x94) & 0x20000000) != 0) {
      *(undefined1 *)((int)fVar6 + 0x7b8) = 1;
      FUN_0058d8e0(fVar6);
      uVar9 = FUN_00547820(fVar6,0);
      FUN_00547930(0x4c,(int)fVar6 + 0x80,uVar9);
      *(undefined1 *)((int)fVar6 + 0x7b3) = 0;
      sVar8 = DAT_00804d20;
      *(undefined4 *)((int)fVar6 + 0x77c) = 0;
      *(short *)((int)fVar6 + 0x7aa) = sVar8;
      fVar21 = (float10)FUN_0062e040((int)*(short *)((int)fVar6 + 0x1064),(int)sVar8,0,0,0);
      *(float *)((int)fVar6 + 0x784) = (float)fVar21;
      if ((float)fVar21 <= 0.0) {
        *(undefined4 *)((int)fVar6 + 0x784) = 0x3f000000;
      }
      *(undefined4 *)((int)fVar6 + 0x748) = *(undefined4 *)((int)fVar6 + 0x5c);
      *(undefined4 *)((int)fVar6 + 0x74c) = *(undefined4 *)((int)fVar6 + 0x60);
      uVar11 = -(uint)(param_1 != 0.0) & 2;
      *(undefined4 *)((int)fVar6 + 0x750) = *(undefined4 *)((int)fVar6 + 100);
      iVar12 = *(int *)((int)fVar6 + 0x798);
      iVar15 = iVar12 + 0x10 + uVar11 * 0xc;
      *(undefined4 *)((int)fVar6 + 0x754) = *(undefined4 *)(iVar12 + 0x10 + uVar11 * 0xc);
      pfVar20 = (float *)((int)fVar6 + 0x754);
      *(undefined4 *)((int)fVar6 + 0x758) = *(undefined4 *)(iVar15 + 4);
      *(undefined4 *)((int)fVar6 + 0x75c) = *(undefined4 *)(iVar15 + 8);
      pfVar18 = (float *)(iVar12 + 0x10 + ((-(uint)(param_1 != 0.0) & 0xfffffffe) + 2) * 0xc);
      pfVar19 = (float *)((int)fVar6 + 0x76c);
      *pfVar19 = *pfVar18;
      *(float *)((int)fVar6 + 0x770) = pfVar18[1];
      *(float *)((int)fVar6 + 0x774) = pfVar18[2];
      if (param_1 == 0.0) {
        param_1 = *(float *)(iVar14 + 0x70);
      }
      else {
        param_1 = *(float *)(iVar14 + 0x6c);
      }
      *(float *)((int)fVar6 + 0x770) = param_1;
      FUN_005b3800(local_24,pfVar19,pfVar20);
      local_20 = 0;
      FUN_005b3b30(local_24,local_24);
      FUN_005b3830(local_24,local_24,_DAT_007ffc28);
      FUN_005b37d0((int)fVar6 + 0x760,pfVar20,local_24);
      *(float *)((int)fVar6 + 0x764) = *(float *)((int)fVar6 + 0x764) + _DAT_007ffc2c;
      param_1 = *pfVar19 - *pfVar20;
      uVar7 = FUN_005be2d0(param_1,*(float *)((int)fVar6 + 0x774) - *(float *)((int)fVar6 + 0x75c));
      *(undefined2 *)((int)fVar6 + 0x5a) = uVar7;
      *(undefined1 *)((int)fVar6 + 0x281) = 0;
      return;
    }
    iVar14 = *(int *)((int)fVar6 + 0x798);
    *(undefined1 *)((int)fVar6 + 0x7b8) = 0;
    *(undefined2 *)((int)fVar6 + 0x7aa) = 0x2a;
    pfVar20 = (float *)(iVar14 + 0x1c);
    if (param_1 == 0.0) {
      *(undefined1 *)((int)fVar6 + 0x7b3) = 0;
      pfVar19 = (float *)(iVar14 + 0x10);
      pfVar18 = (float *)(iVar14 + 0x28);
    }
    else {
      *(undefined1 *)((int)fVar6 + 0x7b3) = 1;
      pfVar19 = (float *)(iVar14 + 0x28);
      pfVar18 = (float *)(iVar14 + 0x10);
    }
    if ((*pfVar20 != *pfVar19) || (pfVar16 = pfVar18, *(float *)(iVar14 + 0x24) != pfVar19[2])) {
      pfVar16 = pfVar20;
    }
    param_1 = *pfVar16 - *pfVar19;
    uVar7 = FUN_005be2d0(param_1,pfVar16[2] - pfVar19[2]);
    *(undefined4 *)((int)fVar6 + 0x6c) = 0;
    *(undefined2 *)((int)fVar6 + 0x5a) = uVar7;
    if (*(char *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x116) == '\x02') {
      FUN_0058d480(fVar6,1);
    }
    *(undefined4 *)((int)fVar6 + 0x77c) = 0;
    FUN_00681f40("GrapAttach",(int)fVar6 + 400);
    FUN_0058d480(fVar6,0);
    *(undefined1 *)((int)fVar6 + 0xe32) = 0;
    fVar2 = *(float *)(iVar14 + 0x24) - pfVar19[2];
    param_1 = (*pfVar20 - *pfVar19) * (*pfVar20 - *pfVar19) + fVar2 * fVar2;
    fVar21 = (float10)FUN_005c0240(param_1);
    param_1 = *(float *)(iVar14 + 0x20) - pfVar19[1];
    iVar14 = FUN_005be2d0(param_1,(float)fVar21);
    uVar4 = (ushort)(iVar14 >> 0x1f);
    sVar8 = 0x4000 - (((ushort)iVar14 ^ uVar4) - uVar4);
    if (iVar14 < 0) {
      sVar8 = -sVar8;
    }
    *(short *)((int)fVar6 + 0x7a4) = sVar8;
    if ((*(byte *)(*(int *)((int)fVar6 + 0x798) + 0x68) & 1) == 0) {
      return;
    }
    FUN_005b3800(*(int *)((int)fVar6 + 0x798) + 0x44,pfVar19,pfVar20);
    FUN_005b3800(&local_c,pfVar18,pfVar20);
    fVar5 = _DAT_007ffca4;
    fVar2 = _DAT_007ffca0;
    local_8 = _DAT_007ffca4 + local_8;
    *(float *)(*(int *)((int)fVar6 + 0x798) + 0x44) =
         _DAT_007ffca0 * *(float *)(*(int *)((int)fVar6 + 0x798) + 0x44);
    *(float *)(*(int *)((int)fVar6 + 0x798) + 0x48) =
         fVar2 * *(float *)(*(int *)((int)fVar6 + 0x798) + 0x48);
    *(float *)(*(int *)((int)fVar6 + 0x798) + 0x48) =
         *(float *)(*(int *)((int)fVar6 + 0x798) + 0x48) + *(float *)((int)fVar6 + 0xb4) * fVar5;
    *(float *)(*(int *)((int)fVar6 + 0x798) + 0x4c) =
         fVar2 * *(float *)(*(int *)((int)fVar6 + 0x798) + 0x4c);
    uVar11 = FUN_005be2d0(*(undefined4 *)(*(int *)((int)fVar6 + 0x798) + 0x44),
                          *(undefined4 *)(*(int *)((int)fVar6 + 0x798) + 0x4c));
    iVar14 = *(int *)((int)fVar6 + 0x798);
    local_18 = *(undefined4 *)(iVar14 + 0x44);
    local_14 = *(float *)(iVar14 + 0x48);
    local_10 = *(float *)(iVar14 + 0x4c);
    FUN_005b3620(&local_18,&local_18,-(uVar11 & 0xffff));
    FUN_005b3620(&local_c,&local_c,-(uVar11 & 0xffff));
    FUN_005b3b30(&local_18,&local_18);
    FUN_005b3b30(&local_c,&local_c);
    param_1 = local_14 * local_8 + local_10 * local_4;
    sVar8 = FUN_004d55d0(param_1);
    *(short *)(*(int *)((int)fVar6 + 0x798) + 0x60) = 0x4000 - sVar8;
    iVar14 = *(int *)((int)fVar6 + 0x798);
    *(undefined4 *)(iVar14 + 0x50) = *(undefined4 *)(iVar14 + 0x44);
    *(undefined4 *)(iVar14 + 0x54) = *(undefined4 *)(iVar14 + 0x48);
    *(undefined4 *)(iVar14 + 0x58) = *(undefined4 *)(iVar14 + 0x4c);
    iVar14 = *(int *)((int)fVar6 + 0x798) + 0x50;
    FUN_005b37d0(iVar14,pfVar20,iVar14);
    return;
  }
  if (*(char *)((int)param_1 + 0x7b8) != '\x01') {
    iVar15 = *(int *)((int)param_1 + 0x798);
    iVar14 = iVar15 + 0x1c;
    pfVar20 = (float *)(iVar15 + 0x28);
    if (*(char *)((int)param_1 + 0x7b3) != '\0') {
      pfVar20 = (float *)(iVar15 + 0x10);
    }
    if ((*(byte *)(iVar15 + 0x68) & 1) == 0) {
      pfVar19 = (float *)((int)param_1 + 0x5c);
      fVar21 = (float10)FUN_005b3c50(pfVar19,iVar14,0);
      if ((fVar21 < (float10)0.010000001) ||
         (fVar2 = *(float *)((int)fVar6 + 0x77c), !NAN(fVar2) && 5.0 < fVar2 != (fVar2 == 5.0))) {
        FUN_00561ba0(fVar6,6);
        FUN_00681f40("GrapDetach",(int)fVar6 + 0x80);
        if ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) {
          FUN_00576960(0x262);
        }
        param_1 = *pfVar20 - *pfVar19;
        uVar7 = FUN_005be2d0(param_1,pfVar20[2] - *(float *)((int)fVar6 + 100));
        *(undefined2 *)((int)fVar6 + 0x27a) = uVar7;
        *(undefined2 *)((int)fVar6 + 0x58) = uVar7;
        *(undefined2 *)((int)fVar6 + 0x5a) = uVar7;
        fVar21 = (float10)FUN_005bed80(pfVar19,pfVar20,0);
        fVar2 = (float)(fVar21 / (float10)*(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) +
                                                    0x30));
        *(float *)((int)fVar6 + 0x788) = fVar2;
        *(float *)((int)fVar6 + 0x68) =
             fVar2 * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
        fVar2 = (float)(&DAT_029899a0)[(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff]
        ;
        *(uint *)((int)fVar6 + 0x7bc) = *(uint *)((int)fVar6 + 0x7bc) & 0xffffffdf;
        *(float *)((int)fVar6 + 0x70) = fVar2 * *(float *)((int)fVar6 + 0x788);
        puVar1 = (ushort *)(*(int *)((int)fVar6 + 0x798) + 0x68);
        *puVar1 = *puVar1 & 0xfeff;
        *(undefined4 *)((int)fVar6 + 0x798) = 0;
        return;
      }
    }
    iVar15 = *(int *)((int)fVar6 + 0x798);
    uVar4 = *(ushort *)(iVar15 + 0x68);
    if (((((uVar4 & 0x40) != 0) && ((char)uVar4 < '\0')) && ((uVar4 & 0x100) != 0)) &&
       ((*(byte *)((int)fVar6 + 0x7bc) & 0x20) != 0)) {
      fVar2 = *(float *)((int)fVar6 + 0x77c);
      if ((*(ushort *)(iVar15 + 0x68) & 1) == 0) {
        *(float *)((int)fVar6 + 0x77c) = fVar2 + _DAT_00925018;
        FUN_00681f40("GrapWindLp",(int)fVar6 + 0x80);
        return;
      }
      if (_DAT_007ffca8 < fVar2 != (_DAT_007ffca8 == fVar2)) {
        *(undefined1 *)((int)fVar6 + 0x7b5) = 0xff;
        *(undefined4 *)((int)fVar6 + 0x77c) = 0;
        *(undefined4 *)(iVar15 + 0x5c) = 0;
        *(uint *)((int)fVar6 + 0x7bc) = *(uint *)((int)fVar6 + 0x7bc) & 0xffffffdf;
        puVar1 = (ushort *)(*(int *)((int)fVar6 + 0x798) + 0x68);
        *puVar1 = *puVar1 & 0xfeff;
        *(undefined4 *)((int)fVar6 + 0xdac) = 0x3e4ccccd;
        *(undefined4 *)((int)fVar6 + 0x798) = 0;
        *(undefined2 *)((int)fVar6 + 0x7a4) = 0;
        *(undefined4 *)((int)fVar6 + 0xf18) = DAT_0093b0cc;
        *(undefined4 *)((int)fVar6 + 0xf1c) = DAT_0093b0d0;
        *(undefined4 *)((int)fVar6 + 0xf20) = DAT_0093b0d4;
        *(undefined4 *)((int)fVar6 + 0xf1c) = 0xbf800000;
        *(undefined4 *)((int)fVar6 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)((int)fVar6 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)((int)fVar6 + 0x70) = DAT_0093b0d4;
        *(undefined4 *)((int)fVar6 + 0x6c) = 0xbf800000;
        FUN_00681f40("GrapDetach",(int)fVar6 + 0x80);
        if ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0) {
          return;
        }
        FUN_00576960(0x262);
        return;
      }
      *(ushort *)(iVar15 + 0x68) = *(ushort *)(iVar15 + 0x68) | 0x200;
      uVar10 = FUN_005be2d0(*(undefined4 *)(iVar15 + 0x44),*(undefined4 *)(iVar15 + 0x4c));
      FUN_005b3800(&local_c,pfVar20,iVar14);
      local_8 = _DAT_007ffca4 + local_8;
      uVar7 = FUN_005be2d0(local_c,local_4);
      uVar11 = FUN_00550040(uVar10 & 0xffff,uVar7);
      uVar11 = 0x8000 - (uVar11 & 0xffff);
      uVar17 = (int)uVar11 >> 0x1f;
      iVar12 = (uVar11 ^ uVar17) - uVar17;
      param_1 = (float)CONCAT22((short)((uint)iVar12 >> 0x10),in_FPUControlWord);
      uVar11 = (int)ROUND((double)iVar12 * 0.5) & 0xffff;
      if ((ushort)uVar10 < 0x8001) {
        uVar11 = -uVar11;
      }
      uVar11 = (uVar10 & 0xffff) + uVar11;
      local_18 = *(undefined4 *)(iVar15 + 0x44);
      local_14 = *(float *)(iVar15 + 0x48);
      local_10 = *(float *)(iVar15 + 0x4c);
      FUN_005b3620(&local_18,&local_18,-uVar11 & 0xffff);
      iVar12 = iVar15 + 0x50;
      param_1 = *(float *)((int)fVar6 + 0x77c) / _DAT_007ffca8;
      FUN_006e6b90();
      param_1 = (float)(uint)*(ushort *)(iVar15 + 0x60);
      uVar9 = FUN_006e6b90();
      FUN_005b35a0(iVar12,&local_18,uVar9);
      FUN_005b3620(iVar12,iVar12,uVar11 & 0xffff);
      iVar13 = FUN_006e6b90();
      *(float *)(iVar15 + 0x54) =
           (1.0 - (1.0 - DAT_0298d9a0) * (float)(&DAT_029899a0)[iVar13 >> 1 & 0x7fff]) *
           *(float *)(iVar15 + 0x54);
      FUN_005b37d0(iVar12,iVar14,iVar12);
      fVar2 = *(float *)((int)fVar6 + 0x77c);
      fVar5 = *(float *)((int)fVar6 + 0x77c) + _DAT_00925018;
      *(float *)((int)fVar6 + 0x77c) = fVar5;
      param_1 = _DAT_007ffca8 * 0.5 - 0.2;
      if (param_1 <= fVar2) {
        return;
      }
      if ((NAN(param_1) || NAN(fVar5)) || param_1 < fVar5 == (param_1 == fVar5)) {
        return;
      }
      FUN_00681f40("GrapSwing",(int)fVar6 + 0x80);
      return;
    }
    *(uint *)((int)fVar6 + 0x7bc) = *(uint *)((int)fVar6 + 0x7bc) & 0xffffffdf;
    *(undefined1 *)((int)fVar6 + 0x7b5) = 0xff;
    *(ushort *)(iVar15 + 0x68) = *(ushort *)(iVar15 + 0x68) & 0xfeff;
    *(undefined4 *)((int)fVar6 + 0x798) = 0;
    return;
  }
  pfVar20 = (float *)0x0;
  if ((*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + *(short *)((int)param_1 + 0x7aa) * 4
               ) == 0) ||
     (pfVar20 = (float *)FUN_0062f150((int)param_1 + 8,(int)*(short *)((int)param_1 + 0x7aa),1,0),
     pfVar20 != (float *)0x0)) {
    param_1 = *(float *)((int)fVar6 + 0x77c) + _DAT_00925018;
    *(float *)((int)fVar6 + 0x77c) = param_1;
    if (*(float *)((int)fVar6 + 0x784) < param_1 != (*(float *)((int)fVar6 + 0x784) == param_1)) {
      *(undefined4 *)((int)fVar6 + 0x77c) = *(undefined4 *)((int)fVar6 + 0x784);
    }
  }
  *(undefined4 *)((int)fVar6 + 0x68) = DAT_0093b0cc;
  *(undefined4 *)((int)fVar6 + 0x6c) = DAT_0093b0d0;
  *(undefined4 *)((int)fVar6 + 0x70) = DAT_0093b0d4;
  cVar3 = *(char *)((int)fVar6 + 0x7b3);
  if (cVar3 != '\0') {
    if (cVar3 == '\x01') {
      param_1 = *(float *)((int)fVar6 + 0x77c) / *(float *)((int)fVar6 + 0x784);
      FUN_005b3800(local_24,(int)fVar6 + 0x760,(int)fVar6 + 0x754);
      FUN_005b3830(local_24,local_24,param_1);
      FUN_005b37d0((int)fVar6 + 0x5c,(int)fVar6 + 0x754,local_24);
      if (*(float *)((int)fVar6 + 0x784) < *(float *)((int)fVar6 + 0x77c) ==
          (*(float *)((int)fVar6 + 0x784) == *(float *)((int)fVar6 + 0x77c))) {
        return;
      }
      *(undefined1 *)((int)fVar6 + 0x7b3) = 2;
      sVar8 = DAT_00804d28;
      *(undefined4 *)((int)fVar6 + 0x77c) = 0;
      *(short *)((int)fVar6 + 0x7aa) = sVar8;
      fVar21 = (float10)FUN_0062e040((int)*(short *)((int)fVar6 + 0x1064),(int)sVar8,0,0,0);
      param_1 = (float)fVar21;
      *(float *)((int)fVar6 + 0x784) = param_1;
      if (param_1 <= 0.0) {
        *(undefined4 *)((int)fVar6 + 0x784) = 0x3f800000;
      }
      FUN_00547f30(fVar6,0);
      return;
    }
    if (cVar3 != '\x02') {
      return;
    }
    param_1 = *(float *)((int)fVar6 + 0x77c) / *(float *)((int)fVar6 + 0x784);
    FUN_005b3800(local_24,(int)fVar6 + 0x76c,(int)fVar6 + 0x760);
    FUN_005b3830(local_24,local_24,param_1);
    FUN_005b37d0((int)fVar6 + 0x5c,(int)fVar6 + 0x760,local_24);
    if (*(float *)((int)fVar6 + 0x784) < *(float *)((int)fVar6 + 0x77c) ==
        (*(float *)((int)fVar6 + 0x784) == *(float *)((int)fVar6 + 0x77c))) {
      return;
    }
    *(undefined1 *)((int)fVar6 + 0x7b5) = 0xff;
    *(undefined4 *)((int)fVar6 + 0x68) = 0;
    *(undefined4 *)((int)fVar6 + 0x6c) = 0xc0000000;
    *(undefined4 *)((int)fVar6 + 0x70) = 0;
    FUN_005621a0(fVar6,(int)DAT_00804bf0);
    return;
  }
  if ((pfVar20 != (float *)0x0) && (0.0 < *pfVar20)) {
    fVar21 = (float10)FUN_0062f1f0(*(undefined4 *)((int)fVar6 + 0x50),
                                   (int)*(short *)((int)fVar6 + 0x7aa),0);
    fVar2 = (float)fVar21;
    if ((1.0 < fVar2) &&
       (param_1 = fVar2,
       fVar21 = (float10)FUN_0062a670(*(undefined4 *)((int)fVar6 + 0x50),
                                      (int)*(short *)((int)fVar6 + 0x7aa)), (float10)fVar2 < fVar21)
       ) {
      param_1 = (*pfVar20 - 1.0) / (param_1 - 1.0);
      if (1.0 < param_1) {
        param_1 = 1.0;
      }
      goto LAB_004d632c;
    }
  }
  param_1 = *(float *)((int)fVar6 + 0x77c) / *(float *)((int)fVar6 + 0x784);
LAB_004d632c:
  FUN_005b3800(local_24,(int)fVar6 + 0x754,(int)fVar6 + 0x748);
  FUN_005b3830(local_24,local_24,param_1);
  FUN_005b37d0((int)fVar6 + 0x5c,(int)fVar6 + 0x748,local_24);
  if (*(float *)((int)fVar6 + 0x784) < *(float *)((int)fVar6 + 0x77c) ==
      (*(float *)((int)fVar6 + 0x784) == *(float *)((int)fVar6 + 0x77c))) {
    return;
  }
  *(undefined1 *)((int)fVar6 + 0x7b3) = 1;
  sVar8 = DAT_00804d24;
  *(undefined4 *)((int)fVar6 + 0x77c) = 0;
  *(short *)((int)fVar6 + 0x7aa) = sVar8;
  fVar21 = (float10)FUN_0062e040((int)*(short *)((int)fVar6 + 0x1064),(int)sVar8,0,0,0);
  param_1 = (float)fVar21;
  *(float *)((int)fVar6 + 0x784) = param_1;
  if (param_1 <= 0.0) {
    *(undefined4 *)((int)fVar6 + 0x784) = 0x3f800000;
  }
  uVar9 = FUN_00547820(fVar6,0);
  FUN_00547930(0x4d,(int)fVar6 + 0x80,uVar9);
  return;
}

