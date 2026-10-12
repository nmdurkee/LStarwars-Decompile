/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4ba0; label: FUN_006d4ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d4ba0(int param_1,int param_2,int param_3)

{
  int in_ECX;
  
  if (-1 < param_1) {
    if (param_2 != 0) {
      *(int *)(in_ECX + 0x6558 + param_3 * 4) = param_1;
      FUN_004ef660(param_3 * 0x80 + 0x6358 + in_ECX,param_1 * 0x17c + 0x4ea2 + in_ECX,0x80);
      return;
    }
    FUN_004ef660(param_1 * 0x17c + 0x4ea2 + in_ECX,param_3 * 0x80 + 0x6358 + in_ECX,0x80);
  }
  return;
}

