/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59a5c0; label: FUN_0059a5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0059a5c0(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((float10)param_1 != fVar1) && ((float10)param_2 != fVar1)) {
    return (float10)(float)((float10)param_1 / (float10)param_2);
  }
  return fVar1;
}

