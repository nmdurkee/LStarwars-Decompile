/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x604dd0; label: FUN_00604dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00604dd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 3;
}

