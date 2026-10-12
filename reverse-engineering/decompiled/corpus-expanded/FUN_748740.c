/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748740; label: FUN_00748740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748740(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) < param_1) {
    FUN_007484e0(param_1);
  }
  *(int *)(in_ECX + 4) = param_1;
  return;
}

