/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6cc0; label: FUN_005d6cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005d6cc0(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005be490(18.0 / param_1,0x3f800000);
  return (float10)(float)(fVar1 * (float10)9.58738019107841e-05 +
                         fVar1 * (float10)9.58738019107841e-05);
}

