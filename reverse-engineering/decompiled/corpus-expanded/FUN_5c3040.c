/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3040; label: FUN_005c3040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c3040(int param_1)

{
  int in_ECX;
  
  if (param_1 == 4) {
    return *(undefined4 *)(in_ECX + 0x800);
  }
  if (param_1 != 5) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x804);
}

