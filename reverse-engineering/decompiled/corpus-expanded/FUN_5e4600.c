/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4600; label: FUN_005e4600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

