/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7cc0; label: FUN_006c7cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c7cc0(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    return *(undefined4 *)(in_ECX + 8);
  }
  return *(undefined4 *)(param_1 + 4);
}

