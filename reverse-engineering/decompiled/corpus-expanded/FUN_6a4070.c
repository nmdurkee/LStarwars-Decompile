/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a4070; label: FUN_006a4070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_006a4070(float param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  double dVar3;
  void *pvVar4;
  float *pfVar5;
  float *pfVar6;
  float *in_ECX;
  int iVar7;
  float *extraout_ECX;
  uint uVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  float *pfVar16;
  int iVar17;
  float10 fVar18;
  size_t asStack_7f58 [4];
  float fStack_7f48;
  float local_7f38 [55];
  float afStack_7e5c [7561];
  float local_838 [448];
  float local_138 [56];
  undefined8 local_58;
  double local_50;
  double local_48;
  undefined8 local_40;
  void *local_38;
  double local_34;
  float *local_2c;
  int local_28;
  float *local_24;
  float *local_20;
  float *local_1c;
  float *local_18;
  undefined4 *local_14;
  float *local_10;
  float local_c;
  float local_8;
  undefined4 *puVar11;
  
  local_8 = 9.757697e-39;
  fStack_7f48 = 9.75772e-39;
  local_14 = local_7f38 + (-3 - (int)param_2);
  (&fStack_7f48)[-(int)param_2] = 9.52883e-44;
  asStack_7f58[3 - (int)param_2] = 0x6a4098;
  local_38 = _malloc((size_t)(&fStack_7f48)[-(int)param_2]);
  asStack_7f58[3 - (int)param_2] = 0x7700;
  asStack_7f58[2 - (int)param_2] = 0;
  asStack_7f58[1 - (int)param_2] = (size_t)local_7f38;
  asStack_7f58[-(int)param_2] = 0x6a40ae;
  _memset((void *)asStack_7f58[1 - (int)param_2],asStack_7f58[2 - (int)param_2],
          asStack_7f58[3 - (int)param_2]);
  local_34 = (double)param_4;
  pfVar10 = local_7f38 + (-3 - (int)param_2);
  local_48 = (double)param_3;
  local_10 = local_7f38;
  local_18 = (float *)(2 - (int)in_ECX);
  local_24 = (float *)&DAT_008111c0;
  local_2c = (float *)&DAT_00811064;
  fVar1 = param_3;
  local_1c = in_ECX;
  while( true ) {
    iVar7 = (int)local_18 + (int)local_1c;
    pfVar16 = local_138;
    iVar17 = 0x38;
    pfVar5 = local_2c;
    do {
      local_8 = 999.0;
      if (iVar7 + -2 < 0x58) {
        if (pfVar5[-1] < 999.0) {
          local_8 = pfVar5[-1];
        }
      }
      else if (_DAT_008111bc < 999.0) {
        local_8 = _DAT_008111bc;
      }
      if (iVar7 + -1 < 0x58) {
        if (*pfVar5 < local_8) {
          local_8 = *pfVar5;
        }
      }
      else if (_DAT_008111bc < local_8) {
        local_8 = _DAT_008111bc;
      }
      if (iVar7 < 0x58) {
        if (pfVar5[1] < local_8) {
          local_8 = pfVar5[1];
        }
      }
      else if (_DAT_008111bc < local_8) {
        local_8 = _DAT_008111bc;
      }
      iVar7 = iVar7 + 1;
      if (iVar7 < 0x58) {
        if (pfVar5[2] < local_8) {
          local_8 = pfVar5[2];
        }
      }
      else if (_DAT_008111bc < local_8) {
        local_8 = _DAT_008111bc;
      }
      pfVar5 = pfVar5 + 1;
      *pfVar16 = local_8;
      pfVar16 = pfVar16 + 1;
      iVar17 = iVar17 + -1;
    } while (iVar17 != 0);
    pfVar16 = local_24;
    pfVar5 = local_10 + 0x70;
    for (iVar7 = 0x150; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar5 = *pfVar16;
      pfVar16 = pfVar16 + 1;
      pfVar5 = pfVar5 + 1;
    }
    pfVar16 = local_24;
    pfVar5 = local_10;
    for (iVar7 = 0x38; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar5 = *pfVar16;
      pfVar16 = pfVar16 + 1;
      pfVar5 = pfVar5 + 1;
    }
    local_20 = local_10 + 0x38;
    pfVar16 = local_24;
    pfVar5 = local_20;
    for (iVar7 = 0x38; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar5 = *pfVar16;
      pfVar16 = pfVar16 + 1;
      pfVar5 = pfVar5 + 1;
    }
    iVar7 = 8;
    uVar15 = 0xf;
    pfVar16 = local_10 + 1;
    while( true ) {
      do {
        uVar8 = (int)(uVar15 + 1) >> 0x1f;
        local_8 = (float)(int)((uVar15 + 1 ^ uVar8) - uVar8) * param_4 + fVar1;
        if ((0.0 <= local_8) || (param_3 <= 0.0)) {
          if ((0.0 < local_8) && (param_3 < 0.0)) {
            local_8 = 0.0;
          }
        }
        else {
          local_8 = 0.0;
        }
        pfVar16[-1] = local_8 + pfVar16[-1];
        local_8 = (float)(int)((uVar15 ^ (int)uVar15 >> 0x1f) - ((int)uVar15 >> 0x1f)) * param_4 +
                  fVar1;
        if (((local_8 < 0.0) && (0.0 < param_3)) || ((0.0 < local_8 && (param_3 < 0.0)))) {
          local_8 = 0.0;
        }
        uVar8 = (int)(uVar15 - 1) >> 0x1f;
        *pfVar16 = local_8 + *pfVar16;
        local_8 = (float)(int)((uVar15 - 1 ^ uVar8) - uVar8) * param_4 + fVar1;
        if (((local_8 < 0.0) && (0.0 < param_3)) || ((0.0 < local_8 && (param_3 < 0.0)))) {
          local_8 = 0.0;
        }
        uVar8 = (int)(uVar15 - 2) >> 0x1f;
        pfVar16[1] = pfVar16[1] + local_8;
        local_8 = (float)(int)((uVar15 - 2 ^ uVar8) - uVar8) * param_4 + fVar1;
        if (((local_8 < 0.0) && (0.0 < param_3)) || ((0.0 < local_8 && (param_3 < 0.0)))) {
          local_8 = 0.0;
        }
        uVar15 = uVar15 - 4;
        pfVar5 = pfVar16 + 4;
        pfVar16[2] = pfVar16[2] + local_8;
        pfVar16 = pfVar5;
      } while (-0x29 < (int)uVar15);
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) break;
      uVar15 = 0xf;
    }
    local_8 = 0.0;
    pfVar16 = local_838;
    local_58 = (double)(*local_1c + 100.0);
    pfVar5 = local_1c;
    do {
      local_c = 2.8026e-45;
      if (1 < (int)local_8) {
        local_c = local_8;
      }
      (&fStack_7f48)[-(int)param_2] = (float)pfVar5;
      local_c = ((float)local_58 - (float)(int)local_c * 10.0) - 30.0;
      (&fStack_7f48)[-(int)param_2] = local_c;
      asStack_7f58[3 - (int)param_2] = 0x6a4423;
      FUN_006a4010();
      fVar1 = (float)(int)local_8;
      pfVar5 = local_138;
      pfVar6 = pfVar16;
      for (iVar7 = 0x38; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar6 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar6 = pfVar6 + 1;
      }
      local_c = (100.0 - fVar1 * 10.0) - 30.0;
      (&fStack_7f48)[-(int)param_2] = local_c;
      asStack_7f58[3 - (int)param_2] = 0x6a4457;
      FUN_006a4010();
      (&fStack_7f48)[-(int)param_2] = 9.759095e-39;
      FUN_006a3f90();
      local_10 = local_10 + 0x38;
      local_8 = (float)((int)local_8 + 1);
      pfVar16 = pfVar16 + 0x38;
      pfVar5 = extraout_ECX;
    } while ((int)local_8 < 8);
    iVar7 = 7;
    do {
      (&fStack_7f48)[-(int)param_2] = 9.759176e-39;
      FUN_006a3f10();
      (&fStack_7f48)[-(int)param_2] = 9.759189e-39;
      FUN_006a3f10();
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    local_24 = local_24 + 0x150;
    local_1c = local_1c + 1;
    local_2c = local_2c + 4;
    if (0x811173 < (int)local_2c) break;
    fVar1 = (float)local_48;
    param_4 = (float)local_34;
  }
  local_34 = (double)param_1;
  local_18 = (float *)0x0;
  do {
    pfVar16 = local_18;
    *(undefined4 *)((int)pfVar10 + -4) = 0x20;
    *(undefined4 *)((int)pfVar10 + -8) = 0x6a44ee;
    pvVar4 = _malloc(*(size_t *)((int)pfVar10 + -4));
    local_48 = (double)(int)local_18 * 0.5;
    local_58 = (double)CONCAT44(pvVar4,(undefined4)local_58);
    *(void **)((int)local_38 + (int)pfVar16 * 4) = pvVar4;
    puVar11 = (undefined4 *)((int)pfVar10 + -4);
    pfVar10 = (float *)((int)pfVar10 + -4);
    *puVar11 = 0x6a4517;
    fVar18 = (float10)FUN_006e8fac();
    *(double *)((int)pfVar10 + -8) = (double)(fVar18 / (float10)local_34);
    *(undefined4 *)((int)pfVar10 + -0xc) = 0x6a4525;
    FUN_006eafc0();
    *(undefined4 *)((int)pfVar10 + -4) = 0x6a452d;
    iVar7 = FUN_006e6b90();
    *(undefined4 *)((int)pfVar10 + -4) = 0x6a4543;
    local_18 = (float *)iVar7;
    fVar18 = (float10)FUN_006e9040();
    fVar18 = fVar18 * (float10)1.4426950216293335 - (float10)5.965784072875977;
    *(double *)((int)pfVar10 + -8) = (double)(fVar18 + fVar18);
    *(undefined4 *)((int)pfVar10 + -0xc) = 0x6a455c;
    FUN_006e6c40();
    *(undefined4 *)((int)pfVar10 + -4) = 0x6a4564;
    pfVar5 = (float *)FUN_006e6b90();
    local_18 = (float *)(iVar7 + 1);
    *(undefined4 *)((int)pfVar10 + -4) = 0x6a457a;
    local_2c = pfVar5;
    fVar18 = (float10)FUN_006e9040();
    fVar18 = fVar18 * (float10)1.4426950216293335 - (float10)5.965784072875977;
    *(double *)((int)pfVar10 + -8) = (double)(fVar18 + fVar18);
    *(undefined4 *)((int)pfVar10 + -0xc) = 0x6a4593;
    FUN_006eafc0();
    *(undefined4 *)((int)pfVar10 + -4) = 0x6a459b;
    local_c = (float)FUN_006e6b90();
    if ((int)pfVar16 < (int)pfVar5) {
      local_2c = pfVar16;
      pfVar5 = pfVar16;
    }
    if ((int)pfVar5 < 0) {
      local_2c = (float *)0x0;
    }
    if (0x10 < (int)local_c) {
      local_c = 2.24208e-44;
    }
    local_28 = 0;
    local_10 = (float *)((int)pfVar16 + 1);
    do {
      *(undefined4 *)((int)pfVar10 + -4) = 0xe8;
      *(undefined4 *)((int)pfVar10 + -8) = 0x6a45cf;
      local_18 = _malloc(*(size_t *)((int)pfVar10 + -4));
      *(float **)(local_58._4_4_ + local_28 * 4) = local_18;
      pfVar16 = param_2;
      puVar9 = local_14;
      if (0 < (int)param_2) {
        for (; pfVar16 != (float *)0x0; pfVar16 = (float *)((int)pfVar16 + -1)) {
          *puVar9 = 0x4479c000;
          puVar9 = puVar9 + 1;
        }
      }
      local_20 = local_2c;
      if ((int)local_2c <= (int)local_c) {
        iVar7 = local_28 + (int)local_2c * 8;
        local_24 = (float *)(iVar7 * 0x38);
        local_1c = afStack_7e5c + iVar7 * 0x38;
        do {
          pfVar16 = (float *)0x0;
          local_8 = 0.0;
          local_50 = (double)(int)local_20 * 0.5;
          do {
            local_40 = (double)(int)local_8 * 0.125 + local_50;
            puVar12 = (undefined1 *)((int)pfVar10 + -4);
            *(undefined4 *)((int)pfVar10 + -4) = 0x6a4667;
            FUN_006e8fac();
            *(undefined4 *)(puVar12 + -4) = 0x6a466f;
            pfVar6 = (float *)FUN_006e6b90();
            pfVar10 = (float *)(puVar12 + -4);
            *(undefined4 *)(puVar12 + -4) = 0x6a468b;
            FUN_006e8fac();
            *(undefined4 *)((int)pfVar10 + -4) = 0x6a4699;
            pfVar5 = (float *)FUN_006e6b90();
            dVar3 = local_40;
            local_40 = (double)CONCAT44(pfVar5,(undefined4)local_40);
            if ((int)pfVar6 < 0) {
              pfVar6 = (float *)0x0;
            }
            if ((int)param_2 < (int)pfVar6) {
              pfVar6 = param_2;
            }
            if ((int)pfVar6 < (int)pfVar16) {
              pfVar16 = pfVar6;
            }
            if ((int)pfVar5 < 0) {
              pfVar5 = (float *)0x0;
              local_40 = (double)((ulonglong)dVar3 & 0xffffffff);
            }
            if ((int)param_2 < (int)pfVar5) {
              local_40 = (double)CONCAT44(param_2,(undefined4)local_40);
              pfVar5 = param_2;
            }
            if (3 < (int)pfVar5 - (int)pfVar16) {
              iVar7 = (int)pfVar16 + 2;
              pfVar6 = (float *)(local_14 + iVar7);
              do {
                if ((int)param_2 <= (int)pfVar16) goto LAB_006a47bb;
                fVar1 = local_7f38[(int)local_8 + (int)local_24];
                pfVar5 = local_7f38 + (int)local_8 + (int)local_24;
                if (fVar1 < pfVar6[-2]) {
                  pfVar6[-2] = *pfVar5;
                }
                if ((int)param_2 <= iVar7 + -1) {
                  pfVar16 = (float *)((int)pfVar16 + 1);
                  goto LAB_006a47bb;
                }
                if (fVar1 < pfVar6[-1]) {
                  pfVar6[-1] = *pfVar5;
                }
                if ((int)param_2 <= iVar7) {
                  pfVar16 = (float *)((int)pfVar16 + 2);
                  goto LAB_006a47bb;
                }
                if (fVar1 < *pfVar6) {
                  *pfVar6 = *pfVar5;
                }
                if ((int)param_2 <= iVar7 + 1) {
                  pfVar16 = (float *)((int)pfVar16 + 3);
                  goto LAB_006a47bb;
                }
                if (fVar1 < pfVar6[1]) {
                  pfVar6[1] = *pfVar5;
                }
                pfVar16 = pfVar16 + 1;
                pfVar6 = pfVar6 + 4;
                iVar7 = iVar7 + 4;
                pfVar5 = local_40._4_4_;
              } while ((int)pfVar16 < (int)local_40._4_4_ + -3);
            }
            for (; ((int)pfVar16 < (int)pfVar5 && ((int)pfVar16 < (int)param_2));
                pfVar16 = (float *)((int)pfVar16 + 1)) {
              if (local_7f38[(int)local_24 + (int)local_8] < (float)local_14[(int)pfVar16]) {
                local_14[(int)pfVar16] = local_7f38[(int)local_24 + (int)local_8];
              }
            }
LAB_006a47bb:
            local_8 = (float)((int)local_8 + 1);
          } while ((int)local_8 < 0x38);
          if (3 < (int)param_2 - (int)pfVar16) {
            fVar1 = *local_1c;
            iVar7 = ((uint)((int)param_2 + (-4 - (int)pfVar16)) >> 2) + 1;
            pfVar5 = (float *)(local_14 + (int)pfVar16 + 2);
            pfVar16 = pfVar16 + iVar7;
            do {
              if (fVar1 < pfVar5[-2]) {
                pfVar5[-2] = *local_1c;
              }
              if (fVar1 < pfVar5[-1]) {
                pfVar5[-1] = *local_1c;
              }
              if (fVar1 < *pfVar5) {
                *pfVar5 = *local_1c;
              }
              if (fVar1 < pfVar5[1]) {
                pfVar5[1] = *local_1c;
              }
              pfVar5 = pfVar5 + 4;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if ((int)pfVar16 < (int)param_2) {
            fVar1 = *local_1c;
            do {
              if (fVar1 < (float)local_14[(int)pfVar16]) {
                local_14[(int)pfVar16] = *local_1c;
              }
              pfVar16 = (float *)((int)pfVar16 + 1);
            } while ((int)pfVar16 < (int)param_2);
          }
          local_24 = local_24 + 0x70;
          local_20 = (float *)((int)local_20 + 1);
          local_1c = local_1c + 0x1c0;
        } while ((int)local_20 <= (int)local_c);
      }
      puVar9 = local_14;
      if ((int)local_10 < 0x11) {
        pfVar16 = (float *)0x0;
        local_8 = 0.0;
        do {
          local_50 = (double)(int)local_8 * 0.125 + local_48;
          puVar13 = (undefined1 *)((int)pfVar10 + -4);
          *(undefined4 *)((int)pfVar10 + -4) = 0x6a48c6;
          FUN_006e8fac();
          *(undefined4 *)(puVar13 + -4) = 0x6a48ce;
          pfVar5 = (float *)FUN_006e6b90();
          pfVar10 = (float *)(puVar13 + -4);
          *(undefined4 *)(puVar13 + -4) = 0x6a48ea;
          FUN_006e8fac();
          *(undefined4 *)((int)pfVar10 + -4) = 0x6a48f8;
          local_20 = (float *)FUN_006e6b90();
          if ((int)pfVar5 < 0) {
            pfVar5 = (float *)0x0;
          }
          if ((int)param_2 < (int)pfVar5) {
            pfVar5 = param_2;
          }
          if ((int)pfVar5 < (int)pfVar16) {
            pfVar16 = pfVar5;
          }
          if ((int)local_20 < 0) {
            local_20 = (float *)0x0;
          }
          if ((int)param_2 < (int)local_20) {
            local_20 = param_2;
          }
          if (3 < (int)local_20 - (int)pfVar16) {
            iVar7 = (int)pfVar16 + 2;
            pfVar5 = (float *)(puVar9 + iVar7);
            do {
              if ((int)param_2 <= (int)pfVar16) goto LAB_006a4a44;
              iVar17 = (int)local_8 + (local_28 + (int)local_10 * 8) * 0x38;
              fVar1 = local_7f38[iVar17];
              pfVar6 = local_7f38 + iVar17;
              if (fVar1 < pfVar5[-2]) {
                pfVar5[-2] = *pfVar6;
              }
              puVar9 = local_14;
              if ((int)param_2 <= iVar7 + -1) {
                pfVar16 = (float *)((int)pfVar16 + 1);
                goto LAB_006a4a44;
              }
              if (fVar1 < pfVar5[-1]) {
                pfVar5[-1] = *pfVar6;
              }
              if ((int)param_2 <= iVar7) {
                pfVar16 = (float *)((int)pfVar16 + 2);
                goto LAB_006a4a44;
              }
              if (fVar1 < *pfVar5) {
                *pfVar5 = *pfVar6;
              }
              if ((int)param_2 <= iVar7 + 1) {
                pfVar16 = (float *)((int)pfVar16 + 3);
                goto LAB_006a4a44;
              }
              if (fVar1 < pfVar5[1]) {
                pfVar5[1] = *pfVar6;
              }
              pfVar16 = pfVar16 + 1;
              pfVar5 = pfVar5 + 4;
              iVar7 = iVar7 + 4;
            } while ((int)pfVar16 < (int)local_20 + -3);
          }
          for (; ((int)pfVar16 < (int)local_20 && ((int)pfVar16 < (int)param_2));
              pfVar16 = (float *)((int)pfVar16 + 1)) {
            iVar7 = (int)local_8 + (local_28 + (int)local_10 * 8) * 0x38;
            if (local_7f38[iVar7] < (float)puVar9[(int)pfVar16]) {
              puVar9[(int)pfVar16] = local_7f38[iVar7];
            }
          }
LAB_006a4a44:
          local_8 = (float)((int)local_8 + 1);
        } while ((int)local_8 < 0x38);
        if (3 < (int)param_2 - (int)pfVar16) {
          iVar7 = local_28 + (int)local_10 * 8;
          fVar1 = afStack_7e5c[iVar7 * 0x38];
          pfVar6 = afStack_7e5c + iVar7 * 0x38;
          iVar7 = ((uint)((int)param_2 + (-4 - (int)pfVar16)) >> 2) + 1;
          pfVar5 = (float *)(puVar9 + (int)pfVar16 + 2);
          pfVar16 = pfVar16 + iVar7;
          do {
            if (fVar1 < pfVar5[-2]) {
              pfVar5[-2] = *pfVar6;
            }
            if (fVar1 < pfVar5[-1]) {
              pfVar5[-1] = *pfVar6;
            }
            if (fVar1 < *pfVar5) {
              *pfVar5 = *pfVar6;
            }
            if (fVar1 < pfVar5[1]) {
              pfVar5[1] = *pfVar6;
            }
            pfVar5 = pfVar5 + 4;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        if ((int)pfVar16 < (int)param_2) {
          iVar7 = local_28 + (int)local_10 * 8;
          fVar1 = afStack_7e5c[iVar7 * 0x38];
          do {
            if (fVar1 < (float)puVar9[(int)pfVar16]) {
              puVar9[(int)pfVar16] = afStack_7e5c[iVar7 * 0x38];
            }
            pfVar16 = (float *)((int)pfVar16 + 1);
          } while ((int)pfVar16 < (int)param_2);
        }
      }
      local_8 = 0.0;
      pfVar16 = local_18 + 2;
      do {
        fVar1 = local_8;
        puVar14 = (undefined4 *)((int)pfVar10 + -4);
        pfVar10 = (float *)((int)pfVar10 + -4);
        *puVar14 = 0x6a4b63;
        FUN_006e8fac();
        *(undefined4 *)((int)pfVar10 + -4) = 0x6a4b6b;
        iVar7 = FUN_006e6b90();
        if (iVar7 < 0) {
          fVar2 = -999.0;
        }
        else if (iVar7 < (int)param_2) {
          fVar2 = (float)puVar9[iVar7];
        }
        else {
          fVar2 = -999.0;
        }
        local_8 = (float)((int)fVar1 + 1);
        *pfVar16 = fVar2;
        pfVar16 = pfVar16 + 1;
      } while ((int)local_8 < 0x38);
      iVar7 = 0;
      pfVar16 = local_18 + 3;
      do {
        if (-200.0 < pfVar16[-1]) break;
        if (-200.0 < *pfVar16) {
          iVar7 = iVar7 + 1;
          break;
        }
        if (-200.0 < pfVar16[1]) {
          iVar7 = iVar7 + 2;
          break;
        }
        if (-200.0 < pfVar16[2]) {
          iVar7 = iVar7 + 3;
          break;
        }
        iVar7 = iVar7 + 4;
        pfVar16 = pfVar16 + 4;
      } while (iVar7 < 0x10);
      local_8 = 7.70714e-44;
      pfVar16 = local_18 + 0x38;
      *local_18 = (float)iVar7;
      do {
        if (-200.0 < pfVar16[1]) break;
        if (-200.0 < *pfVar16) {
          local_8 = (float)((int)local_8 + -1);
          break;
        }
        local_8 = (float)((int)local_8 + -2);
        pfVar16 = pfVar16 + -2;
      } while (0x11 < (int)local_8);
      local_28 = local_28 + 1;
      local_18[1] = (float)(int)local_8;
    } while (local_28 < 8);
    local_18 = local_10;
    if (0x10 < (int)local_10) {
      return local_38;
    }
  } while( true );
}

