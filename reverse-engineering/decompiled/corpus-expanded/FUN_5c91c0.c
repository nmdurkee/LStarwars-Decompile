/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c91c0; label: FUN_005c91c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c91c0(byte *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  
  uVar5 = 0;
  switch(param_2[4]) {
  case 0.0:
    uVar5 = (uint)(byte)(&DAT_00971760)[(uint)param_2[3] & (uint)*param_1];
    goto switchD_005c91d5_default;
  case 1.4013e-45:
    uVar5 = (uint)(byte)(&DAT_00971760)[(uint)param_1[1] & (uint)param_2[3]];
    goto LAB_005c9235;
  case 2.8026e-45:
    uVar5 = (uint)(byte)(&DAT_00971760)[(uint)param_1[2] & (uint)param_2[3]];
    break;
  case 4.2039e-45:
    uVar5 = (uint)(byte)(&DAT_00971760)[(uint)param_1[3] & (uint)param_2[3]] +
            (uint)(byte)(&DAT_00971760)[param_1[2]];
    break;
  default:
    goto switchD_005c91d5_default;
  }
  uVar5 = uVar5 + (byte)(&DAT_00971760)[param_1[1]];
LAB_005c9235:
  uVar5 = uVar5 + (byte)(&DAT_00971760)[*param_1];
switchD_005c91d5_default:
  pfVar1 = (float *)(uVar5 * 0x10 + -0x10 + *(int *)(param_1 + 4));
  if ((*(uint *)(param_1 + 0xc) & 1) == 0) {
    fVar2 = (*param_2 - *pfVar1) * pfVar1[1];
    fVar3 = (pfVar1[4] - *pfVar1) * pfVar1[2];
    fVar4 = (pfVar1[4] - *pfVar1) * pfVar1[6];
    return (float10)(((((fVar2 * (fVar4 + fVar3 + (pfVar1[3] - pfVar1[7]) * 2.0) -
                        (pfVar1[3] - pfVar1[7]) * 3.0) - fVar3 * 2.0) - fVar4) * fVar2 + fVar3) *
                     fVar2 + pfVar1[3]);
  }
  if ((((*(uint *)(param_1 + 0xc) & 2) != 0) && ((int)(uVar5 - 1) < *(int *)(param_1 + 8))) &&
     (pfVar1[4] - *param_2 < *param_2 - *pfVar1)) {
    return (float10)pfVar1[7];
  }
  return (float10)pfVar1[3];
}

