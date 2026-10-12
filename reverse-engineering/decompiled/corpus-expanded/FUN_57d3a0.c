/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57d3a0; label: FUN_0057d3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057d3a0(int param_1,int param_2,float *param_3,int param_4,float param_5,int param_6)

{
  byte bVar1;
  short sVar2;
  int *piVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  int *piVar8;
  short *psVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  float10 fVar17;
  int iVar18;
  int *local_46bc;
  float fStack_46b8;
  int local_46b4;
  float local_46b0;
  int local_46ac;
  uint local_46a8;
  undefined4 *local_46a4;
  float fStack_46a0;
  short *local_469c;
  undefined2 auStack_4698 [2];
  int local_4694;
  undefined4 uStack_4690;
  int *local_468c;
  int iStack_4688;
  int local_4684;
  int local_4680;
  int local_467c;
  undefined4 *puStack_4678;
  float local_4674;
  float local_4670;
  int iStack_466c;
  int iStack_4668;
  uint local_4664;
  uint uStack_4660;
  int local_465c;
  int local_4658;
  float local_4654;
  undefined4 uStack_4650;
  float fStack_464c;
  undefined4 uStack_4648;
  undefined4 local_4644 [12];
  undefined4 local_4614;
  undefined4 local_4610;
  undefined4 local_460c;
  undefined4 uStack_45d4;
  float fStack_45d0;
  undefined4 uStack_45cc;
  undefined1 auStack_45c4 [64];
  undefined4 auStack_4584 [16];
  undefined1 auStack_4544 [64];
  undefined4 auStack_4504 [48];
  undefined4 auStack_4444 [256];
  undefined1 auStack_4044 [16384];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_46bc;
  local_468c = (int *)0x49f42400;
  local_467c = param_1;
  local_4658 = param_2;
  local_46b4 = param_4;
  local_4694 = -1;
  local_46b0 = 0.0;
  local_4684 = FUN_0055f450();
  piVar11 = *(int **)(local_4684 + 0x2ab0);
  if (piVar11 == (int *)0x0) goto LAB_0057e240;
  piVar8 = (int *)0x0;
  iVar6 = 0;
  local_46bc = (int *)0x0;
  if (piVar11[1] < 1) {
LAB_0057d449:
    if ((*(byte *)(local_46b4 + 0x5c) & 2) == 0) {
      local_46b0 = *param_3;
      psVar9 = *(short **)((int)local_46b0 + 0x50);
    }
    else {
      psVar9 = (short *)*param_3;
    }
  }
  else {
    do {
      if (piVar8 != (int *)0x0) goto LAB_0057d45c;
      piVar3 = *(int **)(*piVar11 + iVar6 * 4);
      if (piVar3[1] == param_1) {
        piVar8 = piVar3;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < piVar11[1]);
    local_46bc = piVar8;
    if (piVar8 == (int *)0x0) goto LAB_0057d449;
LAB_0057d45c:
    local_46bc = piVar8;
    if (((DAT_00951c9c == (code *)0x0) || (iVar6 = (*DAT_00951c9c)(piVar8,local_46b4), iVar6 == -1))
       || (sVar2 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + iVar6 * 2), sVar2 == -1))
    goto LAB_0057d449;
    psVar9 = (short *)(sVar2 * 0x54 + *(int *)(DAT_029130e4 + 0x18));
  }
  local_46ac = *(int *)(psVar9 + 2);
  local_469c = psVar9;
  if (local_46ac == 0) goto LAB_0057e240;
  local_4680 = (int)*psVar9;
  local_46a8 = local_4680 * 0x4c + *(int *)(DAT_029130e4 + 0x20);
  puVar12 = *(undefined4 **)(local_46a8 + 0x24);
  local_46a4 = puVar12;
  FUN_00503050(local_46b4,param_5,local_4644,&local_465c,&local_4664,&local_4674,&local_4654,
               &local_4670,&local_4694);
  if (param_6 != 0) {
    local_4674 = 0.0;
  }
  if (local_4694 == -1) {
    if (PTR_DAT_00803e00[7] == '\0') {
      local_4694 = puVar12[0x27];
    }
    else {
      local_4694 = puVar12[0x28];
    }
  }
  if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
    FUN_005b5430(local_4644,local_4644,param_1 + 0x18);
  }
  if (local_46b0 != 0.0) {
    puVar12 = local_4644;
    puVar13 = (undefined4 *)((int)local_46b0 + 0xb8);
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)((int)local_46b0 + 0x5c) = local_4614;
    *(undefined4 *)((int)local_46b0 + 0x60) = local_4610;
    *(undefined4 *)((int)local_46b0 + 100) = local_460c;
    puVar12 = local_46a4;
  }
  if ((local_465c == 0) ||
     (iStack_4688 = (*(code *)*puVar12)(psVar9,local_44,local_4694), iStack_4688 < 1))
  goto LAB_0057e240;
  bVar1 = *(byte *)((int)param_3 + 0x15);
  if (local_4664 != bVar1) {
    cVar7 = (char)local_4664;
    if ((local_4654 <= 0.0) || (bVar1 == 0xff)) {
      *(char *)((int)param_3 + 0x16) = cVar7;
      if (local_4670 <= 1.0) {
        param_3[3] = 1.0;
      }
      else {
        param_3[3] = local_4670;
      }
    }
    else {
      if ((*(byte *)(param_3 + 5) & 1) == 0) {
        if (bVar1 == 0) {
          *(char *)((int)param_3 + 0x16) = cVar7;
          fVar4 = param_5;
          goto LAB_0057d620;
        }
        *(byte *)((int)param_3 + 0x16) = bVar1;
      }
      else {
        *(undefined1 *)((int)param_3 + 0x16) = *(undefined1 *)((int)param_3 + 0x17);
        fVar4 = param_3[4];
LAB_0057d620:
        param_3[3] = fVar4;
      }
      *(char *)((int)param_3 + 0x17) = cVar7;
      if (local_4670 <= 1.0) {
        param_3[4] = 1.0;
      }
      else {
        param_3[4] = local_4670;
      }
      if (cVar7 != *(char *)((int)param_3 + 0x16)) {
        param_3[1] = 0.0;
        *(byte *)(param_3 + 5) = *(byte *)(param_3 + 5) | 1;
      }
    }
    *(char *)((int)param_3 + 0x15) = cVar7;
  }
  if ((*(byte *)(param_3 + 5) & 1) != 0) {
    if (0.0 < local_4654) {
      param_3[1] = param_3[1] + _DAT_00925018 * 60.0 * (1.0 / local_4654);
    }
    else {
      param_3[1] = 1.0;
    }
    if (1.0 < param_3[1] != (param_3[1] == 1.0)) {
      param_3[1] = 0.0;
      param_3[3] = param_3[4];
      *(undefined1 *)((int)param_3 + 0x16) = *(undefined1 *)((int)param_3 + 0x17);
      *(byte *)(param_3 + 5) = *(byte *)(param_3 + 5) ^ 1;
    }
  }
  if (*(byte *)((int)param_3 + 0x16) == 0) {
    param_3[3] = param_5;
    fStack_46b8 = *(float *)(local_46b4 + 0x48);
    iVar6 = *(int *)(local_46b4 + 0x4c);
  }
  else {
    iVar6 = (uint)*(byte *)((int)param_3 + 0x16) * 4;
    fStack_46b8 = *(float *)(*(int *)(local_469c + 6) + -4 + iVar6);
    iVar6 = *(int *)(*(int *)(local_469c + 8) + -4 + iVar6);
  }
  if (((uint)param_3[5] & 1) == 0) {
    if (fStack_46b8 == 0.0) {
      FUN_005d36d0(local_46ac,0,0,auStack_4044);
    }
    else {
      FUN_005f38c0(local_46ac,fStack_46b8,param_3[3]);
    }
    if (iVar6 == 0) {
      uStack_4690 = 0;
    }
    else {
      uStack_4690 = FUN_005d3a20(iStack_4688,local_44,iVar6,param_3[3]);
    }
  }
  else {
    if (*(byte *)((int)param_3 + 0x17) == 0) {
      param_3[4] = param_5;
      iVar15 = *(int *)(local_46b4 + 0x48);
      iVar14 = *(int *)(local_46b4 + 0x4c);
    }
    else {
      iVar14 = (uint)*(byte *)((int)param_3 + 0x17) * 4;
      iVar15 = *(int *)(*(int *)(local_469c + 6) + -4 + iVar14);
      iVar14 = *(int *)(*(int *)(local_469c + 8) + -4 + iVar14);
    }
    if (fStack_46b8 == 0.0) {
      if (iVar15 == 0) {
        FUN_005d36d0(local_46ac,0,0,auStack_4044);
      }
      else {
        FUN_005f38c0(local_46ac,iVar15,param_3[4],0,0,auStack_4044);
      }
    }
    else if (iVar15 == 0) {
      FUN_005f38c0(local_46ac,fStack_46b8,param_3[3],0,0,auStack_4044);
    }
    else {
      FUN_005f38f0(local_46ac,fStack_46b8,param_3[3],iVar15,param_3[4],param_3[1]);
    }
    if ((iVar6 == 0) || (iVar14 == 0)) {
      uStack_4690 = 0;
    }
    else {
      uStack_4690 = FUN_005d3dc0(iStack_4688,local_44,iVar6,param_3[3],iVar14,param_3[4],param_3[1])
      ;
    }
    if ((((iVar15 != 0) && (bVar1 = *(byte *)((int)param_3 + 0x17), bVar1 != 0xff)) && (bVar1 != 0))
       && (((local_46bc == (int *)0x0 || (local_46bc != DAT_00951be8)) || (DAT_00951c58 == 0)))) {
      fVar17 = (float10)FUN_0062a670(local_469c,bVar1 - 1);
      local_46b0 = (float)fVar17;
      fStack_46a0 = _DAT_00925018 * 60.0 * local_4674 + param_3[4];
      param_3[4] = fStack_46a0;
      if (local_46b0 < fStack_46a0) {
        if ((*(byte *)(*(int *)(*(int *)(local_469c + 4) + (bVar1 - 1) * 4) + 4) & 2) == 0) {
          param_3[4] = local_46b0;
        }
        else {
          param_3[4] = (fStack_46a0 - local_46b0) + 1.0;
        }
      }
    }
  }
  psVar9 = local_469c;
  FUN_0062e1e0(local_469c,local_4644,auStack_4044,auStack_4504,auStack_4444);
  if (((fStack_46b8 != 0.0) && (bVar1 = *(byte *)((int)param_3 + 0x16), bVar1 != 0xff)) &&
     ((bVar1 != 0 &&
      (((local_46bc == (int *)0x0 || (local_46bc != DAT_00951be8)) || (DAT_00951c58 == 0)))))) {
    fVar17 = (float10)FUN_0062a670(psVar9,bVar1 - 1);
    local_46b0 = (float)fVar17;
    fStack_46a0 = _DAT_00925018 * 60.0 * local_4674 + param_3[3];
    param_3[3] = fStack_46a0;
    if (local_46b0 < fStack_46a0) {
      if ((*(byte *)(*(int *)(*(int *)(psVar9 + 4) + (bVar1 - 1) * 4) + 4) & 2) == 0) {
        param_3[3] = local_46b0;
      }
      else {
        param_3[3] = (fStack_46a0 - local_46b0) + 1.0;
      }
    }
  }
  FUN_00596920(0);
  iVar6 = FUN_0056e0f0(1);
  if (iVar6 == 0) {
    FUN_00595910(&local_4614,0x3f800000,*(undefined4 *)(local_4684 + 0x2ab4));
  }
  else {
    FUN_005958b0();
  }
  puVar12 = local_46a4;
  iVar15 = local_46ac;
  iVar6 = local_46b4;
  if ((((*(byte *)(local_46b4 + 0x5c) & 0x20) == 0) && ((*(uint *)(local_46a8 + 4) & 0x10000) != 0))
     && ((*(byte *)(local_46b4 + 0x5c) & 0x10) != 0)) {
    *(undefined1 *)(local_46ac + 0x1a0) = 0;
  }
  else {
    *(undefined1 *)(local_46ac + 0x1a0) = 1;
  }
  if ((local_46a4[0x24] & 0x8000) != 0) {
    FUN_0062fac0(local_46ac,local_4644,iStack_4688,local_44,auStack_4044,uStack_4690,
                 *(byte *)(local_46b4 + 0x5c) & 8);
  }
  FUN_005f4ff0(iVar15,local_4644,iStack_4688,local_44,auStack_4044,uStack_4690,
               *(byte *)(iVar6 + 0x5c) & 8);
  puVar13 = (undefined4 *)0x0;
  puStack_4678 = (undefined4 *)0x0;
  if ((*(byte *)(local_46a8 + 0x40) & 1) != 0) {
    iVar6 = (int)*(char *)(puVar12 + 0x44);
    if ((iVar6 == -1) || (*(int *)(psVar9 + iVar6 * 2 + 10) == 0)) {
      puVar13 = local_4644;
    }
    else {
      puVar13 = auStack_4444 + iVar6 * 0x10;
    }
    puStack_4678 = puVar13;
    FUN_0055b570(local_4684,local_4680,puVar13,0);
  }
  thunk_FUN_005d05b0();
  local_46bc = (int *)0x49f42400;
  uVar10 = 0xffffffff;
  iVar6 = -1;
  iVar15 = 0;
  uStack_4660 = 0xffffffff;
  iStack_4668 = -1;
  iStack_466c = 0;
  if (((((*(byte *)(local_46b4 + 0x5c) & 0x10) != 0) && (DAT_00951bf0 != 0)) &&
      ((*(uint *)(local_46a8 + 4) & 0x10000) == 0)) &&
     ((DAT_008264bc == 1 && (DAT_008264c4 != '\0')))) {
    bVar1 = *(byte *)((int)local_46a4 + 0xf6);
    if (*(byte *)((int)local_46a4 + 0xf6) == 0xff) {
      bVar1 = DAT_00951bf0;
    }
    fStack_46a0 = (float)(uint)bVar1;
    if (fStack_46a0 != 0.0) {
      if (*(short *)(local_46a4 + 0x3c) == 0) {
        if (99.0 <= (float)local_46a4[0x23]) {
          fStack_46b8 = *(float *)(local_46a8 + 0x3c) * *(float *)(local_46a8 + 0x30);
          fStack_46b8 = fStack_46b8 + fStack_46b8;
        }
        else {
          fStack_46b8 = (float)local_46a4[0x23];
        }
        if (0.0 < fStack_46b8) {
          fVar17 = (float10)FUN_005506f0(0,&local_4614,0x40a00000,0xffffffff);
          local_46bc = (int *)(float)fVar17;
          iVar15 = 1;
          if ((float)local_46bc != 2e+06) {
            iVar6 = FUN_0067a6e0();
            uVar10 = FUN_0067a600();
            if (0.0 < DAT_0292fdbc) {
              uStack_45d4 = local_4614;
              fStack_45d0 = (float)local_46bc + 0.005;
              uStack_45cc = local_460c;
              fVar17 = (float10)FUN_00550830(&uStack_45d4,_DAT_00951c50,_DAT_00951c6c,DAT_0292fdbc);
              local_46b0 = (float)fVar17;
              if (0.0 < local_46b0) {
                FUN_0054fec0(&DAT_0292fdb8,&local_46a8,auStack_4698);
                uVar5 = FUN_006e6b90(local_46a8 & 0xffff,0,auStack_4698[0]);
                FUN_005fee80(&uStack_45d4,fStack_46b8,uVar5);
              }
            }
          }
        }
      }
      else {
        if (99.0 <= (float)local_46a4[0x23]) {
          fStack_46b8 = *(float *)(local_46a8 + 0x3c) * *(float *)(local_46a8 + 0x30);
        }
        else {
          fStack_46b8 = (float)local_46a4[0x23];
        }
        if (0.0 < fStack_46b8) {
          fVar17 = (float10)FUN_00550830(&local_4614,_DAT_00951c50,_DAT_00951c6c,0x3f800000);
          puVar12 = local_46a4;
          local_46b0 = (float)fVar17;
          if (0.0 < local_46b0) {
            fStack_46a0 = local_46b0 * (float)(int)fStack_46a0;
            iVar14 = 0;
            puVar16 = auStack_4504;
            piVar11 = (int *)(local_469c + 10);
            do {
              if ((((uint)*(ushort *)(puVar12 + 0x3c) & 1 << ((byte)iVar14 & 0x1f)) != 0) &&
                 (*piVar11 != 0)) {
                uStack_4650 = *puVar16;
                fVar17 = (float10)FUN_005506f0(0,puVar16,0x40a00000,0xffffffff);
                fStack_464c = (float)fVar17;
                uStack_4648 = puVar16[2];
                if ((fStack_464c != 2e+06) && (0.0 < DAT_0292fdbc)) {
                  fStack_464c = fStack_464c + 0.005;
                  FUN_0054fec0(&DAT_0292fdb8,&local_46a8,auStack_4698);
                  uVar5 = FUN_006e6b90(local_46a8 & 0xffff,0,auStack_4698[0]);
                  FUN_005fee80(&uStack_4650,fStack_46b8,uVar5);
                }
              }
              iVar14 = iVar14 + 1;
              piVar11 = piVar11 + 1;
              puVar16 = puVar16 + 3;
              iVar6 = iStack_4668;
              uVar10 = uStack_4660;
              puVar13 = puStack_4678;
              iVar15 = iStack_466c;
            } while (iVar14 < 0x10);
          }
        }
      }
    }
  }
  if ((((*(byte *)(local_46b4 + 0x5c) & 0x20) != 0) && ((local_46a4[0x24] & 0x8000) == 0)) &&
     (fVar17 = (float10)FUN_005b3c50(&local_4614,PTR_DAT_008021b4 + 0xe8,0),
     fVar17 < (float10)_DAT_00951c00)) {
    if (iVar15 == 0) {
      fVar17 = (float10)FUN_005506f0(0,&local_4614,0x40a00000,0xffffffff);
      local_46bc = (int *)(float)fVar17;
      if ((float)local_46bc != 2e+06) {
        iVar6 = FUN_0067a6e0();
        uVar10 = FUN_0067a600();
      }
    }
    if ((0x1f < uVar10) || (((&DAT_008034cc)[uVar10 * 0xc] & 2) == 0)) {
      local_46bc = (int *)0x49f42400;
    }
    if (((float)local_46bc == 2e+06) && (iVar6 != -1)) {
      fVar17 = (float10)FUN_00553500(&local_4614);
      local_46bc = (int *)(float)fVar17;
    }
    if ((float)local_46bc != 2e+06) {
      local_468c = local_46bc;
      iVar6 = FUN_00550490(local_4644,2,local_46bc,
                           *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),auStack_4544);
      if (iVar6 != 0) {
        FUN_005d4690(0);
        FUN_005f4ff0(local_46ac,auStack_4544,iStack_4688,local_44,auStack_4044,uStack_4690,
                     *(byte *)(local_46b4 + 0x5c) & 8);
        if ((puVar13 != (undefined4 *)0x0) &&
           (iVar6 = FUN_00550490(puVar13,2,local_46bc,
                                 *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                 auStack_45c4), iVar6 != 0)) {
          FUN_0055b570(local_4684,local_4680,0,auStack_45c4);
        }
        FUN_005d46b0();
      }
    }
  }
  if (((*(short *)(PTR_DAT_00803e00 + 4) != -1) && (PTR_DAT_00803e00[6] != -1)) &&
     (iVar6 = FUN_0056e160((int)(char)PTR_DAT_00803e00[6]), iVar6 != 0)) {
    DAT_0093b0ec = local_469c;
    DAT_00802540 = local_4680;
    DAT_0093b0e8 = local_46a4;
    DAT_0093b0f0 = 0;
    DAT_0093b0f4 = 2;
    if ((float)local_468c == 2e+06) {
      DAT_0093b0f4 = 0;
    }
    _DAT_00802544 = local_468c;
    FUN_00552e90(0,0,(int)*(short *)(PTR_DAT_00803e00 + 4),0,(int)*(char *)((int)local_46a4 + 0x10e)
                 ,0xffffffff,auStack_4444,(float)local_468c != 2e+06,local_4694,0,0,0x3f800000,
                 0x3f800000);
  }
  if (*(char *)(local_46b4 + 0x60) != -1) {
    piVar11 = *(int **)(local_4658 + 0x1c);
    local_468c = *(int **)(local_467c + 0xa8);
    iVar6 = 0;
    if (*(char *)(local_46b4 + 0x5e) != '\0') {
      do {
        iVar15 = *piVar11;
        iVar14 = (uint)*(byte *)(local_46b4 + 0x60) + iVar6;
        bVar1 = *(byte *)(iVar15 + 0x5a + iVar14 * 100);
        if (bVar1 == 0xff) {
          puVar12 = local_4644;
          iVar18 = *local_468c + iVar14 * 8;
        }
        else {
          FUN_005c0500(auStack_4584,auStack_4044 + (uint)bVar1 * 0x40,local_4644);
          puVar12 = auStack_4584;
          iVar15 = *piVar11;
          iVar18 = *local_468c + iVar14 * 8;
        }
        FUN_00507c50(local_467c,piVar11,iVar18,iVar15 + iVar14 * 100,param_5,puVar12,param_6);
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)(uint)*(byte *)(local_46b4 + 0x5e));
    }
  }
LAB_0057e240:
  __security_check_cookie(local_4 ^ (uint)&local_46bc);
  return;
}

