/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40e7a0; label: FUN_0040e7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040e7a0(float param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *in_ECX = param_1 * *in_EAX;
  in_ECX[1] = in_EAX[1] * param_1;
  in_ECX[2] = param_1 * in_EAX[2];
  return;
}

