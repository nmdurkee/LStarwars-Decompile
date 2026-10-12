/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce830; label: FUN_004ce830
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ce830(float param_1,int param_2)

{
  undefined4 *puVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  float fVar7;
  ushort uVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  bool bVar14;
  float10 fVar15;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar13 = (int)param_1;
  if (((*(uint *)(*(int *)((int)param_1 + 0x54) + 4) & 0x40000) != 0) ||
     (iVar10 = FUN_0041aef0(param_1), iVar10 != 0)) {
    cVar5 = *(char *)((int)param_1 + 0x7b5);
    if (cVar5 == '\x0f') {
      if (*(char *)((int)param_1 + 0x7b3) == '\0') {
        param_1._0_2_ = ~(ushort)(*(int *)((int)param_1 + 0x7bc) << 5) & 0x8000 | 0x4000;
        iVar10 = 0;
        do {
          iVar11 = FUN_005cfac0(*(int *)(iVar13 + 0x798) + 0x5c + iVar10 * 0xc);
          if (iVar11 != 0) {
            uVar12 = FUN_005cf9e0(*(int *)(iVar13 + 0x798) + 0x5c + iVar10 * 0xc,0);
            fVar15 = (float10)FUN_005b3c50(iVar13 + 0x80,uVar12);
            if (fVar15 < (float10)0.36) {
              uVar8 = param_1._0_2_;
              if (iVar10 != 0) {
                uVar8 = -param_1._0_2_;
              }
              *(ushort *)(*(int *)(iVar13 + 0x798) + 0x78 + iVar10 * 2) = uVar8;
              if (((uint)*(ushort *)(iVar13 + 0x7a4) & 1 << ((byte)iVar10 & 0x1f)) == 0) {
                *(ushort *)(iVar13 + 0x7a4) =
                     (ushort)(1 << ((byte)iVar10 & 0x1f)) | *(ushort *)(iVar13 + 0x7a4);
                FUN_00681f40("env_door_flap",iVar13 + 0x80);
              }
            }
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 2);
      }
      if (*(char *)(iVar13 + 0x7b3) == '\0') {
        bVar14 = false;
        if ((*(int *)(*(int *)(*(int *)(iVar13 + 0x50) + 0xc) + *(short *)(iVar13 + 0x7aa) * 4) == 0
            ) || (iVar10 = FUN_0062f1a0(iVar13 + 8), iVar10 == *(short *)(iVar13 + 0x7aa))) {
          fVar4 = *(float *)(iVar13 + 0x77c) - _DAT_00925018;
          *(float *)(iVar13 + 0x77c) = fVar4;
          if (fVar4 < 0.0 != (fVar4 == 0.0)) {
            *(undefined4 *)(iVar13 + 0x77c) = 0;
            *(undefined1 *)(iVar13 + 0x7b5) = 0xff;
            *(undefined1 *)(*(int *)(iVar13 + 0x798) + 0x4f) = 0;
            bVar14 = true;
            if ((*(byte *)(*(int *)(iVar13 + 0x798) + 0x4c) & 0x10) != 0) {
              FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
            }
            FUN_004399e0(iVar13,iVar13 + 0x80);
          }
        }
        fVar7 = 1.0 - *(float *)(iVar13 + 0x77c) / *(float *)(iVar13 + 0x784);
        FUN_004ce450(iVar13);
        iVar11 = *(int *)(*(int *)(*(int *)(iVar13 + 0x798) + 0x40) + 8);
        pfVar2 = (float *)(iVar11 + local_14 * 0xc);
        iVar10 = iVar11 + (int)local_10 * 0xc;
        puVar1 = (undefined4 *)(iVar13 + 0x5c);
        local_c = *pfVar2 + fVar7 * (*(float *)(iVar11 + (int)local_10 * 0xc) - *pfVar2);
        local_8 = (*(float *)(iVar10 + 4) - pfVar2[1]) * fVar7 + pfVar2[1];
        local_4 = (*(float *)(iVar10 + 8) - pfVar2[2]) * fVar7 + pfVar2[2];
        FUN_0054fb80(puVar1,puVar1,&local_c,0x41200000);
        *(undefined4 *)(iVar13 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)(iVar13 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)(iVar13 + 0x70) = DAT_0093b0d4;
        fVar15 = (float10)FUN_005506f0(0,puVar1,0x40a00000,0xffffffff);
        fVar4 = (float)fVar15;
        *(float *)(iVar13 + 0x21c) = fVar4;
        if (fVar4 != 2e+06) {
          *(float *)(iVar13 + 0x60) = fVar4 - *(float *)(iVar13 + 0xff0) * *(float *)(iVar13 + 0xa8)
          ;
        }
        FUN_00572440(iVar13,fVar4 != 2e+06,fVar4);
        *(float *)(iVar13 + 0x60) = fVar7 * 0.0025 + *(float *)(iVar13 + 0x60);
        if (bVar14) {
          if (((*(byte *)(*(int *)(iVar13 + 0x798) + 0x4c) & 4) == 0) &&
             (*(char *)(iVar13 + 0x7b4) == '\0')) {
            *(undefined4 *)(iVar13 + 0x77c) = 0x40000000;
            *(undefined1 *)(iVar13 + 0x7b4) = 1;
            *(undefined1 *)(iVar13 + 0x7b5) = 0xf;
            *(undefined1 *)(iVar13 + 0x7b3) = 1;
            puVar3 = (undefined4 *)
                     (*(int *)(*(int *)(*(int *)(iVar13 + 0x798) + 0x40) + 8) +
                     (2 - (uint)((*(uint *)(iVar13 + 0x7bc) & 0x400) != 0)) * 0xc);
            *(undefined4 *)(iVar13 + 0x8c) = *puVar3;
            *(undefined4 *)(iVar13 + 0x90) = puVar3[1];
            uVar12 = puVar3[2];
            *(undefined4 *)(iVar13 + 0x94) = uVar12;
            *puVar1 = *(undefined4 *)(iVar13 + 0x8c);
            *(undefined4 *)(iVar13 + 0x60) = *(undefined4 *)(iVar13 + 0x90);
            *(undefined4 *)(iVar13 + 100) = uVar12;
            FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
            return;
          }
          *(undefined4 *)(iVar13 + 0x6c) = 0xbdcccccd;
          *(undefined1 *)(iVar13 + 0x281) = 0;
          return;
        }
      }
      else if (*(char *)(iVar13 + 0x7b3) == '\x01') {
        bVar14 = false;
        fVar4 = *(float *)(iVar13 + 0x77c) - _DAT_00925018;
        *(float *)(iVar13 + 0x77c) = fVar4;
        local_10 = 2e+06;
        if (0.0 < fVar4) {
          param_1 = 1.0 - fVar4 * 0.5;
        }
        else {
          param_1 = 1.0;
          *(undefined1 *)(iVar13 + 0x7b3) = 0;
          FUN_004ce450(iVar13);
          FUN_004ce4e0(local_14);
          *(undefined4 *)(iVar13 + 0x77c) = *(undefined4 *)(iVar13 + 0x784);
          iVar10 = *(int *)(*(int *)(*(int *)(iVar13 + 0x798) + 0x40) + 8);
          pfVar2 = (float *)(iVar10 + local_14 * 0xc);
          uVar9 = FUN_005be2d0(*(float *)(iVar10 + 0x7771b000) - *pfVar2,
                               *(float *)(iVar10 + 0x7771b008) - pfVar2[2]);
          *(undefined2 *)(iVar13 + 0x27a) = uVar9;
          *(undefined2 *)(iVar13 + 0x58) = uVar9;
          *(undefined2 *)(iVar13 + 0x5a) = uVar9;
          fVar15 = (float10)FUN_005506f0(0,iVar13 + 0x5c,0x40a00000,0xffffffff);
          local_10 = (float)fVar15;
          *(float *)(iVar13 + 0x21c) = local_10;
          bVar14 = true;
          if (local_10 == 2e+06) {
            FUN_00572440(iVar13,0,local_10);
          }
          else {
            FUN_00572440(iVar13,1,local_10);
          }
        }
        if ((*(uint *)(iVar13 + 0x7bc) & 0x400) == 0) {
          iVar11 = 2;
          iVar10 = 1;
        }
        else {
          iVar11 = 1;
          iVar10 = 2;
        }
        iVar6 = *(int *)(*(int *)(*(int *)(iVar13 + 0x798) + 0x40) + 8);
        pfVar2 = (float *)(iVar6 + iVar11 * 0xc);
        iVar11 = iVar6 + iVar10 * 0xc;
        *(float *)(iVar13 + 0x5c) = *pfVar2 + param_1 * (*(float *)(iVar6 + iVar10 * 0xc) - *pfVar2)
        ;
        *(float *)(iVar13 + 0x60) = (*(float *)(iVar11 + 4) - pfVar2[1]) * param_1 + pfVar2[1];
        *(float *)(iVar13 + 100) = (*(float *)(iVar11 + 8) - pfVar2[2]) * param_1 + pfVar2[2];
        *(undefined4 *)(iVar13 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)(iVar13 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)(iVar13 + 0x70) = DAT_0093b0d4;
        if ((bVar14) && (local_10 != 2e+06)) {
          *(float *)(iVar13 + 0x60) =
               local_10 - *(float *)(iVar13 + 0xff0) * *(float *)(iVar13 + 0xa8);
          return;
        }
      }
    }
    else if (((((*(char *)((int)param_1 + 0x281) != '\0') &&
               (*(char *)((int)param_1 + 0x28b) == '\0')) &&
              ((cVar5 == -1 ||
               ((((cVar5 == '\x01' || (cVar5 == '\x02')) || (cVar5 == '\x03')) ||
                ((cVar5 == '\x04' || (iVar13 = FUN_00578790(param_1,0xf), iVar13 != 0)))))))) &&
             (((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0 ||
              (*(char *)((int)param_1 + 0xf00) == '\x03')))) &&
            (iVar13 = FUN_004ce220(param_1,0), iVar13 != 0)) {
      iVar10 = FUN_00578790(param_1,0xf);
      if ((iVar10 != 0) &&
         (fVar4 = *(float *)((int)param_1 + 0x77c) - _DAT_00925018,
         *(float *)((int)param_1 + 0x77c) = fVar4, fVar4 <= 0.0)) {
        *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
        *(undefined4 *)((int)param_1 + 0x7a0) = 0;
      }
      if ((param_2 != 0) ||
         ((iVar10 = FUN_00578790(param_1,0xf), iVar10 != 0 && (*(int *)((int)param_1 + 0x7a0) != 0))
         )) {
        bVar14 = DAT_0088060c == 0;
        *(undefined1 *)((int)param_1 + 0x7b5) = 0xf;
        *(int *)((int)param_1 + 0x798) = iVar13;
        *(undefined1 *)(iVar13 + 0x4f) = 1;
        *(uint *)((int)param_1 + 0x7bc) =
             *(uint *)((int)param_1 + 0x7bc) ^
             ((uint)bVar14 << 10 ^ *(uint *)((int)param_1 + 0x7bc)) & 0x400;
        FUN_00547f30(param_1,0);
        if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0) {
          FUN_00576960(0x268);
        }
        *(undefined2 *)((int)param_1 + 0x7aa) = 0x1e;
        *(undefined1 *)((int)param_1 + 0x7b3) = 0;
        *(undefined1 *)((int)param_1 + 0x7b4) = 0;
        FUN_004ce450(param_1);
        FUN_004ce4e0(local_14);
        *(undefined4 *)((int)param_1 + 0x77c) = *(undefined4 *)((int)param_1 + 0x784);
        iVar13 = *(int *)(*(int *)(*(int *)((int)param_1 + 0x798) + 0x40) + 8);
        pfVar2 = (float *)(iVar13 + local_14 * 0xc);
        uVar9 = FUN_005be2d0(*(float *)(iVar13 + (int)local_10 * 0xc) - *pfVar2,
                             *(float *)(iVar13 + 8 + (int)local_10 * 0xc) - pfVar2[2]);
        *(undefined2 *)((int)param_1 + 0x5a) = uVar9;
        *(undefined4 *)((int)param_1 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)((int)param_1 + 0x6c) = DAT_0093b0d0;
        uVar12 = DAT_0093b0d4;
        *(undefined2 *)((int)param_1 + 0x7a4) = 0;
        *(undefined4 *)((int)param_1 + 0x70) = uVar12;
        return;
      }
      if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0) {
        *(uint *)((int)param_1 + 0xe24) = *(uint *)((int)param_1 + 0xe24) | 0x20;
        return;
      }
    }
  }
  return;
}

