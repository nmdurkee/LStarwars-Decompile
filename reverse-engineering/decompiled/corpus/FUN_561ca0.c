/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561ca0; label: FUN_00561ca0
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

