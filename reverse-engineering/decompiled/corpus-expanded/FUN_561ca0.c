/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561ca0; label: FUN_00561ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00561ca0(int param_1,float param_2,int param_3)

{
  float fVar1;
  float10 fVar2;
  
  param_2 = param_2 - (*(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x78c));
  if (param_2 <= 0.0) {
    fVar1 = 0.0;
    if (param_3 == 0) {
      return;
    }
  }
  else {
    fVar2 = (float10)FUN_005c0240(*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x24) *
                                  -2.0 * param_2);
    fVar1 = (float)fVar2;
    if ((param_3 == 0) && (fVar1 <= *(float *)(param_1 + 0x6c))) {
      return;
    }
  }
  *(float *)(param_1 + 0x6c) = fVar1;
  return;
}

