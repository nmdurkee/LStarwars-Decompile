/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bdf80; label: FUN_005bdf80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bdf80(int param_1,int param_2)

{
  float10 fVar1;
  
  if (param_1 == 0) {
    if (param_2 < 0) {
      return (float10)3.1415927;
    }
    return (float10)0.0;
  }
  if (param_2 == 0) {
    if (param_1 < 0) {
      return (float10)4.712389;
    }
    return (float10)1.5707964;
  }
  if (-1 < param_1) {
    if (param_2 < 0) {
      fVar1 = (float10)FUN_005bdf20();
      return (float10)(float)((float10)3.1415927410125732 - fVar1);
    }
    fVar1 = (float10)FUN_005bdf20();
    return fVar1;
  }
  if (param_2 < 0) {
    fVar1 = (float10)FUN_005bdf20();
    return (float10)(float)(fVar1 + (float10)3.1415927410125732);
  }
  fVar1 = (float10)FUN_005bdf20();
  return -fVar1;
}

