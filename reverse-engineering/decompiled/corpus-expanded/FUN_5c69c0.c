/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c69c0; label: FUN_005c69c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c69c0(void)

{
  float *in_ECX;
  
  return (float10)(in_ECX[2] * in_ECX[2] + *in_ECX * *in_ECX + in_ECX[1] * in_ECX[1]);
}

