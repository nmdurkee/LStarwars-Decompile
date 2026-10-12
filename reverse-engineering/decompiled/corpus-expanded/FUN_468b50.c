/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x468b50; label: FUN_00468b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468b50(int param_1,int param_2)

{
  ushort *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  bool bVar10;
  undefined2 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  int *piVar16;
  float10 fVar17;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  ulonglong uVar18;
  float local_60;
  int local_5c;
  int *local_58;
  uint local_54;
  int local_50;
  int local_4c;
  int local_48;
  float local_44;
  int local_40;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((((param_1 != 0) && (param_2 != 0)) &&
      (piVar5 = *(int **)(param_1 + 0x2ac8), piVar5 != (int *)0x0)) && (*piVar5 != 0)) {
    *(ushort *)(param_2 + 0x3c) = *(ushort *)(param_2 + 0x3c) & 0xfffe;
    *(ushort *)(param_2 + 100) = *(ushort *)(param_2 + 100) & 0xfffe;
    *(ushort *)(param_2 + 0x8c) = *(ushort *)(param_2 + 0x8c) & 0xfffe;
    *(ushort *)(param_2 + 0xb4) = *(ushort *)(param_2 + 0xb4) & 0xfffe;
    *(ushort *)(param_2 + 0xdc) = *(ushort *)(param_2 + 0xdc) & 0xfffe;
    *(ushort *)(param_2 + 0x104) = *(ushort *)(param_2 + 0x104) & 0xfffe;
    *(ushort *)(param_2 + 300) = *(ushort *)(param_2 + 300) & 0xfffe;
    *(ushort *)(param_2 + 0x154) = *(ushort *)(param_2 + 0x154) & 0xfffe;
    *(undefined2 *)(param_2 + 0x10) = 0;
    *(undefined2 *)(param_2 + 0x12) = 0;
    local_40 = *piVar5 + DAT_007f8cc4 * 0x14;
    local_58 = *(int **)(local_40 + 0xc);
    local_48 = 0;
    if (0 < *(int *)(*piVar5 + 4 + DAT_007f8cc4 * 0x14)) {
      do {
        fVar17 = (float10)0;
        iVar6 = *local_58;
        iVar12 = *(int *)(iVar6 + 0x38);
        bVar9 = false;
        if (((iVar12 != 0) && (*(int *)(iVar6 + 0x40) != 0)) &&
           (((*(byte *)(iVar6 + 0xa0) & 0x20) == 0 &&
            (((*(byte *)(*(int *)(iVar6 + 0x40) + 0x24) & 1) != 0 &&
             (*(char *)(iVar12 + 0x7b5) == '\b')))))) {
          *(undefined1 *)(iVar12 + 0x7b5) = 0xff;
          *(undefined4 *)(*(int *)(iVar6 + 0x38) + 0x10cc) = 0;
          *(undefined4 *)(iVar6 + 0x38) = 0;
        }
        local_5c = *(int *)(iVar6 + 0x38);
        *(undefined4 *)(iVar6 + 0x38) = 0;
        local_50 = 0;
        local_4c = 0;
        *(uint *)(iVar6 + 0xa0) =
             *(uint *)(iVar6 + 0xa0) ^
             ((uint)(local_5c != 0) << 0x15 ^ *(uint *)(iVar6 + 0xa0)) & 0x200000;
        uVar7 = *(uint *)(iVar6 + 0xa0);
        local_54 = *(byte *)(*(int *)(iVar6 + 0x28) + 10) >> 1 & 1;
        *(uint *)(iVar6 + 0xa0) = uVar7 & 0xffffff7f;
        if (((uVar7 & 0x1000) != 0) && (fVar17 == (float10)*(float *)(iVar6 + 0x50))) {
          local_30 = (float)fVar17;
          if ((*(byte *)(iVar6 + 0xa0) & 0x20) != 0) {
            fVar17 = (float10)FUN_005a1500(*(undefined4 *)(iVar6 + 0x28));
            fVar17 = fVar17 * (float10)*(float *)(*(int *)(iVar6 + 0x40) + 0x20);
          }
          local_2c = (float)fVar17;
          local_28 = 0.0;
          FUN_005a1480(*(undefined4 *)(iVar6 + 0x28),&local_30);
          *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xffffefff;
        }
        uVar7 = *(uint *)(iVar6 + 0xa0);
        if (((((uVar7 & 2) != 0) && ((uVar7 & 1) != 0)) && (*(int *)(iVar6 + 0x28) != 0)) &&
           (((uVar7 & 0x10) == 0 && ((uVar7 & 0x10000) == 0)))) {
          iVar12 = FUN_005d6620(iVar6 + 0x1c,*(undefined4 *)(iVar6 + 0x68),&DAT_00806680);
          if (iVar12 == 0) {
            *(int *)(*(int *)(param_2 + 4) + (uint)*(ushort *)(param_2 + 0x10) * 4) = iVar6;
            *(short *)(param_2 + 0x10) = *(short *)(param_2 + 0x10) + 1;
            *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x80;
          }
          if (((local_5c != 0) || (*(float *)(iVar6 + 100) <= 1.0)) ||
             (((*(byte *)(iVar6 + 0x74) & 2) != 0 ||
              (((*(int *)(iVar6 + 0x40) != 0 ||
                (fVar17 = (float10)FUN_005a1370(*(undefined4 *)(iVar6 + 0x28)),
                fVar17 <= (float10)*(float *)(iVar6 + 100))) ||
               (iVar12 = FUN_00467860(iVar6), iVar12 != 0)))))) {
            bVar10 = false;
          }
          else {
            bVar10 = true;
          }
          iVar12 = local_5c;
          fVar17 = (float10)FUN_00467310();
          *(float *)(iVar6 + 0x58) = (float)fVar17;
          if (((iVar12 != 0) || (bVar10)) || ((*(uint *)(iVar6 + 0xa0) & 0x8000) != 0)) {
            *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xffffbfff;
            local_50 = 1;
            FUN_00467450(iVar6);
            uVar7 = *(uint *)(iVar6 + 0xa0);
            if ((uVar7 & 0x40) == 0) {
              *(undefined4 *)(iVar6 + 0x48) = *(undefined4 *)(iVar6 + 0x44);
              if (((*(float *)(iVar6 + 0x4c) <= 0.0) || ((uVar7 & 0x2000) != 0)) ||
                 (*(int *)(*(int *)(iVar6 + 0x28) + 0xc) != 2)) {
LAB_00468f03:
                *(undefined4 *)(iVar6 + 0x50) = 0;
              }
              else {
                bVar9 = *(float *)(iVar6 + 0x50) == 0.0;
                local_44 = *(float *)(iVar6 + 0x50) + _DAT_00925018;
                *(float *)(iVar6 + 0x50) = local_44;
                if (*(float *)(iVar6 + 0x4c) < local_44 != (*(float *)(iVar6 + 0x4c) == local_44)) {
                  *(uint *)(iVar6 + 0xa0) = uVar7 | 0x2000;
                  goto LAB_00468f03;
                }
              }
              if (((((*(byte *)(iVar6 + 0x74) & 0x40) != 0) &&
                   ((*(uint *)(iVar6 + 0xa0) & 0x800) == 0)) &&
                  (uVar18 = FUN_00467860(iVar6), (int)uVar18 != 0)) &&
                 ((extraout_ST0_00 == (float10)*(float *)(iVar6 + 0x4c) ||
                  ((uVar18 & 0x200000000000) != 0)))) {
                FUN_005a15e0(*(undefined4 *)(iVar6 + 0x28),0);
                *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x800;
              }
            }
            else {
              *(undefined4 *)(iVar6 + 0x48) = 0;
              *(undefined4 *)(iVar6 + 0x50) = 0;
            }
          }
          else {
            *(undefined4 *)(iVar6 + 0x50) = 0;
            uVar18 = FUN_00467860(iVar6);
            if ((int)uVar18 == 0) {
              FUN_00467470(iVar6);
            }
            else if (((uVar18 & 0x2000000000) == 0) &&
                    (((*(uint *)(iVar6 + 0x74) & 2) != 0 ||
                     (extraout_ST0 < (float10)*(float *)(iVar6 + 0x48))))) {
              local_44 = *(float *)(iVar6 + 0x48) - _DAT_00925018;
              *(float *)(iVar6 + 0x48) = local_44;
              if ((float10)local_44 < extraout_ST0 != ((float10)local_44 == extraout_ST0)) {
                *(float *)(iVar6 + 0x48) = (float)extraout_ST0;
              }
              if (extraout_ST0 == (float10)*(float *)(iVar6 + 0x48)) {
                if (((*(uint *)(iVar6 + 0x74) & 0x40) != 0) && ((uVar18 & 0x80000000000) != 0)) {
                  FUN_005a15e0(*(undefined4 *)(iVar6 + 0x28),1);
                  *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xfffff7ff;
                }
                FUN_00467470(iVar6);
                *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xffffdfff;
              }
            }
          }
          if (0.0 < *(float *)(iVar6 + 0x50)) {
            local_44 = (float)FUN_0054fa60();
            local_30 = (float)(int)local_44 * 1.5259022e-05 * 0.05 - 0.025;
            if ((*(byte *)(iVar6 + 0xa0) & 0x20) == 0) {
              fVar17 = (float10)0;
            }
            else {
              fVar17 = (float10)FUN_005a1500(*(undefined4 *)(iVar6 + 0x28));
              fVar17 = fVar17 * (float10)*(float *)(*(int *)(iVar6 + 0x40) + 0x20);
            }
            local_2c = (float)fVar17;
            local_44 = (float)FUN_0054fa60();
            local_2c = ((float)(int)local_44 * 1.5259022e-05 * 0.05 - 0.025) + local_2c;
            local_44 = (float)FUN_0054fa60();
            local_28 = (float)(int)local_44 * 1.5259022e-05 * 0.05 - 0.025;
            FUN_005a1480(*(undefined4 *)(iVar6 + 0x28),&local_30);
            *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x1000;
            if (*(short *)(iVar6 + 0x82) == -1) {
              FUN_00681f40("LegShakeL",iVar6 + 0x1c);
            }
            else if ((bVar9) || (iVar12 = FUN_00650ef0((int)*(short *)(iVar6 + 0x82)), iVar12 != 0))
            {
              FUN_005478a0((int)*(short *)(iVar6 + 0x82),iVar6 + 0x1c,0,0);
            }
          }
          uVar3 = *(ushort *)(*(int *)(iVar6 + 0x28) + 10);
          if ((((uVar3 & 1) != 0) || (local_54 != 0)) || ((uVar3 & 4) != 0)) {
            local_4c = 1;
            if ((*(int *)(iVar6 + 0x40) != 0) &&
               (((*(byte *)(iVar6 + 0xa0) & 0x20) != 0 ||
                (FUN_00467530(), (*(byte *)(iVar6 + 0xa0) & 0x20) != 0)))) {
              puVar1 = (ushort *)(*(int *)(iVar6 + 0x40) + 0x24);
              *puVar1 = *puVar1 | 1;
              local_30 = 0.0;
              fVar17 = (float10)FUN_005a1500(*(undefined4 *)(iVar6 + 0x28));
              local_2c = (float)(fVar17 * (float10)*(float *)(*(int *)(iVar6 + 0x40) + 0x20));
              local_28 = 0.0;
              FUN_005a1480(*(undefined4 *)(iVar6 + 0x28),&local_30);
            }
            FUN_004671d0();
            if (local_54 == 0) {
              if ((((*(ushort *)(*(int *)(iVar6 + 0x28) + 10) & 5) != 0) &&
                  (*(float *)(iVar6 + 0x50) == 0.0)) && (local_50 != 0)) {
                if (*(short *)(iVar6 + 0x82) == -1) {
                  FUN_00681f40("LegoForm",iVar6 + 0x1c);
                }
                else if ((*(int *)(*(int *)(iVar6 + 0x28) + 0xc) == 0) ||
                        (iVar12 = FUN_00650ef0((int)*(short *)(iVar6 + 0x82)), iVar12 != 0)) {
                  FUN_005478a0((int)*(short *)(iVar6 + 0x82),iVar6 + 0x1c,0,0);
                }
              }
            }
            else {
              iVar12 = FUN_00467860(iVar6);
              if (iVar12 == 0) {
                if ((*(int *)(*(int *)(iVar6 + 0x28) + 0xc) != 4) &&
                   (*(short *)(iVar6 + 0x86) != -1)) {
                  FUN_005478a0((int)*(short *)(iVar6 + 0x86),iVar6 + 0x1c,0,0);
                }
              }
              else if (*(short *)(iVar6 + 0x84) != -1) {
                FUN_005478a0((int)*(short *)(iVar6 + 0x84),iVar6 + 0x1c,0,0);
              }
            }
            if ((*(uint *)(iVar6 + 0x74) & 0x2000) == 0) {
              for (puVar8 = *(undefined4 **)(*(int *)(iVar6 + 0x28) + 0x18);
                  puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
                if (((*(byte *)puVar8[9] & 2) == 0) &&
                   (sVar4 = *(short *)((byte *)puVar8[9] + 2), sVar4 != -1)) {
                  FUN_0058b3b0(puVar8 + 1,sVar4);
                }
              }
            }
          }
          iVar12 = *(int *)(iVar6 + 0x28);
          if (*(int *)(iVar12 + 0xc) == 2) {
            uVar7 = *(uint *)(iVar6 + 0xa0);
            if ((uVar7 & 0x20) == 0) {
              if ((*(float *)(iVar6 + 0x4c) <= 0.0) || ((uVar7 & 0x2000) != 0)) {
                uVar15 = *(uint *)(iVar6 + 0x74) & 0x40;
                if ((((uVar15 == 0) || ((uVar7 & 0x800) != 0)) &&
                    (((*(char *)(iVar12 + 9) != '\0' || (0.0 < *(float *)(iVar6 + 0x4c))) ||
                     (uVar15 != 0)))) && ((uVar7 & 0x4000) == 0)) {
                  if (*(short *)(iVar6 + 0x88) != -1) {
                    if ((*(uint *)(iVar6 + 0x74) & 0x20) == 0) {
                      FUN_0056a8c0(param_1,(int)*(short *)(iVar6 + 0x88),iVar6 + 0x1c);
                    }
                    else if (iVar12 != 0) {
                      for (puVar8 = *(undefined4 **)(iVar12 + 0x18); puVar8 != (undefined4 *)0x0;
                          puVar8 = (undefined4 *)*puVar8) {
                        iVar12 = FUN_005cf9e0(puVar8 + 1);
                        if (iVar12 != 0) {
                          FUN_0056a8c0(param_1,(int)*(short *)(iVar6 + 0x88),iVar12);
                        }
                      }
                    }
                    FUN_005a15e0(*(undefined4 *)(iVar6 + 0x28),0);
                    *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x10000;
                  }
                  if ((*(short *)(iVar6 + 0x8a) != 0) && ((*(uint *)(iVar6 + 0xa0) & 0x200) == 0)) {
                    uVar13 = FUN_0046c4f0();
                    FUN_005b37d0(local_c,iVar6 + 0x1c,iVar6 + 0x90);
                    FUN_005b35a0(local_18,&DAT_00802500,*(undefined2 *)(iVar6 + 0x8c));
                    FUN_005b3620(local_18,local_18,*(undefined2 *)(iVar6 + 0x8e));
                    FUN_0046d270(*(undefined2 *)(iVar6 + 0x8a),uVar13,0,0,local_c,local_18,
                                 0x40000000,0xffffffff,*(undefined4 *)(iVar6 + 0x9c),0x49f42400,0,1,
                                 0);
                    *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x200;
                  }
                  *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) | 0x4000;
                }
              }
            }
            else {
              iVar12 = FUN_00467890(iVar6);
              if ((iVar12 != 0) && (local_5c == 0)) {
                *(uint *)(iVar6 + 0xa0) = uVar7 | 0x40;
              }
            }
          }
          else if (((local_4c == 0) && (*(int *)(iVar12 + 0xc) == 0)) &&
                  ((*(byte *)(iVar6 + 0xa0) & 0x20) != 0)) {
            FUN_00467580();
            *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xffffffbf;
          }
          iVar12 = *(int *)(iVar6 + 0x40);
          if (iVar12 != 0) {
            if (*(int *)(*(int *)(iVar6 + 0x28) + 0xc) == 2) {
              if ((local_54 != 0) && (*(char *)(iVar12 + 0x27) == *(char *)(iVar12 + 0x26))) {
                *(ushort *)(iVar12 + 0x24) = *(ushort *)(iVar12 + 0x24) | 2;
                puVar1 = (ushort *)(*(int *)(iVar6 + 0x40) + 0x24);
                *puVar1 = *puVar1 | 4;
                piVar5 = *(int **)(iVar6 + 0x40);
                iVar12 = 0;
                piVar16 = piVar5;
                if (*(char *)((int)piVar5 + 0x27) != '\0') {
                  do {
                    if ((*(char *)(*piVar16 + 0x7d) != '\0') &&
                       (((int)*(char *)(*piVar16 + 0x7d) & 1 << ((byte)iVar12 & 0x1f)) == 0)) {
                      *(ushort *)(piVar5 + 9) = *(ushort *)(piVar5 + 9) & 0xfffb;
                      break;
                    }
                    iVar12 = iVar12 + 1;
                    piVar16 = piVar16 + 1;
                  } while (iVar12 < (int)(uint)*(byte *)(*(int *)(iVar6 + 0x40) + 0x27));
                }
              }
            }
            else {
              *(ushort *)(iVar12 + 0x24) = *(ushort *)(iVar12 + 0x24) & 0xfffd;
              puVar1 = (ushort *)(*(int *)(iVar6 + 0x40) + 0x24);
              *puVar1 = *puVar1 & 0xfffb;
            }
          }
          uVar7 = *(uint *)(iVar6 + 0xa0);
          if (((uVar7 & 0x8000) != 0) && (iVar12 = FUN_00467890(iVar6), iVar12 != 0)) {
            *(uint *)(iVar6 + 0xa0) = uVar7 & 0xffff7fff;
          }
          if (((*(byte *)(iVar6 + 0xa2) & 1) == 0) && ((*(uint *)(iVar6 + 0x74) & 0x300) != 0)) {
            *(int **)(*(int *)(param_2 + 8) + (uint)*(ushort *)(param_2 + 0x12) * 4) = local_58;
            *(short *)(param_2 + 0x12) = *(short *)(param_2 + 0x12) + 1;
          }
          uVar7 = *(uint *)(iVar6 + 0xa0);
          if (((char)uVar7 < '\0') && (iVar12 = FUN_00467890(iVar6), iVar12 == 0)) {
            if ((*(uint *)(iVar6 + 0x74) & 0x400) == 0) {
              if ((uVar7 & 0x20000) == 0) {
                local_60 = 0.0;
                FUN_005a0c20(*(undefined4 *)(iVar6 + 0x28),local_24,&local_60,2,1,1);
                local_60 = *(float *)(iVar6 + 0x70) * 1.2 * local_60;
                local_3c = 0;
                if (local_60 == 0.0) {
                  local_38 = 0.0;
                }
                else {
                  local_44 = (float)FUN_0054fa60();
                  local_38 = (float)(int)local_44 / (65535.0 / (local_60 * 0.5) + 1.0);
                }
                local_34 = 0;
                uVar13 = FUN_0054fa60();
                FUN_005b3690(&local_3c,&local_3c,uVar13);
                uVar11 = FUN_0054fa60();
                FUN_005b3620(&local_3c,&local_3c,uVar11);
                FUN_005b37d0(local_24,local_24,&local_3c);
                uVar13 = FUN_006e6b90(_DAT_00925018,0,0,0);
                if ((*(byte *)(iVar6 + 0x74) & 0x10) == 0) {
                  uVar14 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x884)
                  ;
                }
                else {
                  uVar14 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x898)
                  ;
                }
                FUN_00684be0(uVar14,local_24,uVar13);
              }
            }
            else {
              for (puVar8 = *(undefined4 **)(*(int *)(iVar6 + 0x28) + 0x18);
                  puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
                if ((*(byte *)(puVar8[9] + 4) & 1) == 0) {
                  puVar2 = puVar8 + 1;
                  iVar12 = FUN_005cfac0(puVar2);
                  if (iVar12 != 0) {
                    local_60 = 0.0;
                    FUN_005d0260(puVar2,local_24,&local_60);
                    local_60 = *(float *)(iVar6 + 0x70) * 1.2 * local_60;
                    uVar13 = FUN_005d0330(puVar2);
                    FUN_005c11d0(local_24,local_24,uVar13);
                    local_3c = 0;
                    if (local_60 == 0.0) {
                      local_38 = 0.0;
                    }
                    else {
                      local_44 = (float)FUN_0054fa60();
                      local_38 = (float)(int)local_44 / (65535.0 / (local_60 * 0.5) + 1.0);
                    }
                    local_34 = 0;
                    uVar13 = FUN_0054fa60();
                    FUN_005b3690(&local_3c,&local_3c,uVar13);
                    uVar11 = FUN_0054fa60();
                    FUN_005b3620(&local_3c,&local_3c,uVar11);
                    FUN_005b37d0(local_24,local_24,&local_3c);
                    if ((*(byte *)(iVar6 + 0x74) & 0x10) == 0) {
                      if ((*(uint *)(iVar6 + 0xa0) & 0x20000) == 0) {
                        uVar14 = FUN_006e6b90(_DAT_00925018,0,0,0);
                        uVar13 = *(undefined4 *)
                                  (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x884);
                        goto LAB_00469679;
                      }
                    }
                    else if ((*(uint *)(iVar6 + 0xa0) & 0x20000) == 0) {
                      uVar14 = FUN_006e6b90(_DAT_00925018,0,0,0);
                      uVar13 = *(undefined4 *)
                                (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x898);
LAB_00469679:
                      FUN_00684be0(uVar13,local_24,uVar14);
                    }
                  }
                }
              }
            }
          }
          *(uint *)(iVar6 + 0xa0) = *(uint *)(iVar6 + 0xa0) & 0xfffdffff;
          if ((*(uint *)(iVar6 + 0x74) & 0x400) != 0) {
            for (puVar8 = *(undefined4 **)(*(int *)(iVar6 + 0x28) + 0x18);
                puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
              *(uint *)(puVar8[9] + 4) = *(uint *)(puVar8[9] + 4) & 0xfffffffe;
            }
          }
        }
        local_58 = local_58 + 2;
        local_48 = local_48 + 1;
      } while (local_48 < *(int *)(local_40 + 4));
    }
  }
  return;
}

