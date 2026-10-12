/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c9eb0; label: FUN_004c9eb0
 */

float10 FUN_004c9eb0(float param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)param_1;
  if ((float10)0 < fVar1) {
    fVar2 = (float10)0.30000001192092896;
    if (fVar1 < (float10)param_2 + fVar2 + fVar2 + (float10)0.20000000298023224) {
      if (fVar1 < (float10)0.3) {
        return (float10)(float)(fVar1 / fVar2);
      }
      fVar3 = (float10)(float)((float10)param_2 + fVar2);
      if (fVar1 < fVar3) {
        return (float10)1;
      }
      if (fVar1 < (float10)(float)(fVar3 + fVar2)) {
        return (float10)(float)((float10)1 -
                               (fVar1 - fVar3) / ((float10)(float)(fVar3 + fVar2) - fVar3));
      }
    }
  }
  return (float10)0;
}

