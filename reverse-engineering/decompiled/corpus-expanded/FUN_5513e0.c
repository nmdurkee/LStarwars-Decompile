/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x5513e0; label: FUN_005513e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005513e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    float *param_5,float *param_6)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float local_54;
  float local_4c;
  undefined4 local_3c [2];
  undefined4 local_34;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  local_54 = 1e+09;
  FUN_005b3800(local_3c,param_2,param_1);
  iVar1 = FUN_005be2d0(local_3c[0],local_34);
  FUN_005b3800(local_30,param_3,param_1);
  FUN_005b3620(local_30,local_30,-iVar1);
  FUN_005b3800(local_24,param_4,param_1);
  FUN_005b3620(local_24,local_24,-iVar1);
  FUN_005b3800(local_3c,param_4,param_3);
  iVar1 = FUN_005be2d0(local_3c[0],local_34);
  FUN_005b3800(local_18,param_1,param_3);
  FUN_005b3620(local_18,local_18,-iVar1);
  FUN_005b3800(local_c,param_2,param_3);
  FUN_005b3620(local_c,local_c,-iVar1);
  fVar2 = (float10)FUN_005b7c20(local_30[0]);
  fVar3 = (float10)FUN_005b7c20(local_24[0]);
  if (fVar3 != (float10)(double)fVar2) {
    fVar2 = (float10)FUN_005b7c20(local_18[0]);
    fVar3 = (float10)FUN_005b7c20(local_c[0]);
    if (fVar3 != (float10)(double)fVar2) {
      *param_5 = ABS(local_18[0]) / (ABS(local_c[0]) + ABS(local_18[0]));
      *param_6 = ABS(local_30[0]) / (ABS(local_24[0]) + ABS(local_30[0]));
      return (float10)0;
    }
  }
  fVar2 = (float10)FUN_005bed80(param_2,param_1,0);
  fVar3 = (float10)FUN_005bed80(param_4,param_3,0);
  fVar4 = (float10)FUN_00551370(param_1,param_2,(float)fVar2);
  if ((float)fVar4 < 1e+09) {
    *param_5 = local_4c;
    *param_6 = 0.0;
    local_54 = (float)fVar4;
  }
  fVar2 = (float10)FUN_00551370(param_1,param_2,(float)fVar2);
  if ((float)fVar2 < local_54) {
    *param_5 = local_4c;
    *param_6 = 1.0;
    local_54 = (float)fVar2;
  }
  fVar2 = (float10)FUN_00551370(param_3,param_4,(float)fVar3);
  if ((float)fVar2 < local_54) {
    *param_6 = local_4c;
    *param_5 = 0.0;
    local_54 = (float)fVar2;
  }
  fVar2 = (float10)FUN_00551370(param_3,param_4,(float)fVar3);
  if (local_54 <= (float)fVar2) {
    return (float10)local_54;
  }
  *param_6 = local_4c;
  *param_5 = 1.0;
  return (float10)(float)fVar2;
}

