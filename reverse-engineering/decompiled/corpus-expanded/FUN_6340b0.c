/* Ghidra pseudocode, not original source.
 * ev_00f52e189c4008d6734275378e3b7e7cc775b5c4744fc695c4d739e43a001eb2
 * Entry: 0x6340b0; label: FUN_006340b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006340b0(void)

{
  float *in_EAX;
  
  FUN_005c0240(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
  return;
}

