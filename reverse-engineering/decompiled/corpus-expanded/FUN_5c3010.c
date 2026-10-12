/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3010; label: FUN_005c3010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3010(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (param_1 == 4) {
    *(undefined4 *)(in_ECX + 0x800) = param_2;
  }
  else if (param_1 == 5) {
    *(undefined4 *)(in_ECX + 0x804) = param_2;
    return;
  }
  return;
}

