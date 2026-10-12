/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a7f90; label: FUN_006a7f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006a7f90(uint param_1)

{
  double dVar1;
  
  dVar1 = (double)(param_1 & 0x1fffff);
  if ((int)param_1 < 0) {
    dVar1 = -dVar1;
  }
  dVar1 = _ldexp(dVar1,((int)param_1 >> 0x15 & 0x3ffU) - 0x314);
  return (float10)(float)dVar1;
}

