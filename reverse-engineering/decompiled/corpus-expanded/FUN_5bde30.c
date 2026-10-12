/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bde30; label: FUN_005bde30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bde30(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  param_1 = param_1 & 0xffff;
  if (param_1 < 0xc001) {
    if (param_1 < 0x4001) {
      param_1 = param_1 + 0x4000;
    }
    else {
      param_1 = 0xc000 - param_1;
    }
  }
  else {
    param_1 = param_1 - 0xc000;
  }
  fVar1 = (float)(int)param_1 * 9.58738e-05 - 1.5707964;
  fVar4 = fVar1 * fVar1;
  fVar3 = fVar1 * fVar4 * fVar4;
  fVar2 = fVar3 * fVar4;
  return (float10)(fVar2 * fVar4 * 2.601887e-06 +
                  fVar2 * -0.00019807414 +
                  fVar3 * 0.0083330255 + fVar1 * fVar4 * -0.16666657 + fVar1);
}

