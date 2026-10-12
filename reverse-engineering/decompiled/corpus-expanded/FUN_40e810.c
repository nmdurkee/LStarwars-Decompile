/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40e810; label: FUN_0040e810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0040e810(void)

{
  float *in_EAX;
  
  return (float10)(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
}

