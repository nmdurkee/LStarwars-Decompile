/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c99b0; label: FUN_004c99b0
 */

float10 FUN_004c99b0(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005bed80(param_1,param_2,0);
  fVar1 = (float10)(float)(fVar1 * (float10)0.125);
  if ((float10)1 < fVar1) {
    return (float10)(float)(float10)1;
  }
  if (fVar1 < (float10)0.10000000149011612) {
    fVar1 = (float10)0.1;
  }
  return fVar1;
}

