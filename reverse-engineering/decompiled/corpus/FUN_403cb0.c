/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x403cb0; label: FUN_00403cb0
 */

float10 FUN_00403cb0(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((float10)param_1 != fVar1) && ((float10)param_2 != fVar1)) {
    return (float10)(float)((float10)param_1 / (float10)param_2);
  }
  return fVar1;
}

