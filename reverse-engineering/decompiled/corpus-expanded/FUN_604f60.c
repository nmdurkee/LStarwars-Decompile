/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x604f60; label: FUN_00604f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00604f60(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + 8;
  return;
}

