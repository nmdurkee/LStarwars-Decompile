/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x5501d0; label: FUN_005501d0
 */

void FUN_005501d0(float *param_1,float *param_2,undefined2 *param_3,undefined2 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  float10 fVar5;
  float fVar6;
  
  fVar1 = *param_2 - *param_1;
  fVar6 = param_2[1] - param_1[1];
  fVar2 = param_2[2] - param_1[2];
  fVar3 = fVar1 * fVar1 + fVar2 * fVar2;
  fVar5 = (float10)FUN_005c0240(fVar3,fVar3,fVar6);
  uVar4 = FUN_005be2d0(fVar6,(float)fVar5);
  *param_3 = uVar4;
  uVar4 = FUN_005be2d0(fVar1,fVar2);
  *param_4 = uVar4;
  return;
}

