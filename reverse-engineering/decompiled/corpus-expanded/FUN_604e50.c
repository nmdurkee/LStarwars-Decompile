/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x604e50; label: FUN_00604e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00604e50(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] == param_1[1]);
}

