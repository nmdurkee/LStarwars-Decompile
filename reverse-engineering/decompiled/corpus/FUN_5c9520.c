/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c9520; label: FUN_005c9520
 */

/* WARNING: Removing unreachable block (ram,0x005c9573) */

float10 FUN_005c9520(int *param_1,float *param_2,int param_3)

{
  uint *puVar1;
  short *psVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  pfVar6 = param_2;
  param_1 = (int *)*param_1;
  uVar12 = 0;
  puVar1 = (uint *)(*param_1 + (int)param_2[2] * 4);
  if (param_3 == 4) {
    FUN_005b7cc0(param_2[1]);
    cVar11 = FUN_006e6b90();
    return (float10)(*puVar1 >> (cVar11 - 1U & 0x1f) & 1);
  }
  switch(param_2[4]) {
  case 0.0:
    uVar12 = (uint)(byte)(&DAT_00971760)[(uint)param_2[3] & (uint)(byte)*puVar1];
    goto switchD_005c9589_default;
  case 1.4013e-45:
    uVar12 = (uint)(byte)(&DAT_00971760)[(uint)*(byte *)((int)puVar1 + 1) & (uint)param_2[3]];
    goto LAB_005c95e9;
  case 2.8026e-45:
    uVar12 = (uint)(byte)(&DAT_00971760)[(uint)*(byte *)((int)puVar1 + 2) & (uint)param_2[3]];
    break;
  case 4.2039e-45:
    uVar12 = (uint)(byte)(&DAT_00971760)[(uint)*(byte *)((int)puVar1 + 3) & (uint)param_2[3]] +
             (uint)(byte)(&DAT_00971760)[*(byte *)((int)puVar1 + 2)];
    break;
  default:
    goto switchD_005c9589_default;
  }
  uVar12 = uVar12 + (byte)(&DAT_00971760)[*(byte *)((int)puVar1 + 1)];
LAB_005c95e9:
  uVar12 = uVar12 + (byte)(&DAT_00971760)[(byte)*puVar1];
switchD_005c9589_default:
  uVar13 = (uint)*(ushort *)(param_1[1] + (int)param_2[2] * 2);
  switch(param_3) {
  default:
    return (float10)0;
  case 1:
    iVar14 = (uVar13 + uVar12) * 0x10;
    pfVar6 = (float *)(iVar14 + -0x10 + param_1[2]);
    fVar8 = (*param_2 - *(float *)(iVar14 + -0x10 + param_1[2])) * pfVar6[1];
    fVar9 = (pfVar6[4] - *pfVar6) * pfVar6[3];
    fVar4 = (pfVar6[4] - *pfVar6) * pfVar6[7];
    return (float10)(((((fVar8 * (fVar4 + fVar9 + (pfVar6[2] - pfVar6[6]) * 2.0) -
                        (pfVar6[2] - pfVar6[6]) * 3.0) - fVar9 * 2.0) - fVar4) * fVar8 + fVar9) *
                     fVar8 + pfVar6[2]);
  case 2:
    psVar2 = (short *)(param_1[2] + 4 + (uVar13 + uVar12) * 4);
    fVar9 = (float)*(byte *)((int)psVar2 + 7) - (float)*(byte *)((int)psVar2 + 3);
    fVar8 = 0.0;
    if (fVar9 != 0.0) {
      fVar8 = 1.0 / fVar9;
    }
    break;
  case 3:
    return (float10)*(float *)(param_1[2] + -8 + (uVar13 + uVar12) * 8);
  case 5:
    pfVar6 = (float *)param_1[2];
    psVar2 = (short *)((int)pfVar6 + (uVar13 + 2 + uVar12) * 6);
    fVar8 = (float)(ushort)psVar2[5] - (float)(ushort)psVar2[2];
    fVar4 = fVar8 * *pfVar6 * (float)(int)(char)psVar2[1];
    fVar9 = (float)(int)(char)psVar2[4] * *pfVar6 * fVar8;
    fVar5 = pfVar6[2] + pfVar6[1] * (float)(int)*psVar2;
    fVar8 = ((*param_2 - 1.0) - (float)(ushort)psVar2[2]) * (1.0 / fVar8);
    fVar10 = fVar5 - ((float)(int)psVar2[3] * pfVar6[1] + pfVar6[2]);
    return (float10)(((((fVar8 * (fVar9 + fVar4 + fVar10 * 2.0) - fVar10 * 3.0) - fVar4 * 2.0) -
                      fVar9) * fVar8 + fVar4) * fVar8 + fVar5);
  case 6:
    pfVar7 = (float *)param_1[2];
    pfVar3 = pfVar7 + uVar13 + uVar12 + 3;
    fVar8 = pfVar7[3] * (float)*(byte *)((int)pfVar3 + 3);
    param_2 = (float *)((float)*(byte *)((int)pfVar7 + (uVar13 + uVar12) * 4 + 0x13) * pfVar7[3]);
    if (fVar8 == (float)param_2) {
      param_2 = (float *)(fVar8 + 1.0);
    }
    fVar5 = (float)param_2 - fVar8;
    fVar4 = fVar5 * *pfVar7 * (float)(int)*(char *)((int)pfVar3 + 2);
    fVar9 = (float)(int)*(char *)((int)pfVar3 + 6) * *pfVar7 * fVar5;
    fVar10 = pfVar7[2] + pfVar7[1] * (float)(int)*(short *)pfVar3;
    fVar8 = ((*pfVar6 - 1.0) - fVar8) * (1.0 / fVar5);
    fVar5 = fVar10 - ((float)(int)*(short *)(pfVar3 + 1) * pfVar7[1] + pfVar7[2]);
    return (float10)(((((fVar8 * (fVar9 + fVar4 + fVar5 * 2.0) - fVar5 * 3.0) - fVar4 * 2.0) - fVar9
                      ) * fVar8 + fVar4) * fVar8 + fVar10);
  }
  fVar4 = *(float *)param_1[2];
  fVar5 = ((float *)param_1[2])[1];
  fVar10 = fVar9 * fVar4 * (float)(int)(char)psVar2[1];
  fVar9 = (float)(int)(char)psVar2[3] * fVar4 * fVar9;
  fVar4 = fVar5 * (float)(int)*psVar2;
  fVar8 = ((*param_2 - 1.0) - (float)*(byte *)((int)psVar2 + 3)) * fVar8;
  fVar5 = fVar4 - (float)(int)psVar2[2] * fVar5;
  return (float10)(((((fVar8 * (fVar9 + fVar10 + fVar5 * 2.0) - fVar5 * 3.0) - fVar10 * 2.0) - fVar9
                    ) * fVar8 + fVar10) * fVar8 + fVar4);
}

