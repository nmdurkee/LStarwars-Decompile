/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c99b0; label: FUN_004c99b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

