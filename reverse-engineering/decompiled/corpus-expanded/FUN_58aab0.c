/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58aab0; label: FUN_0058aab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058aab0(int param_1)

{
  if ((((param_1 != 0) || (param_1 = DAT_009553d4, DAT_009553d4 != 0)) &&
      (*(char *)(param_1 + 0x1d) != '\0')) &&
     ((*(int *)(param_1 + 4) != 0 && ((*(byte *)(param_1 + 0x1e) & 1) == 0)))) {
    return 1;
  }
  return 0;
}

