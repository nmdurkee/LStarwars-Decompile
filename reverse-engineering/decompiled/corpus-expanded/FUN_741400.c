/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x741400; label: FUN_00741400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00741400(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 0x191) {
    return param_1 * 0x4d8 + 4 + in_ECX;
  }
  return 0;
}

