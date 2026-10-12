/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c30b0; label: FUN_005c30b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c30b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58 + *(int *)(in_ECX + 0x54) * 4) = param_1;
  *(int *)(in_ECX + 0x54) = *(int *)(in_ECX + 0x54) + 1;
  return;
}

