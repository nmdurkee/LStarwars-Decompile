/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66f9a0; label: FUN_0066f9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066f9a0(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  iVar1 = FUN_006e6b90();
  iVar2 = FUN_006e6b90();
  param_2[1] = param_1[1] * (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] -
               (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * param_1[2];
  FUN_006e6b90();
  iVar1 = FUN_006e6b90();
  param_2[2] = (float)(extraout_ST1 -
                      (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * (float10)*param_1);
  FUN_006e6b90();
  iVar1 = FUN_006e6b90();
  *param_2 = (float)(extraout_ST0 +
                    (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * extraout_ST1_00);
  return;
}

