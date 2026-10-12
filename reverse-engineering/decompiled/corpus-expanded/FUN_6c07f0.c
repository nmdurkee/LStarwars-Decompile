/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c07f0; label: FUN_006c07f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c07f0(int *param_1,undefined4 param_2)

{
  int *in_ECX;
  
  if (*param_1 != 0) {
    (**(code **)(*in_ECX + 0x14))(*param_1,param_2);
    return;
  }
  (**(code **)(*in_ECX + 0x10))(param_1);
  return;
}

