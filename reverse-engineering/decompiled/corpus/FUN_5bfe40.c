/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bfe40; label: FUN_005bfe40
 */

void FUN_005bfe40(float param_1,float param_2)

{
  float10 fVar1;
  
  if (param_1 == 0.0) {
    return;
  }
  fVar1 = (float10)FUN_005be790(param_1);
  FUN_005be970((float)(fVar1 * (float10)param_2));
  return;
}

