/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x653840; label: FUN_00653840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00653840(float param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  float fVar1;
  float10 fVar2;
  
  if (param_1 == 0.0) {
    if (param_2 != 0.0) {
      *param_5 = -param_3 / param_2;
      *param_4 = -param_3 / param_2;
      return 1;
    }
  }
  else {
    param_3 = param_1 * 4.0 * param_3;
    fVar1 = param_2 * param_2;
    if (param_3 <= fVar1) {
      if (fVar1 != param_3) {
        fVar2 = (float10)FUN_005c0240(fVar1 - param_3);
        *param_4 = (-param_2 - (float)fVar2) / (param_1 + param_1);
        *param_5 = ((float)fVar2 - param_2) / (param_1 + param_1);
        return 1;
      }
      fVar1 = -param_2 / (param_1 + param_1);
      *param_5 = fVar1;
      *param_4 = fVar1;
      return 1;
    }
  }
  return 0;
}

