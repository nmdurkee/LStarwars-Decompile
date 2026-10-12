/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5ddc80; label: FUN_005ddc80
 */

void FUN_005ddc80(int param_1,float param_2)

{
  float fVar1;
  float10 fVar2;
  
  if (param_1 != 0) {
    fVar1 = *(float *)(param_1 + 0x2c) + param_2 * *(float *)(param_1 + 0x28) * 0.00390625;
    *(float *)(param_1 + 0x2c) = fVar1;
    if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
      fVar2 = (float10)FUN_005b7d30(fVar1,0x3f800000);
      *(float *)(param_1 + 0x2c) = (float)fVar2;
    }
    *(float *)(param_1 + 0x34) = param_2 * 5.0 + *(float *)(param_1 + 0x34);
    *(float *)(param_1 + 0x30) = param_2 + *(float *)(param_1 + 0x30);
  }
  return;
}

