/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0590; label: FUN_006c0590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c0590(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f97c;
  if (in_ECX[5] != 0) {
    FUN_006334d0(in_ECX[5],in_ECX[3] << 4);
  }
  return;
}

