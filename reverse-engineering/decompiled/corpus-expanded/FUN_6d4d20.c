/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4d20; label: FUN_006d4d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d4d20(int param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 0x67e0);
  *(char *)(in_ECX + 0x67e0) = (char)param_1;
  if (param_1 != cVar1) {
    DAT_029755b0 = 6;
  }
  return;
}

