/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c85e0; label: FUN_006c85e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c85e0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  for (piVar1 = (int *)*in_ECX; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 0xc))(param_1);
  }
  return;
}

