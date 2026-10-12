/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58a900; label: FUN_0058a900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058a900(int param_1)

{
  int iVar1;
  
  if ((((param_1 == 0) && (param_1 = DAT_009553d4, DAT_009553d4 == 0)) ||
      (*(char *)(param_1 + 0x1d) == '\0')) || (iVar1 = *(int *)(param_1 + 4), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

