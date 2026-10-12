/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8590; label: FUN_006c8590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8590(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  for (piVar1 = (int *)*in_ECX; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 4))(param_1,param_2,param_3);
  }
  return;
}

