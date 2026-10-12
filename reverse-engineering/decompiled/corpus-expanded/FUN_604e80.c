/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x604e80; label: FUN_00604e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00604e80(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
    return in_ECX[1];
  }
  return in_ECX[1];
}

