/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7630; label: FUN_006c7630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c7630(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x50) != 0) {
    *(float *)(param_1 + 4) = *(float *)(param_1 + 4) - 10.0;
  }
  return;
}

