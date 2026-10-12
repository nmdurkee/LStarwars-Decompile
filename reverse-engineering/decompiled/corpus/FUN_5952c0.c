/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5952c0; label: FUN_005952c0
 */

void FUN_005952c0(float *param_1,float *param_2,undefined4 param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_ECX;
  
  fVar2 = param_2[1];
  fVar3 = param_1[1];
  pfVar1 = (float *)(in_ECX + 0x770);
  fVar4 = param_2[2];
  fVar5 = param_1[2];
  *pfVar1 = *param_2 - *param_1;
  *(float *)(in_ECX + 0x774) = fVar2 - fVar3;
  *(float *)(in_ECX + 0x778) = fVar4 - fVar5;
  *(undefined4 *)(in_ECX + 0x77c) = 0;
  FUN_005b3b30(pfVar1,pfVar1);
  *(undefined4 *)(in_ECX + 0x77c) = 0x3f800000;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  *(float *)(in_ECX + 0x760) = *param_1;
  *(float *)(in_ECX + 0x764) = fVar2;
  *(float *)(in_ECX + 0x768) = fVar3;
  *(undefined4 *)(in_ECX + 0x76c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x76c) = 0x3f800000;
  FUN_005b7390(in_ECX + 0x780,param_1,param_2,param_3);
  return;
}

