/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c1120; label: FUN_006c1120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1120(void)

{
  int in_ECX;
  
  if (in_ECX != 0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  return;
}

