/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642370; label: FUN_00642370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00642370(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((float10)param_1 != fVar1) && ((float10)param_2 != fVar1)) {
    return (float10)(float)((float10)param_1 / (float10)param_2);
  }
  return fVar1;
}

