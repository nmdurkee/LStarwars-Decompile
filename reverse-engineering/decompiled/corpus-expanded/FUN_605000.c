/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x605000; label: FUN_00605000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00605000(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return in_ECX[1] - param_1[1] >> 3;
}

