/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x4104f0; label: FUN_004104f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004104f0(undefined4 *param_1,float *param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  float *in_EAX;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  float10 fVar10;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  sVar1 = *(short *)(in_EAX + 0x40);
  if (sVar1 != -1) {
    if (sVar1 == -2) {
      fVar10 = (float10)FUN_005b9dd0();
      if ((((fVar10 < (float10)0.5) && (DAT_0093d7f0 != 0)) &&
          (iVar8 = DAT_0093d7f0, (*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) ||
         ((DAT_0093d7f4 != 0 &&
          (iVar8 = DAT_0093d7f4, (*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)))) {
        DAT_00855e10 = *(undefined4 *)(iVar8 + 0x80);
        DAT_00855e14 = *(undefined4 *)(iVar8 + 0x84);
        DAT_00855e18 = *(undefined4 *)(iVar8 + 0x88);
        DAT_00855e50 = *(undefined4 *)(iVar8 + 0x68);
        DAT_00855e54 = *(undefined4 *)(iVar8 + 0x6c);
        DAT_00855e58 = *(undefined4 *)(iVar8 + 0x70);
      }
      pfVar3 = (float *)&DAT_00855e10;
      pfVar9 = (float *)&DAT_00855e50;
    }
    else {
      if (sVar1 == -3) {
LAB_004106c4:
        for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *param_2 = *in_EAX;
          in_EAX = in_EAX + 1;
          param_2 = param_2 + 1;
        }
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = param_3;
        param_1[3] = 0;
        FUN_0040e8e0(param_1);
        return 0;
      }
      fVar4 = in_EAX[0x41];
      if (fVar4 == 0.0) {
        return 1;
      }
      if (*(int *)((int)fVar4 + 0x110) == 0) {
        return 1;
      }
      pfVar3 = (float *)((int)fVar4 + 0x30);
      pfVar9 = in_EAX + 0x18;
      if (pfVar3 == (float *)0x0) goto LAB_004106c4;
    }
    pfVar7 = in_EAX + 8;
    local_30 = *pfVar3 - in_EAX[0xc];
    local_2c = pfVar3[1] - in_EAX[0xd];
    local_28 = pfVar3[2] - in_EAX[0xe];
    local_18 = local_2c * in_EAX[9] + local_30 * *pfVar7 + local_28 * in_EAX[10];
    if ((_DAT_007f1604 <= local_18) && (local_18 <= _DAT_007f1608)) {
      if ((0.969 <= (local_18 * local_18) /
                    (local_30 * local_30 + local_2c * local_2c + local_28 * local_28)) &&
         (fVar4 = 50.0 - (in_EAX[10] * pfVar9[2] + *pfVar9 * *pfVar7 + in_EAX[9] * pfVar9[1]),
         1.0 <= fVar4)) {
        local_18 = local_18 / fVar4;
        local_20 = local_18 * *pfVar9;
        local_1c = pfVar9[1] * local_18;
        local_18 = local_18 * pfVar9[2];
        local_30 = local_20 + local_30;
        local_2c = local_2c + local_1c;
        local_28 = local_28 + local_18;
        if (in_EAX[0x47] == 0.0) {
          fVar4 = ABS(local_2c * in_EAX[1] + local_30 * *in_EAX + local_28 * in_EAX[2]);
          fVar5 = ABS(in_EAX[6] * local_28 + in_EAX[4] * local_30 + in_EAX[5] * local_2c);
          fVar6 = ABS(local_28 * in_EAX[10] + in_EAX[9] * local_2c + *pfVar7 * local_30);
          if (fVar5 <= fVar4) {
            if (fVar5 < fVar6) {
              pfVar7 = in_EAX + 4;
            }
          }
          else if (fVar4 < fVar6) {
            pfVar7 = in_EAX;
          }
          pfVar9 = in_EAX + 0x2c;
          FUN_005b3920(pfVar9,&local_30,pfVar7);
          FUN_005b3b30(pfVar9,pfVar9);
          in_EAX[0x2f] = 1.0;
        }
        if (in_EAX[0x33] != 0.0) {
          local_18 = in_EAX[0x33];
          local_20 = local_18 * in_EAX[0x2c];
          local_1c = in_EAX[0x2d] * local_18;
          local_18 = local_18 * in_EAX[0x2e];
          local_30 = local_30 + local_20;
          local_2c = local_2c + local_1c;
          local_28 = local_28 + local_18;
        }
        pfVar9 = param_2;
        for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *pfVar9 = *in_EAX;
          in_EAX = in_EAX + 1;
          pfVar9 = pfVar9 + 1;
        }
        FUN_005b3470(&local_20,&local_30,param_2);
        sVar1 = FUN_005be2d0(local_20,local_18);
        FUN_005b3620(&local_20,&local_20,-(int)sVar1);
        sVar2 = FUN_005be2d0(local_1c,local_18);
        FUN_005b5060(param_2,(int)sVar1);
        FUN_005b4dd0(param_2,-(int)sVar2);
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = param_3;
        param_1[3] = 0;
        FUN_0040e8e0(param_1);
        return 0;
      }
      return 2;
    }
  }
  return 1;
}

