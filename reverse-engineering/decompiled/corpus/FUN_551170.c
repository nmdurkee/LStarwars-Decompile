/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x551170; label: FUN_00551170
 */

undefined4
FUN_00551170(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            float *param_5,float *param_6)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 local_3c [2];
  undefined4 local_34;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_005b3800(local_3c,param_2,param_1);
  iVar1 = FUN_005be2d0(local_3c[0],local_34);
  FUN_005b3800(local_18,param_3,param_1);
  FUN_005b3620(local_18,local_18,-iVar1);
  FUN_005b3800(local_c,param_4,param_1);
  FUN_005b3620(local_c,local_c,-iVar1);
  fVar2 = (float10)FUN_005b7c20(local_18[0]);
  fVar3 = (float10)FUN_005b7c20(local_c[0]);
  if (fVar3 != (float10)(double)fVar2) {
    FUN_005b3800(local_3c,param_4,param_3);
    iVar1 = FUN_005be2d0(local_3c[0],local_34);
    FUN_005b3800(local_30,param_1,param_3);
    FUN_005b3620(local_30,local_30,-iVar1);
    FUN_005b3800(local_24,param_2,param_3);
    FUN_005b3620(local_24,local_24,-iVar1);
    fVar2 = (float10)FUN_005b7c20(local_30[0]);
    fVar3 = (float10)FUN_005b7c20(local_24[0]);
    if (fVar3 != (float10)(double)fVar2) {
      if (param_5 != (float *)0x0) {
        *param_5 = ABS(local_30[0]) / (ABS(local_24[0]) + ABS(local_30[0]));
      }
      if (param_6 != (float *)0x0) {
        *param_6 = ABS(local_18[0]) / (ABS(local_c[0]) + ABS(local_18[0]));
      }
      return 1;
    }
  }
  return 0;
}

