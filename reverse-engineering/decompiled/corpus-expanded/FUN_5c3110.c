/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3110; label: FUN_005c3110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3110(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_3;
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  *(undefined4 *)(in_ECX + 0x1c) = param_2;
  return;
}

