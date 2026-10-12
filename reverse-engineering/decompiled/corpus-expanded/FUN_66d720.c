/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66d720; label: FUN_0066d720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066d720(int param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = param_1;
  pfVar1 = (float *)(param_1 + 0x58);
  param_1 = 0;
  if (*pfVar1 <= 65535.0) {
    do {
      fVar2 = (float)param_1;
      FUN_005dc050(*param_2 + *(float *)(iVar3 + 0x18) +
                   (*(float *)(iVar3 + 0x24) - *(float *)(iVar3 + 0x18)) * fVar2,
                   *(float *)(iVar3 + 0x1c) + param_2[1] +
                   (*(float *)(iVar3 + 0x28) - *(float *)(iVar3 + 0x1c)) * fVar2,
                   *(float *)(iVar3 + 0x20) + param_2[2] +
                   (*(float *)(iVar3 + 0x2c) - *(float *)(iVar3 + 0x20)) * fVar2,
                   *param_2 + *(float *)(iVar3 + 0x30) +
                   (*(float *)(iVar3 + 0x3c) - *(float *)(iVar3 + 0x30)) * fVar2,
                   *(float *)(iVar3 + 0x34) + param_2[1] +
                   (*(float *)(iVar3 + 0x40) - *(float *)(iVar3 + 0x34)) * fVar2,
                   *(float *)(iVar3 + 0x38) + param_2[2] +
                   fVar2 * (*(float *)(iVar3 + 0x44) - *(float *)(iVar3 + 0x38)),0xffff7f80);
      param_1 = param_1 + 1;
    } while (param_1 < 2);
    param_1 = 0;
    do {
      fVar2 = (float)param_1;
      FUN_005dc050(*param_2 + *(float *)(iVar3 + 0x18) +
                   (*(float *)(iVar3 + 0x30) - *(float *)(iVar3 + 0x18)) * fVar2,
                   *(float *)(iVar3 + 0x1c) + param_2[1] +
                   (*(float *)(iVar3 + 0x34) - *(float *)(iVar3 + 0x1c)) * fVar2,
                   *(float *)(iVar3 + 0x20) + param_2[2] +
                   (*(float *)(iVar3 + 0x38) - *(float *)(iVar3 + 0x20)) * fVar2,
                   *param_2 + *(float *)(iVar3 + 0x24) +
                   (*(float *)(iVar3 + 0x3c) - *(float *)(iVar3 + 0x24)) * fVar2,
                   *(float *)(iVar3 + 0x28) + param_2[1] +
                   (*(float *)(iVar3 + 0x40) - *(float *)(iVar3 + 0x28)) * fVar2,
                   *(float *)(iVar3 + 0x2c) + param_2[2] +
                   fVar2 * (*(float *)(iVar3 + 0x44) - *(float *)(iVar3 + 0x2c)),0xffff7f80);
      param_1 = param_1 + 1;
    } while (param_1 < 2);
    return;
  }
  do {
    fVar2 = (float)param_1;
    FUN_005dc050(*param_2 + *(float *)(iVar3 + 0x18),*(float *)(iVar3 + 0x1c) + param_2[1],
                 *(float *)(iVar3 + 0x20) + param_2[2],
                 *param_2 + *(float *)(iVar3 + 0x24) +
                 (*(float *)(iVar3 + 0x30) - *(float *)(iVar3 + 0x24)) * fVar2,
                 *(float *)(iVar3 + 0x28) + param_2[1] +
                 (*(float *)(iVar3 + 0x34) - *(float *)(iVar3 + 0x28)) * fVar2,
                 *(float *)(iVar3 + 0x2c) + param_2[2] +
                 fVar2 * (*(float *)(iVar3 + 0x38) - *(float *)(iVar3 + 0x2c)),0x3f7f80);
    param_1 = param_1 + 1;
  } while (param_1 < 2);
  param_1 = 0;
  do {
    fVar2 = (float)param_1;
    FUN_005dc050(*param_2 + *(float *)(iVar3 + 0x24),*(float *)(iVar3 + 0x28) + param_2[1],
                 *(float *)(iVar3 + 0x2c) + param_2[2],
                 *param_2 + *(float *)(iVar3 + 0x18) +
                 (*(float *)(iVar3 + 0x30) - *(float *)(iVar3 + 0x18)) * fVar2,
                 *(float *)(iVar3 + 0x1c) + param_2[1] +
                 (*(float *)(iVar3 + 0x34) - *(float *)(iVar3 + 0x1c)) * fVar2,
                 *(float *)(iVar3 + 0x20) + param_2[2] +
                 fVar2 * (*(float *)(iVar3 + 0x38) - *(float *)(iVar3 + 0x20)),0x3f7f80);
    param_1 = param_1 + 1;
  } while (param_1 < 2);
  return;
}

