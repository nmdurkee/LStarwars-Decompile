/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x604ef0; label: FUN_00604ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00604ef0(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    return *(int *)(in_ECX + 4);
  }
  return in_ECX + 4;
}

