/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x605170; label: FUN_00605170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00605170(int param_1)

{
  int in_ECX;
  
  return (uint)((param_1 - in_ECX) / 0x30) < 0x10;
}

