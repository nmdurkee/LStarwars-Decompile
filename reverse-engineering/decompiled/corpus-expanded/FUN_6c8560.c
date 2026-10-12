/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8560; label: FUN_006c8560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8560(int param_1)

{
  int *in_ECX;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(int *)(param_1 + 8) = in_ECX[1];
  if (in_ECX[1] != 0) {
    *(int *)(in_ECX[1] + 4) = param_1;
  }
  in_ECX[2] = in_ECX[2] + 1;
  in_ECX[1] = param_1;
  if (*in_ECX == 0) {
    *in_ECX = param_1;
  }
  return;
}

