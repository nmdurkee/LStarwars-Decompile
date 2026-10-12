/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0860; label: FUN_006c0860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c0860(int param_1,int param_2)

{
  int in_ECX;
  
  FUN_004f6de0(*(undefined4 *)(in_ECX + 0x198),param_1 * param_2,param_1 * param_2 >> 0x1f,1);
  return;
}

