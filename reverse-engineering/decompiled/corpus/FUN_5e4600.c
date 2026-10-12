/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e4600; label: FUN_005e4600
 */

void FUN_005e4600(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_005be2d0(*param_1,param_1[2]);
  *param_3 = (float)iVar1;
  fVar2 = (float10)FUN_005c0240(*param_1 * *param_1 + param_1[2] * param_1[2]);
  iVar1 = FUN_005be2d0(-param_1[1],(float)fVar2);
  *param_2 = (float)iVar1;
  return;
}

