/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b010; label: FUN_0074b010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0074b010(int param_1)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    *in_ECX = param_1;
    return param_1;
  }
  if (in_ECX[1] != 0) {
    return 0;
  }
  in_ECX[1] = param_1;
  return param_1;
}

