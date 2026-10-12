/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4de0; label: FUN_006d4de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d4de0(int param_1,int param_2,int param_3,int param_4)

{
  int in_ECX;
  
  if (param_3 != 0) {
    return *(char *)(in_ECX + 0x6358 + (param_4 * 0x20 + param_2) * 4) != '\0';
  }
  return *(char *)(in_ECX + 0x4ea2 + (param_1 * 0x5f + param_2) * 4) != '\0';
}

