/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc760; label: FUN_005bc760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bc760(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 float *param_5,float *param_6)

{
  int iVar1;
  float10 fVar2;
  
  *param_6 = 0.0;
  iVar1 = 0;
  param_6[1] = 0.0;
  param_6[2] = 0.0;
  if (-1 < param_2) {
    do {
      fVar2 = (float10)FUN_005bc5c0(iVar1,param_3,param_1,param_4);
      iVar1 = iVar1 + 1;
      *param_6 = *param_6 + (float)fVar2 * *param_5;
      param_6[1] = (float)fVar2 * param_5[1] + param_6[1];
      param_5 = param_5 + 3;
    } while (iVar1 <= param_2);
  }
  return;
}

