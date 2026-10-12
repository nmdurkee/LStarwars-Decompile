/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8610; label: FUN_005d8610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005d8610(void)

{
  float fVar1;
  int in_EAX;
  
  fVar1 = (float)in_EAX;
  if (in_EAX < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  return (float10)((fVar1 * 15734.0) / 1e+06);
}

