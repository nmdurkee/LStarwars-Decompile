/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x437770; label: FUN_00437770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00437770(int param_1,int param_2,int param_3,int param_4,float param_5,int param_6,
                 ushort *param_7)

{
  short sVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  float *pfVar11;
  float **ppfVar12;
  float *pfVar13;
  undefined2 in_FPUControlWord;
  undefined1 auStack_4194 [4];
  float local_4190;
  float local_418c;
  float local_4188;
  undefined1 *local_4184;
  int local_4180;
  int local_417c;
  int local_4178;
  int iStack_4174;
  int iStack_4170;
  uint local_416c;
  ushort *local_4168;
  uint local_4164;
  int local_4160;
  int iStack_415c;
  float *local_4158 [5];
  undefined4 local_4144;
  undefined4 local_4140;
  undefined4 local_413c;
  int local_4134;
  int local_412c;
  code *local_411c;
  code *local_410c;
  code *local_4104;
  undefined4 local_40cc;
  undefined *local_40c4;
  undefined1 local_4094;
  float local_4090 [16];
  undefined1 local_4050 [16384];
  short local_50 [34];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_4194;
  local_4168 = param_7;
  if ((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000000) == 0) &&
      ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)) &&
     ((*(short *)(param_1 + 0x1064) != DAT_007f1908 ||
      (((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b26c || (DAT_0093b2a4 != 0)) ||
       (*(char *)(param_1 + 0x280) != -1)))))) {
    FUN_00547930(0x4f,param_1 + 0x80,0,0);
    if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x4000000) == 0) ||
       (*(short *)(param_1 + 0x1064) == DAT_007f1acc)) {
      local_417c = 0;
      iVar7 = FUN_0054fa60();
      local_4184 = (undefined1 *)
                   (int)ROUND((double)iVar7 * 1.5259021893143654e-05 * 25486.0 - 12743.0);
      local_416c = (uint)local_4184 & 0xffff;
      iVar7 = FUN_0054fa60();
      local_4180 = CONCAT22(local_4180._2_2_,in_FPUControlWord);
      local_4184 = (undefined1 *)
                   (int)ROUND((double)iVar7 * 1.5259021893143654e-05 * 16384.0 - 8192.0);
      local_4164 = (uint)local_4184 & 0xffff;
      iVar7 = 0;
      do {
        local_4160 = FUN_0054fa60();
        local_4160 = local_4160 / 0x5556;
        if (local_4160 != DAT_0087683c) break;
        bVar2 = iVar7 < 8;
        iVar7 = iVar7 + 1;
      } while (bVar2);
      iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
      DAT_0087683c = local_4160;
      if ((*(uint *)(iVar7 + 0x94) & 0x40000) == 0) {
        uVar8 = FUN_0041a5b0(*(undefined4 *)(iVar7 + 0xac),param_1);
      }
      else {
        uVar8 = *(uint *)(param_1 + 0x1048);
      }
      if (param_2 == -1) {
        if (param_3 != -1) {
          uVar8 = uVar8 & ~(1 << ((byte)param_3 & 0x1f));
        }
      }
      else {
        uVar8 = 1 << ((byte)param_2 & 0x1f);
      }
      FUN_0062e290(*(undefined4 *)(param_1 + 0x50),param_1 + 8,param_1 + 0xb8,local_4050,0,0,0,uVar8
                  );
      iVar7 = (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x54) + 0x24))
                        (*(undefined4 *)(param_1 + 0x50),local_50,uVar8);
      local_4180 = 0;
      iStack_4174 = iVar7;
      if (0 < iVar7) {
        do {
          sVar1 = local_50[local_4180];
          if (((sVar1 != -1) && ((param_2 == -1 || (sVar1 == param_2)))) &&
             ((param_3 == -1 || (sVar1 != param_3)))) {
            iVar5 = *(int *)(*(int *)(param_1 + 0x50) + 4);
            iVar4 = *(int *)(iVar5 + 0x194);
            iStack_4170 = iVar4 + sVar1 * 0x14;
            if ((*(int *)(iVar4 + 4 + sVar1 * 0x14) != 0) &&
               (local_4178 = 0, 0 < *(int *)(iVar5 + 0x168))) {
              puVar10 = local_4050;
              do {
                local_4184 = puVar10;
                if (*(int *)(*(int *)(iStack_4170 + 4) + local_4178 * 4) != 0) {
                  if (((DAT_00951288 == 0) ||
                      ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0)) ||
                     (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) <= 0.0)) {
                    local_4190 = 0.0;
                    local_418c = 1.0;
                    local_4188 = 0.0;
                    uVar6 = FUN_0054fa60();
                    FUN_005b3690(&local_4190,&local_4190,uVar6);
                    uVar6 = FUN_0054fa60();
                    FUN_005b35a0(&local_4190,&local_4190,uVar6);
                    local_418c = local_418c + param_5;
                    if (param_2 != -1) {
                      local_418c = local_418c + 1.0;
                    }
                    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
                      if (param_6 != 0) {
                        local_4190 = local_4190 + *(float *)(param_1 + 0xdf8) * 0.75;
                        local_418c = *(float *)(param_1 + 0xdfc) * 0.75 + local_418c;
                        fVar3 = *(float *)(param_1 + 0xe00) * 0.75;
                        goto LAB_00437df3;
                      }
                      if (local_4168 != (ushort *)0x0) {
                        local_4190 = local_4190 + (float)(&DAT_029899a0)[*local_4168 >> 1] * 2.0;
                        fVar3 = (float)(&DAT_029899a0)[(int)(*local_4168 + 0x4000) >> 1 & 0x7fff] *
                                2.0;
                        goto LAB_00437df3;
                      }
                    }
                    else {
                      local_4190 = local_4190 + *(float *)(param_1 + 0x68) * 0.75;
                      local_418c = *(float *)(param_1 + 0x6c) * 0.75 + local_418c;
                      fVar3 = *(float *)(param_1 + 0x70) * 0.75;
LAB_00437df3:
                      local_4188 = fVar3 + local_4188;
                    }
                    FUN_005b5430(local_4090,puVar10,param_1 + 0xb8);
                    puVar9 = &DAT_00810210;
                    ppfVar12 = local_4158;
                    for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *ppfVar12 = (float *)*puVar9;
                      puVar9 = puVar9 + 1;
                      ppfVar12 = ppfVar12 + 1;
                    }
                    local_4144 = 0x3dcccccd;
                    local_4140 = 0x3dcccccd;
                    local_413c = 0xc0a00000;
                  }
                  else {
                    FUN_005b5430(local_4090,puVar10,param_1 + 0xb8);
                    FUN_004329c0(&local_4190);
                    FUN_005b3830(&local_4190,&local_4190,0x40800000);
                    puVar9 = &DAT_00810210;
                    ppfVar12 = local_4158;
                    for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *ppfVar12 = (float *)*puVar9;
                      puVar9 = puVar9 + 1;
                      ppfVar12 = ppfVar12 + 1;
                    }
                    local_4190 = local_4190 + *(float *)(param_1 + 0x68) * 0.75;
                    local_418c = *(float *)(param_1 + 0x6c) * 0.75 + local_418c + 6.0;
                    local_4188 = *(float *)(param_1 + 0x70) * 0.75 + local_4188;
                    local_4144 = 0x3ecccccd;
                    local_4140 = 0x3ecccccd;
                    local_413c = 0xc1200000;
                  }
                  local_4158[2] = &local_4190;
                  local_4158[0] = local_4090;
                  local_4134 = *(int *)(*(int *)(iStack_4170 + 4) + local_4178 * 4);
                  iVar7 = FUN_0056e0f0(1);
                  if (iVar7 == 0) {
                    local_40c4 = (undefined *)(param_1 + 0x4d8);
                  }
                  else {
                    local_40c4 = &DAT_00955890;
                  }
                  sVar1 = *(short *)(param_1 + 0x1064);
                  if (sVar1 == DAT_007f1970) {
                    FUN_00432f50(local_4158,local_417c,param_4,param_1,local_4160,local_416c,
                                 local_4164,&local_4190);
                  }
                  else if (sVar1 == DAT_007f1914) {
                    FUN_00433a40(local_4158,local_417c,param_4,param_1);
                  }
                  else if (sVar1 == DAT_007f1948) {
                    FUN_00437510(local_4158,local_417c,param_4,param_1);
                  }
                  else {
                    local_40cc = _DAT_00925018;
                    local_412c = (-(uint)(param_4 != 0) & 0xfffffc10) + 0x480;
                    local_4094 = 1;
                    local_410c = FUN_00571c50;
                    local_4104 = FUN_00571c80;
                    local_411c = FUN_00571ba0;
                    iVar7 = FUN_0064d270(local_4158);
                    if (iVar7 != 0) {
                      iStack_415c = FUN_0054fa60();
                      *(float *)(iVar7 + 0x100) =
                           (float)iStack_415c * 1.5259022e-05 + (float)iStack_415c * 1.5259022e-05 +
                           7.0;
                    }
                  }
                }
                local_417c = local_417c + 1;
                local_4178 = local_4178 + 1;
                puVar10 = local_4184 + 0x40;
                iVar7 = iStack_4174;
                local_4184 = puVar10;
              } while (local_4178 < *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 4) + 0x168));
            }
          }
          local_4180 = local_4180 + 1;
        } while (local_4180 < iVar7);
      }
      iVar7 = *(int *)(param_1 + 0x54);
      if ((((*(byte *)(iVar7 + 0x40) & 1) != 0) && (DAT_00951288 != 0)) &&
         (((*(uint *)(iVar7 + 4) & 0x2000) != 0 &&
          ((0.0 < *(float *)(*(int *)(iVar7 + 0x24) + 0x28) &&
           (iStack_4174 = FUN_0055b520(PTR_DAT_00802c54,(int)*(short *)(param_1 + 0x1064)),
           iStack_4174 != 0)))))) {
        pfVar11 = (float *)(param_1 + 0xb8);
        pfVar13 = local_4090;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar13 = *pfVar11;
          pfVar11 = pfVar11 + 1;
          pfVar13 = pfVar13 + 1;
        }
        FUN_004329c0(&local_4190);
        FUN_005b3830(&local_4190,&local_4190,0x40800000);
        puVar9 = &DAT_00810210;
        ppfVar12 = local_4158;
        for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
          *ppfVar12 = (float *)*puVar9;
          puVar9 = puVar9 + 1;
          ppfVar12 = ppfVar12 + 1;
        }
        local_4190 = local_4190 + *(float *)(param_1 + 0x68) * 0.75;
        local_4158[0] = local_4090;
        local_4158[2] = &local_4190;
        local_418c = *(float *)(param_1 + 0x6c) * 0.75 + local_418c + 6.0;
        local_4134 = iStack_4174;
        local_4188 = *(float *)(param_1 + 0x70) * 0.75 + local_4188;
        local_4144 = 0x3f4ccccd;
        local_4140 = 0x3ecccccd;
        local_413c = 0xc1200000;
        iVar7 = FUN_0056e0f0(1);
        if (iVar7 == 0) {
          local_40c4 = (undefined *)(param_1 + 0x4d8);
        }
        else {
          local_40c4 = &DAT_00955890;
        }
        local_40cc = _DAT_00925018;
        local_412c = (-(uint)(param_4 != 0) & 0xfffffc10) + 0x480;
        local_4094 = 1;
        local_410c = FUN_00571c50;
        local_4104 = FUN_00571c80;
        local_411c = FUN_00571ba0;
        iVar7 = FUN_0064d270(local_4158);
        if (iVar7 != 0) {
          iStack_4174 = FUN_0054fa60();
          *(float *)(iVar7 + 0x100) =
               (float)iStack_4174 * 1.5259022e-05 + (float)iStack_4174 * 1.5259022e-05 + 3.0;
        }
      }
      if (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\0') {
        FUN_00592ed0(DAT_00856980,param_1,param_2,param_4,param_5);
      }
    }
    else {
      iVar7 = *(int *)(DAT_00956048 + *(short *)(param_1 + 0x1064) * 4);
      local_417c = iVar7;
      if ((iVar7 != 0) && (local_4180 = 0, *(char *)(iVar7 + 8) != '\0')) {
        local_4178 = 0;
        do {
          iVar5 = local_4178;
          iVar4 = FUN_005cfac0(*(int *)(iVar7 + 4) + local_4178);
          if (iVar4 != 0) {
            pfVar11 = (float *)(*(int *)(iVar7 + 4) + 0xc + iVar5);
            pfVar13 = local_4090;
            for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pfVar13 = *pfVar11;
              pfVar11 = pfVar11 + 1;
              pfVar13 = pfVar13 + 1;
            }
            FUN_005b5430(local_4090,local_4090,param_1 + 0xb8);
            FUN_004329c0(&local_4190);
            FUN_005b3830(&local_4190,&local_4190,0x40400000);
            puVar9 = &DAT_00810210;
            ppfVar12 = local_4158;
            for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
              *ppfVar12 = (float *)*puVar9;
              puVar9 = puVar9 + 1;
              ppfVar12 = ppfVar12 + 1;
            }
            local_4190 = local_4190 + *(float *)(param_1 + 0x68) * 0.75;
            local_4158[0] = local_4090;
            local_4158[2] = &local_4190;
            local_418c = *(float *)(param_1 + 0x6c) * 0.75 + local_418c + 5.0;
            local_4188 = *(float *)(param_1 + 0x70) * 0.75 + local_4188;
            local_4144 = 0x3e4ccccd;
            local_4140 = 0x3e4ccccd;
            local_413c = 0xc1200000;
            local_4134 = *(int *)(local_417c + 4) + local_4178;
            iVar7 = FUN_0056e0f0(1);
            if (iVar7 == 0) {
              local_40c4 = (undefined *)(param_1 + 0x4d8);
            }
            else {
              local_40c4 = &DAT_00955890;
            }
            local_40cc = _DAT_00925018;
            local_412c = (-(uint)(param_4 != 0) & 0xfffffc10) + 0x480;
            local_4094 = 1;
            local_410c = FUN_00571c50;
            local_4104 = FUN_00571c80;
            local_411c = FUN_00571ba0;
            iVar5 = FUN_0064d270(local_4158);
            iVar7 = local_417c;
            if (iVar5 != 0) {
              local_4184 = (undefined1 *)FUN_0054fa60();
              *(float *)(iVar5 + 0x100) =
                   (float)(int)local_4184 * 1.5259022e-05 + (float)(int)local_4184 * 1.5259022e-05 +
                   7.0;
              iVar7 = local_417c;
            }
          }
          local_4180 = local_4180 + 1;
          local_4178 = local_4178 + 0x68;
        } while (local_4180 < (int)(uint)*(byte *)(iVar7 + 8));
        __security_check_cookie(local_c ^ (uint)auStack_4194);
        return;
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_4194);
  return;
}

