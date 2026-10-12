/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d4dc0; label: FUN_004d4dc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4dc0(int param_1,float param_2)

{
  undefined2 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  undefined2 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  float10 fVar16;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  iVar10 = (int)param_2;
  FUN_004a4ca0((int)param_2 + 0x6c4);
  if (*(char *)((int)param_2 + 0x7b5) == 'V') {
    pfVar15 = (float *)0x0;
    if ((*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) +
                 *(short *)((int)param_2 + 0x7aa) * 4) == 0) ||
       (pfVar15 = (float *)FUN_0062f150((int)param_2 + 8,(int)*(short *)((int)param_2 + 0x7aa),1,0),
       pfVar15 != (float *)0x0)) {
      bVar9 = false;
      uVar11 = FUN_005be2d0(*(float *)(*(int *)((int)param_2 + 0x798) + 0x4c) -
                            *(float *)((int)param_2 + 0x80),
                            *(float *)(*(int *)((int)param_2 + 0x798) + 0x54) -
                            *(float *)((int)param_2 + 0x88));
      *(undefined2 *)((int)param_2 + 0x5a) = uVar11;
      if ((pfVar15 != (float *)0x0) && ((*(byte *)((int)param_2 + 0x7bc) & 0x40) == 0)) {
        fVar16 = (float10)FUN_0062f1f0(*(undefined4 *)((int)param_2 + 0x50),
                                       (int)*(short *)((int)param_2 + 0x7aa),0);
        if ((1.0 <= (float)fVar16) && ((float)fVar16 <= *pfVar15)) {
          bVar9 = true;
        }
      }
      fVar2 = *(float *)((int)param_2 + 0x77c) + _DAT_00925018;
      *(float *)((int)param_2 + 0x77c) = fVar2;
      if (((*(float *)((int)param_2 + 0x784) < fVar2 != (*(float *)((int)param_2 + 0x784) == fVar2))
          && (*(undefined1 *)((int)param_2 + 0x7b5) = 0xff,
             (*(byte *)((int)param_2 + 0x7bc) & 0x40) == 0)) || (bVar9)) {
        *(uint *)((int)param_2 + 0x7bc) = *(uint *)((int)param_2 + 0x7bc) | 0x40;
        FUN_00567800(*(undefined4 *)((int)param_2 + 0x798),1,8,1,0,1);
        return;
      }
    }
  }
  else if (((((*(uint *)(*(int *)(*(int *)((int)param_2 + 0x54) + 0x24) + 0x90) & 0x1000000) != 0)
            && ((*(byte *)((int)param_2 + 0x1fc) & 0x80) != 0)) &&
           (*(char *)((int)param_2 + 0x281) != '\0')) &&
          ((iVar12 = FUN_005620f0(param_2), iVar12 != 0 &&
           (iVar12 = *(int *)(param_1 + 0x50c8), iVar12 != 0)))) {
    puVar1 = (undefined2 *)((int)param_2 + 0x5a);
    param_2 = 4.0;
    iVar14 = 0;
    FUN_005b3620(local_18,&DAT_0080250c,*puVar1);
    fVar2 = *(float *)(iVar10 + 0x80);
    iVar13 = 0;
    fVar3 = *(float *)(iVar10 + 0x84);
    fVar4 = *(float *)(iVar10 + 0x88);
    fVar5 = *(float *)(iVar10 + 0x80);
    fVar6 = *(float *)(iVar10 + 0x84);
    fVar7 = *(float *)(iVar10 + 0x88);
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        uVar8 = *(uint *)(iVar12 + 0x94);
        if ((((((uVar8 & 1) == 0) && ((uVar8 & 0x800000) != 0)) &&
             (((uVar8 & 0x4000) != 0 &&
              (((uVar8 & 0x8000) != 0 && ((*(uint *)(iVar12 + 0x98) & 0x10) != 0)))))) &&
            (((*(uint *)(iVar12 + 0x98) & 0x20) == 0 || (DAT_0087baf0 != 0)))) &&
           ((((fVar2 - 2.0 <= *(float *)(iVar12 + 0x4c) &&
              (*(float *)(iVar12 + 0x4c) <= fVar5 + 2.0)) &&
             (fVar4 - 2.0 <= *(float *)(iVar12 + 0x54))) &&
            (((*(float *)(iVar12 + 0x54) <= fVar7 + 2.0 &&
              (fVar3 - 2.0 <= *(float *)(iVar12 + 0x50))) &&
             (*(float *)(iVar12 + 0x50) <= fVar6 + 2.0)))))) {
          fVar16 = (float10)FUN_005b3c50((float *)(iVar12 + 0x4c),iVar10 + 0x80,local_c);
          if (((float)fVar16 < param_2) && (0.0 < local_18[0] * local_c[0] + local_10 * local_4)) {
            iVar14 = iVar12;
            param_2 = (float)fVar16;
          }
        }
        iVar13 = iVar13 + 1;
        iVar12 = iVar12 + 0x114;
      } while (iVar13 < *(int *)(param_1 + 0x50c0));
      if (iVar14 != 0) {
        *(undefined1 *)(iVar10 + 0xe2c) = 4;
        *(int *)(iVar10 + 0xd14) = iVar14;
        *(undefined4 *)(iVar10 + 0xc68) = *(undefined4 *)(iVar14 + 0x4c);
        *(undefined4 *)(iVar10 + 0xc6c) = *(undefined4 *)(iVar14 + 0x50);
        *(undefined4 *)(iVar10 + 0xc70) = *(undefined4 *)(iVar14 + 0x54);
        *(undefined4 *)(iVar10 + 0xd8c) = *(undefined4 *)(iVar14 + 0xa8);
        *(undefined4 *)(iVar10 + 0xd80) = 0x3f800000;
        if ((*(uint *)(*(int *)(iVar10 + 0xca4) + 4) & DAT_00802280) != 0) {
          *(uint *)(iVar10 + 0x7bc) = *(uint *)(iVar10 + 0x7bc) & 0xffffffbf;
          *(undefined4 *)(iVar10 + 0x77c) = 0;
          *(undefined1 *)(iVar10 + 0x7b5) = 0x56;
          *(int *)(iVar10 + 0x798) = iVar14;
          *(undefined2 *)(iVar10 + 0x7aa) = 0xa0;
          fVar16 = (float10)FUN_0062e040((int)*(short *)(iVar10 + 0x1064),0xa0,0,0,1);
          *(float *)(iVar10 + 0x784) = (float)fVar16;
          if ((float)fVar16 <= 0.0) {
            *(undefined4 *)(iVar10 + 0x784) = 0x3f800000;
          }
          uVar11 = FUN_005be2d0(*(float *)(*(int *)(iVar10 + 0x798) + 0x4c) -
                                *(float *)(iVar10 + 0x80),
                                *(float *)(*(int *)(iVar10 + 0x798) + 0x54) -
                                *(float *)(iVar10 + 0x88));
          *(undefined2 *)(iVar10 + 0x5a) = uVar11;
        }
      }
    }
  }
  return;
}

